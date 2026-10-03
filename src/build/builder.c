#include "builder.h"
#include "../server/server.h"
#include "../utils/file_utils.h"
#include "../utils/string_utils.h"
#include "../data/data_manager.h"
#include "../data/yaml_parser.h"
#include "../data/json_parser.h"
#include "../frontmatter/frontmatter.h"
#include "../markdown/markdown.h"
#include "../template/template_engine.h"
#include "../sitemap/sitemap.h"
#include "../collection/collection.h"
#include "../pagination/pagination.h"
#include "../tags/tags.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#ifndef _WIN32
#include <unistd.h>
#endif
#ifdef _WIN32
#include <windows.h>
#endif

#include "version.h"

static void normalize_coll_name(const char *in, char *out, size_t out_size) {
    size_t j=0;
    for(size_t i=0; i<strlen(in) && j < out_size-1; i++) {
        if(in[i]=='.') out[j++]='/';
        else out[j++]=in[i];
    }
    out[j]='\0';
}
static char *clean_trim(char *str) {
    if (!str) return NULL;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}
static int file_exists(const char *path){
    FILE *f=fopen(path,"r");
    if(f){ fclose(f); return 1; }
    return 0;
}
static void get_coll_list_template(const char *coll_name, char *out, size_t out_size){
    snprintf(out, out_size, "templates/layouts/%s.cax", coll_name);
    if(file_exists(out)) return;
    snprintf(out, out_size, "templates/layouts/%s-list.cax", coll_name);
    if(file_exists(out)) return;
    snprintf(out, out_size, "default.cax");
}
static time_t get_mtime(const char *path){
    struct stat st;
    if(stat(path,&st)==0) return st.st_mtime;
    return 0;
}

static time_t scan_dir(const char *dir){
    time_t max=0;
    DIR *d=opendir(dir);
    if(!d) return get_mtime(dir);
    struct dirent *e;
    while((e=readdir(d))!=NULL){
        if(e->d_name[0]=='.') continue;
        char p[1024]; snprintf(p,sizeof(p),"%s/%s",dir,e->d_name);
        time_t t;
        if(cax_is_directory(p)) t=scan_dir(p);
        else t=get_mtime(p);
        if(t>max) max=t;
    }
    closedir(d);
    return max;
}

// ==============================
// PHASE 10: BUILD CACHE - 89ms
// ==============================
static int check_cache_valid(void){
    // force rebuild if .cax_force exists or site/ missing
    FILE *ff = fopen(".cax_force","r");
    if(ff){ fclose(ff); remove(".cax_force"); remove(".cax_cache"); return 0; }
    FILE *f = fopen(".cax_cache","r");
    if(!f) return 0;
    long long c,t,d,p;
    char ver[64]={0};
    if(fscanf(f,"%lld %lld %lld %lld %63s",&c,&t,&d,&p,ver)!=5){ fclose(f); remove(".cax_cache"); return 0; }
    fclose(f);
    // version changed -> rebuild
    if(strcmp(ver, CAX_VERSION)!=0){ remove(".cax_cache"); return 0; }
    long long nc=(long long)scan_dir("content");
    long long nt=(long long)scan_dir("templates");
    long long nd=(long long)scan_dir("_data");
    long long np=(long long)scan_dir("public");
    if(c!=nc || t!=nt || d!=nd || p!=np) return 0;
    // also check site/index.html exists - if not, rebuild
    FILE *sf = fopen("site/index.html","r");
    if(!sf) return 0;
    fclose(sf);
    return 1;
}
static void save_cache(void){
    FILE *f = fopen(".cax_cache","w");
    if(!f) return;
    long long c=(long long)scan_dir("content");
    long long t=(long long)scan_dir("templates");
    long long d=(long long)scan_dir("_data");
    long long p=(long long)scan_dir("public");
    fprintf(f,"%lld %lld %lld %lld %s\n",c,t,d,p,CAX_VERSION);
    fclose(f);
}

static void inject_livereload_script(){
    cax_write_file("site/__cax_live.js","(function(){let h=null;setInterval(async()=>{try{let t=await fetch(location.href,{cache:'no-store'}).then(r=>r.text());if(h===null)h=t.length;else if(h!=t.length)location.reload();}catch(e){}},1000);})();");
#ifdef _WIN32
    (void)system("powershell -Command \"$files=Get-ChildItem site -Filter *.html -Recurse -ErrorAction SilentlyContinue; foreach($f in $files){ $c=Get-Content $f.FullName -Raw -ErrorAction SilentlyContinue; if($c -and $c -notmatch '__cax_live'){ $c=$c -replace '</body>','<script src=\\\"/__cax_live.js\\\"></script></body>'; Set-Content $f.FullName $c -NoNewline } }\" >nul 2>&1");
#else
   { int _cax_sys = system("find site -name '*.html' -exec sed -i 's|</body>|<script src=/__cax_live.js></script></body>|g' {} \\; 2>/dev/null"); if(_cax_sys!=0) {} }
#endif
}
static void remove_livereload_script(){
    remove("site/__cax_live.js");
}
static void minify_and_copy_assets(void) {
    cax_copy_directory("public", "site");
    char css_path[4096];
    snprintf(css_path, sizeof(css_path), "site/css/style.css");
    char *css_content = cax_read_file(css_path);
    if (css_content) {
        size_t len = strlen(css_content);
        char *minified = malloc(len + 1);
        if (minified) {
            size_t j = 0; int in_space = 0; int in_quote = 0; char quote_char = '\0';
            for (size_t i = 0; i < len; i++) {
                char c = css_content[i];
                if ((c == '\'' || c == '"') && (i == 0 || css_content[i-1]!= '\\')) {
                    if (!in_quote) { in_quote = 1; quote_char = c; }
                    else if (quote_char == c) { in_quote = 0; }
                }
                if (!in_quote) {
                    if (c == '\n' || c == '\r' || c == '\t') c = ' ';
                    if (c == ' ') { if (!in_space) { minified[j++] = c; in_space = 1; } continue; }
                }
                minified[j++] = c; in_space = 0;
            }
            minified[j] = '\0';
            cax_write_file(css_path, minified);
            free(minified);
        }
        free(css_content);
    }
}
void cax_builder_init_project(void) {
    cax_create_directory("content/posts");
    cax_create_directory("content/services");
    cax_create_directory("_data");
    cax_create_directory("templates/layouts");
    cax_create_directory("templates/partials");
    cax_create_directory("public/css");
    cax_create_directory("site");
    cax_write_file("_data/metadata.json", "{\n \"site\": {\n \"title\": \"CAX Enterprise SSG\",\n \"description\": \"High performance Static Site Generator in C - Horologe Atelier Brass Chronometer\",\n \"url\": \"http://localhost:8080\",\n \"author\": \"Axcora\",\n \"image\": \"/og-image.jpg\",\n \"favicon\": \"/favicon.ico\",\n \"icon\": \"/favicon.ico\",\n \"seo\": true\n }\n}\n");
    cax_write_file("_data/nav.json","{\n \"nav1_name\": \"Home\",\n \"nav1_url\": \"/\",\n \"nav2_name\": \"Posts\",\n \"nav2_url\": \"/posts/\",\n \"nav3_name\": \"About\",\n \"nav3_url\": \"/about/\"\n}\n");
    cax_write_file("templates/partials/seo.cax","<!-- MANUAL SEO - BEBAS EDIT kalau seo:false -->\n<title>{{ title }}</title>\n<meta name=\"description\" content=\"{{ description }}\">\n<meta name=\"author\" content=\"{{ author }}\">\n<meta name=\"generator\" content=\"{{ generator }}\">\n<link rel=\"icon\" href=\"{{ favicon or icon }}\">\n<link rel=\"canonical\" href=\"{{ site_url }}{{ url }}\">\n<meta property=\"og:title\" content=\"{{ title }}\">\n<meta property=\"og:description\" content=\"{{ description }}\">\n<meta property=\"og:url\" content=\"{{ site_url }}{{ url }}\">\n<meta property=\"og:image\" content=\"{{ site_url }}{{ image }}\">\n");
    cax_write_file("templates/partials/header.cax","<header class=\"py-4 border-bottom bg-white shadow-sm mb-4\">\n <div class=\"container d-flex justify-content-between align-items-center\">\n <a class=\"navbar-brand fw-bold text-dark text-decoration-none fs-4\" href=\"/\">{{ title }}</a>\n <nav class=\"nav\">\n <a class=\"nav-link text-secondary fw-medium px-3\" href=\"{{ nav1_url }}\">{{ nav1_name }}</a>\n <a class=\"nav-link text-secondary fw-medium px-3\" href=\"{{ nav2_url }}\">{{ nav2_name }}</a>\n <a class=\"nav-link text-secondary fw-medium px-3\" href=\"{{ nav3_url }}\">{{ nav3_name }}</a>\n </nav>\n </div>\n</header>\n");
    cax_write_file("templates/partials/footer.cax","<footer class=\"text-center py-4 text-muted\">\n <small>&copy; 2026 {{ author }}. Built with {{ generator }}</small>\n</footer>\n");
    cax_write_file("templates/layouts/default.cax","<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n <meta charset=\"UTF-8\">\n <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n <!-- BEBAS PILIH SEO - IF CONDITION -->\n {% if seo %}\n  <!-- seo:true = AUTO SEO KITA - generator CAX + version, canonical site.url, og:image favicon metadata -->\n  {{ seo_tags }}\n {% else %}\n  <!-- seo:false = MANUAL SEO LU - bebas bikin sendiri via seo.cax -->\n  {% include seo.cax %}\n {% endif %}\n <link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/css/bootstrap.min.css\" rel=\"stylesheet\">\n <link href=\"/css/style.css\" rel=\"stylesheet\">\n <link rel=\"sitemap\" type=\"application/xml\" href=\"/sitemap.xml\">\n <link rel=\"alternate\" type=\"application/rss+xml\" href=\"/rss.xml\" title=\"{{ site_title }}\">\n</head>\n<body class=\"bg-light\">\n {% include header.cax %}\n <main class=\"container my-5\">\n <div class=\"card shadow-sm border-0 p-4\">\n <h1 class=\"mb-3 text-primary\">{{ title }}</h1>\n <p class=\"text-muted\">{{ description }}</p>\n <div class=\"mb-3\">{{ tags_html }}</div>\n <hr>\n <div class=\"content-body text-secondary lh-lg\">\n {{ content }}\n </div>\n <div class=\"mt-4 pt-3 border-top d-flex justify-content-between\">\n <div>{{ prev_link }}</div>\n <div>{{ next_link }}</div>\n </div>\n <small class=\"text-muted\">Forged with {{ generator }}</small>\n </main>\n {% include footer.cax %}\n</body>\n</html>\n");
    cax_write_file("templates/layouts/home.cax","<!DOCTYPE html>\n<html lang=\"id\">\n<head>\n <meta charset=\"UTF-8\">\n <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n {% if seo %}{{ seo_tags }}{% else %}{% include seo.cax %}{% endif %}\n <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/axcora-css@1.0.1/axcora.min.css\">\n <link href=\"/css/style.css\" rel=\"stylesheet\">\n</head>\n<body>\n{% include header.cax %}\n<div class=\"container\">\n <h4>Centered Content - {{ cax_version }}</h4>\n <img src=\"{{ image }}\" alt=\"{{ hero_title }}\" class=\"img-fluid\">\n <p>{{ hero_description }}</p>\n <small>Powered by {{ generator }}</small>\n</div>\n<main class=\"container\">\n{{ content }}\n</main>\n{% include footer.cax %}\n</body>\n</html>\n");
    cax_write_file("public/css/style.css","body {\n font-family: system-ui, -apple-system, sans-serif;\n background-color: #f8f9fa;\n}\n");
    cax_write_file("content/index.md","---\nlayout: home.cax\ntitle: Welcome to CAX Engine\ndescription: Blazing fast static site generator written in pure C.\nseo: true\nimage: /og-home.jpg\n---\n<h3>Hello World from C Architecture</h3>\n<p>End-to-end integration verified successfully.</p>\n");
    cax_write_file("content/about.md","---\ntitle: About Us\ndescription: Learn more about CAX Static Site Generator architecture.\nlayout: default.cax\ntags:\n - about\n - cax\n---\n<p>This page is automatically rendered directly from a root content markdown file.</p>\n");
    cax_write_file("content/posts/first-post.md","---\ntitle: First Blog Post in C\ndescription: Exploring static site generation speed.\nlayout: default.cax\ntags:\n - c\n - blog\n---\n<p>This is the first article inside our automated collection loop.</p>\n");
    cax_write_file("content/posts/second-post.md","---\ntitle: Advanced Memory Management\ndescription: Fast string parsing and allocation.\nlayout: default.cax\ntags:\n - c\n - memory\n---\n<p>This is the second article with next and previous navigation links.</p>\n");
}
static CAXObject *copy_metadata_object(CAXObject *src) {
    if (!src) return NULL;
    CAXObject *dst = cax_object_new();
    for (int i = 0; i < src->count; i++) {
        if (src->fields[i].type == CAX_TYPE_STRING) cax_object_set_string(dst, src->fields[i].key, src->fields[i].string_val);
        else if (src->fields[i].type == CAX_TYPE_POINTER) cax_object_set_pointer(dst, src->fields[i].key, src->fields[i].pointer_val);
    }
    return dst;
}
static char *build_tags_html(CAXArray *tags_arr) {
    if (!tags_arr || tags_arr->count == 0) return cax_strdup("");
    size_t buf_size = 8192;
    char *buf = malloc(buf_size);
    if (!buf) return cax_strdup("");
    buf[0] = '\0';
    snprintf(buf, buf_size, "<div class=\"tags-container\">");
    for (int i = 0; i < tags_arr->count; i++) {
        const char *tag_str = (const char *)tags_arr->items[i];
        if (tag_str) {
            char badge[512];
            snprintf(badge, sizeof(badge), "<a href=\"/tags/%s/\" class=\"badge bg-secondary text-decoration-none me-1\">%s</a>", tag_str, tag_str);
            if (strlen(buf) + strlen(badge) + 32 < buf_size) strcat(buf, badge);
        }
    }
    strcat(buf, "</div>");
    return buf;
}
static void process_collection_dir(const char *dir_path, const char *coll_name, CAXArray *master_array) {
    DIR *dir = opendir(dir_path);
    if (!dir) return;
    struct dirent *entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_name[0] == '.') continue;
        char full_path[8192];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (cax_is_directory(full_path)) {
            char nested_coll[1024];
            snprintf(nested_coll, sizeof(nested_coll), "%s/%s", coll_name, entry->d_name);
            process_collection_dir(full_path, nested_coll, master_array);
            continue;
        }
        char *ext = strrchr(entry->d_name, '.');
        if (!ext || strcmp(ext, ".md")!= 0) continue;
        char *file_content = cax_read_file(full_path);
        if (!file_content) continue;
        CAXParsedDocument *doc = cax_frontmatter_parse(file_content);
        free(file_content);
        if (!doc) continue;
        CAXObject *item_obj = cax_object_new();
        if (doc->metadata) {
            for (int i = 0; i < doc->metadata->count; i++) {
                if (doc->metadata->fields[i].type == CAX_TYPE_STRING)
                    cax_object_set_string(item_obj, doc->metadata->fields[i].key, doc->metadata->fields[i].string_val);
                else if (doc->metadata->fields[i].type == CAX_TYPE_POINTER)
                    cax_object_set_pointer(item_obj, doc->metadata->fields[i].key, doc->metadata->fields[i].pointer_val);
            }
        }
        char slug[1024];
        strncpy(slug, entry->d_name, sizeof(slug)-1);
        slug[sizeof(slug)-1] = '\0';
        char *dot = strrchr(slug, '.'); if (dot) *dot = '\0';
        char url_buf[4096];
        snprintf(url_buf, sizeof(url_buf), "/%s/%s/", coll_name, slug);
        cax_object_set_string(item_obj, "url", url_buf);
        cax_object_set_string(item_obj, "permalink", url_buf);
        cax_object_set_string(item_obj, "slug", slug);
        cax_array_add(master_array, item_obj);
        cax_frontmatter_free(doc);
    }
    closedir(dir);
}

// ==============================
// PHASE SEO FINAL - hierarchy + auto_seo:true/false + JSON-LD
// ==============================
static const char* seo_get_nonempty(CAXObject *obj, const char *key){
    if(!obj || !key) return NULL;
    const char *v = cax_object_get_string(obj, key);
    if(v && *v) return v;
    return NULL;
}

static const char* seo_resolve_title(CAXObject *ctx, CAXObject *global){
    const char *v = NULL;
    // 1. frontmatter title
    v = seo_get_nonempty(ctx, "title");
    if(v) return v;
    // 2. metadata.title
    v = seo_get_nonempty(ctx, "metadata.title");
    if(v) return v;
    // 3. global title (from _data yaml/json)
    v = seo_get_nonempty(global, "title");
    if(v) return v;
    v = seo_get_nonempty(global, "site_title");
    if(v) return v;
    // 4. site.title from config
    CAXObject *site = NULL;
    if(global){
        site = cax_object_get_pointer(global, "site");
        if(!site){
            CAXObject *meta = cax_object_get_pointer(global, "metadata");
            if(meta) site = cax_object_get_pointer(meta, "site");
        }
    }
    if(site){
        v = seo_get_nonempty(site, "title");
        if(v) return v;
    }
    // 5. fallback slug/url
    v = seo_get_nonempty(ctx, "slug");
    if(v) return v;
    return "CAX Atelier";
}

static const char* seo_resolve_desc(CAXObject *ctx, CAXObject *global){
    const char *v = NULL;
    v = seo_get_nonempty(ctx, "description");
    if(v) return v;
    v = seo_get_nonempty(ctx, "metadata.description");
    if(v) return v;
    v = seo_get_nonempty(ctx, "desc");
    if(v) return v;
    // global yaml/json
    v = seo_get_nonempty(global, "description");
    if(v) return v;
    v = seo_get_nonempty(global, "site_description");
    if(v) return v;
    CAXObject *site = NULL;
    if(global){
        site = cax_object_get_pointer(global, "site");
        if(!site){
            CAXObject *meta = cax_object_get_pointer(global, "metadata");
            if(meta) site = cax_object_get_pointer(meta, "site");
        }
    }
    if(site){
        v = seo_get_nonempty(site, "description");
        if(v) return v;
    }
    return "High performance Static Site Generator in C - Horologe Atelier Brass Chronometer";
}

static const char* seo_resolve_image(CAXObject *ctx, CAXObject *global){
    const char *v = NULL;
    v = seo_get_nonempty(ctx, "image");
    if(v) return v;
    v = seo_get_nonempty(ctx, "og_image");
    if(v) return v;
    v = seo_get_nonempty(ctx, "metadata.image");
    if(v) return v;
    v = seo_get_nonempty(global, "image");
    if(v) return v;
    v = seo_get_nonempty(global, "og_image");
    if(v) return v;
    v = seo_get_nonempty(global, "site_image");
    if(v) return v;
    CAXObject *site = NULL;
    if(global){
        site = cax_object_get_pointer(global, "site");
        if(!site){
            CAXObject *meta = cax_object_get_pointer(global, "metadata");
            if(meta) site = cax_object_get_pointer(meta, "site");
        }
    }
    if(site){
        v = seo_get_nonempty(site, "image");
        if(v) return v;
        v = seo_get_nonempty(site, "og_image");
        if(v) return v;
    }
    return "/og-image.jpg";
}

static const char* seo_resolve_favicon(CAXObject *ctx, CAXObject *global){
    // favicon & icon ambil dari metadata saja - yaml/json _data
    const char *v = NULL;
    v = seo_get_nonempty(ctx, "favicon");
    if(v) return v;
    v = seo_get_nonempty(ctx, "icon");
    if(v) return v;
    // dari metadata only
    CAXObject *site = NULL;
    if(global){
        site = cax_object_get_pointer(global, "site");
        if(!site){
            CAXObject *meta = cax_object_get_pointer(global, "metadata");
            if(meta) site = cax_object_get_pointer(meta, "site");
        }
    }
    if(site){
        v = seo_get_nonempty(site, "favicon");
        if(v) return v;
        v = seo_get_nonempty(site, "icon");
        if(v) return v;
    }
    if(global){
        v = seo_get_nonempty(global, "favicon");
        if(v) return v;
        v = seo_get_nonempty(global, "icon");
        if(v) return v;
    }
    return "/favicon.ico";
}

static const char* seo_resolve_url(CAXObject *global){
    const char *v = NULL;
    // 5. canonical dari site.url - support yaml/json
    v = seo_get_nonempty(global, "site_url");
    if(v) return v;
    v = seo_get_nonempty(global, "site.url");
    if(v) return v;
    v = seo_get_nonempty(global, "url");
    if(v) return v;
    CAXObject *site = NULL;
    if(global){
        site = cax_object_get_pointer(global, "site");
        if(!site){
            CAXObject *meta = cax_object_get_pointer(global, "metadata");
            if(meta) site = cax_object_get_pointer(meta, "site");
        }
    }
    if(site){
        v = seo_get_nonempty(site, "url");
        if(v) return v;
        v = seo_get_nonempty(site, "site_url");
        if(v) return v;
    }
    return "http://localhost:8080";
}

static const char* seo_resolve_author(CAXObject *ctx, CAXObject *global){
    const char *v = NULL;
    v = seo_get_nonempty(ctx, "author");
    if(v) return v;
    v = seo_get_nonempty(ctx, "metadata.author");
    if(v) return v;
    v = seo_get_nonempty(global, "author");
    if(v) return v;
    v = seo_get_nonempty(global, "site_author");
    if(v) return v;
    CAXObject *site = NULL;
    if(global){
        site = cax_object_get_pointer(global, "site");
        if(!site){
            CAXObject *meta = cax_object_get_pointer(global, "metadata");
            if(meta) site = cax_object_get_pointer(meta, "site");
        }
    }
    if(site){
        v = seo_get_nonempty(site, "author");
        if(v) return v;
    }
    return "Axcora Technology";
}

static int seo_is_enabled(CAXObject *ctx){
    if(!ctx) return 1;
    const char *s = cax_object_get_string(ctx, "seo");
    if(!s) s = cax_object_get_string(ctx, "auto_seo");
    if(!s) return 1; // default true = auto SEO
    // handle boolean false, 0, no, off case-insensitive
    char low[64]; int i=0;
    for(; s[i] && i<63; i++) low[i]= (s[i]>='A' && s[i]<='Z') ? s[i]+32 : s[i];
    low[i]='\0';
    if(strcmp(low,"false")==0 || strcmp(low,"0")==0 || strcmp(low,"no")==0 || strcmp(low,"off")==0 || strcmp(low,"f")==0) return 0;
    return 1;
}

static char* build_seo_tags(CAXObject *ctx, CAXObject *global){
    const char *title = seo_resolve_title(ctx, global);
    const char *desc = seo_resolve_desc(ctx, global);
    const char *image = seo_resolve_image(ctx, global);
    const char *favicon = seo_resolve_favicon(ctx, global);
    const char *page_url = seo_get_nonempty(ctx, "url");
    if(!page_url) page_url = "/";
    const char *site_url_raw = seo_resolve_url(global);
    const char *site_title = seo_get_nonempty(global, "site_title");
    if(!site_title) site_title = seo_get_nonempty(global, "title");
    if(!site_title) site_title = "CAX Atelier";
    const char *author = seo_resolve_author(ctx, global);
    // generator = CAX SSG - Static Site Generator in C + version.h
    static char gen_str[256];
    snprintf(gen_str, sizeof(gen_str), "CAX SSG v%s - Static Site Generator in C", CAX_VERSION);
    const char *generator = gen_str;
    
    // canonical = site.url + page url, no double slash
    char site_url[1024]; snprintf(site_url, sizeof(site_url), "%s", site_url_raw);
    size_t sl = strlen(site_url);
    if(sl>0 && site_url[sl-1]=='/') site_url[sl-1]='\0';
    char canonical[2048]; snprintf(canonical, sizeof(canonical), "%s%s", site_url, page_url);
    
    // image full url
    char img_full[2048];
    if(image[0]=='h' && strncmp(image,"http",4)==0) snprintf(img_full, sizeof(img_full), "%s", image);
    else if(image[0]=='/') snprintf(img_full, sizeof(img_full), "%s%s", site_url, image);
    else snprintf(img_full, sizeof(img_full), "%s/%s", site_url, image);
    
    char fav_full[2048];
    if(favicon[0]=='h' && strncmp(favicon,"http",4)==0) snprintf(fav_full, sizeof(fav_full), "%s", favicon);
    else if(favicon[0]=='/') snprintf(fav_full, sizeof(fav_full), "%s%s", site_url, favicon);
    else snprintf(fav_full, sizeof(fav_full), "%s/%s", site_url, favicon);

    char *buf = malloc(32768);
    if(!buf) return cax_strdup("");
    // TITLE = title or metadata title or config title SAJA - jangan melebar | site_title
    // site_title cuma fallback kalau title gak ada, bukan ditambahin
    snprintf(buf, 32768,
        "<title>%s</title>\n"
        "<meta name=\"description\" content=\"%s\">\n"
        "<meta name=\"author\" content=\"%s\">\n"
        "<meta name=\"generator\" content=\"%s\">\n"
        "<link rel=\"icon\" href=\"%s\">\n"
        "<link rel=\"canonical\" href=\"%s\">\n"
        "<meta property=\"og:type\" content=\"article\">\n"
        "<meta property=\"og:title\" content=\"%s\">\n"
        "<meta property=\"og:description\" content=\"%s\">\n"
        "<meta property=\"og:url\" content=\"%s\">\n"
        "<meta property=\"og:site_name\" content=\"%s\">\n"
        "<meta property=\"og:image\" content=\"%s\">\n"
        "<meta name=\"twitter:card\" content=\"summary_large_image\">\n"
        "<meta name=\"twitter:title\" content=\"%s\">\n"
        "<meta name=\"twitter:description\" content=\"%s\">\n"
        "<meta name=\"twitter:image\" content=\"%s\">\n"
        "<script type=\"application/ld+json\">{\"@context\":\"https://schema.org\",\"@type\":\"Article\",\"headline\":\"%s\",\"description\":\"%s\",\"image\":\"%s\",\"author\":{\"@type\":\"Person\",\"name\":\"%s\"},\"publisher\":{\"@type\":\"Organization\",\"name\":\"%s\",\"logo\":{\"@type\":\"ImageObject\",\"url\":\"%s\"}},\"mainEntityOfPage\":{\"@type\":\"WebPage\",\"@id\":\"%s\"}}</script>\n",
        title,
        desc,
        author,
        generator,
        fav_full,
        canonical,
        title,
        desc,
        canonical,
        site_title,
        img_full,
        title,
        desc,
        img_full,
        title,
        desc,
        img_full,
        author,
        site_title,
        fav_full,
        canonical
    );
    return buf;
}

static char* inject_seo_into_html(const char *html, const char *seo_tags){
    if(!html || !seo_tags) return cax_strdup(html ? html : "");
    // case-insensitive search for </head>
    const char *head_end = NULL;
    const char *p = html;
    while(*p){
        if((p[0]=='<' && p[1]=='/' && (p[2]=='h' || p[2]=='H') && (p[3]=='e' || p[3]=='E') && (p[4]=='a' || p[4]=='A') && (p[5]=='d' || p[5]=='D') && p[6]=='>')){
            head_end = p;
            break;
        }
        p++;
    }
    if(!head_end){
        // try <head> injection after <head>
        const char *head_start = strstr(html, "<head>");
        if(!head_start) head_start = strstr(html, "<HEAD>");
        if(head_start){
            head_start = strchr(head_start, '>');
            if(head_start){
                head_start++;
                size_t before_len = head_start - html;
                size_t total = strlen(html) + strlen(seo_tags) + 1;
                char *out = malloc(total+1);
                memcpy(out, html, before_len);
                out[before_len]='\0';
                strcat(out, seo_tags);
                strcat(out, head_start);
                return out;
            }
        }
        size_t len = strlen(html) + strlen(seo_tags) + 2;
        char *out = malloc(len);
        snprintf(out, len, "%s\n%s", seo_tags, html);
        return out;
    }
    size_t before_len = head_end - html;
    size_t total = strlen(html) + strlen(seo_tags) + 1;
    char *out = malloc(total+1);
    memcpy(out, html, before_len);
    out[before_len] = '\0';
    strcat(out, seo_tags);
    strcat(out, head_end);
    return out;
}

static void copy_all_data_to_context(CAXObject *src, CAXObject *dst) {
    if (!src ||!dst) return;
    for (int i = 0; i < src->count; i++) {
        if (src->fields[i].type == CAX_TYPE_STRING) cax_object_set_string(dst, src->fields[i].key, src->fields[i].string_val);
        else if (src->fields[i].type == CAX_TYPE_POINTER) cax_object_set_pointer(dst, src->fields[i].key, src->fields[i].pointer_val);
    }
}
static void flatten_site_from_metadata(CAXObject *src, CAXObject *dst) {
    if (!src ||!dst) return;
    CAXObject *metadata = cax_object_get_pointer(src, "metadata");
    if (metadata) {
        CAXObject *site = cax_object_get_pointer(metadata, "site");
        if (site) {
            for (int i = 0; i < site->count; i++) {
                if (site->fields[i].type == CAX_TYPE_STRING) cax_object_set_string(dst, site->fields[i].key, site->fields[i].string_val);
            }
        }
    }
}
static void render_collection_items(const char *dir_path, const char *coll_name, CAXArray *master_array, CAXObject *global_data) {
    DIR *dir = opendir(dir_path);
    if (!dir) return;
    struct dirent *entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_name[0] == '.') continue;
        char full_path[8192];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (cax_is_directory(full_path)) {
            char nested_coll[1024];
            snprintf(nested_coll, sizeof(nested_coll), "%s/%s", coll_name, entry->d_name);
            render_collection_items(full_path, nested_coll, master_array, global_data);
            continue;
        }
        char *ext = strrchr(entry->d_name, '.');
        if (!ext || strcmp(ext, ".md")!= 0) continue;
        char *file_content = cax_read_file(full_path);
        if (!file_content) continue;
        CAXParsedDocument *doc = cax_frontmatter_parse(file_content);
        free(file_content);
        if (!doc) continue;
        CAXObject *context = cax_object_new();
        copy_all_data_to_context(global_data, context);
        flatten_site_from_metadata(global_data, context);
        CAXObject *nav_obj = cax_object_get_pointer(global_data, "nav");
        if (nav_obj) {
            cax_object_set_pointer(context, "nav", nav_obj);
            for (int i = 0; i < nav_obj->count; i++) if (nav_obj->fields[i].type == CAX_TYPE_STRING) cax_object_set_string(context, nav_obj->fields[i].key, nav_obj->fields[i].string_val);
        }
        if (doc->metadata) {
            for (int i = 0; i < doc->metadata->count; i++) {
                if (doc->metadata->fields[i].type == CAX_TYPE_STRING) cax_object_set_string(context, doc->metadata->fields[i].key, doc->metadata->fields[i].string_val);
                else if (doc->metadata->fields[i].type == CAX_TYPE_POINTER) cax_object_set_pointer(context, doc->metadata->fields[i].key, doc->metadata->fields[i].pointer_val);
            }
        }
        CAXArray *tags_arr = cax_object_get_pointer(context, "tags");
        if (tags_arr) { char *tags_html = build_tags_html(tags_arr); cax_object_set_string(context, "tags_html", tags_html); free(tags_html); }
        else cax_object_set_string(context, "tags_html", "");
        char slug[1024];
        strncpy(slug, entry->d_name, sizeof(slug) - 1);
        slug[sizeof(slug) - 1] = '\0';
        char *dot = strrchr(slug, '.'); if (dot) *dot = '\0';
        char url_buf[4096];
        snprintf(url_buf, sizeof(url_buf), "/%s/%s/", coll_name, slug);
        cax_object_set_string(context, "url", url_buf);
        cax_object_set_string(context, "permalink", url_buf);
        cax_object_set_string(context, "slug", slug);
        int current_index = -1;
        for (int i = 0; i < master_array->count; i++) {
            const char *u = cax_object_get_string(master_array->items[i], "url");
            if (u && strcmp(u, url_buf) == 0) { current_index = i; break; }
        }
        if (current_index > 0) {
            CAXObject *prev_item = master_array->items[current_index - 1];
            const char *p_url = cax_object_get_string(prev_item, "url");
            const char *p_title = cax_object_get_string(prev_item, "title");
            char prev_buf[1024];
            snprintf(prev_buf, sizeof(prev_buf), "<a href=\"%s\">&larr; %s</a>", p_url? p_url : "", p_title? p_title : "");
            cax_object_set_string(context, "prev_link", prev_buf);
        }
        if (current_index >= 0 && current_index < master_array->count - 1) {
            CAXObject *next_item = master_array->items[current_index + 1];
            const char *n_url = cax_object_get_string(next_item, "url");
            const char *n_title = cax_object_get_string(next_item, "title");
            char next_buf[1024];
            snprintf(next_buf, sizeof(next_buf), "<a href=\"%s\">%s &rarr;</a>", n_url? n_url : "", n_title? n_title : "");
            cax_object_set_string(context, "next_link", next_buf);
        }
        // BUILD SEO TAGS BEFORE RENDER so {{ seo_tags }} works for manual seo:false
        char *seo_tags_pre = build_seo_tags(context, global_data);
        cax_object_set_string(context, "seo_tags", seo_tags_pre);
        free(seo_tags_pre);
        // Re-build for injection after to keep string alive
        char *seo_tags_str = build_seo_tags(context, global_data);
        // ELEVENTY STYLE: templating in markdown - {{ url }}, {% for %}, etc
        char *templated_md = cax_template_render(doc->body, context);
        if(!templated_md) templated_md = cax_strdup(doc->body ? doc->body : "");
        char *html_body = cax_markdown_to_html(templated_md);
        if (html_body) {
            char *final_content = cax_template_render(html_body, context);
            if(!final_content) final_content = cax_strdup(html_body);
            cax_object_set_string(context, "content", final_content);
            free(final_content);
            char *toc_html = cax_markdown_generate_toc(templated_md);
            cax_object_set_string(context, "toc", toc_html);
            free(toc_html);
            free(html_body);
        }
        free(templated_md);
        const char *raw_layout = cax_object_get_string(context, "layout");
        char layout_buf[256] = {0};
        if (raw_layout) { snprintf(layout_buf, sizeof(layout_buf), "%s", raw_layout); char *tmp=clean_trim(layout_buf); memmove(layout_buf, tmp, strlen(tmp)+1); }
        if (strlen(layout_buf) == 0) strcpy(layout_buf, "default.cax");
        char layout_path[2048];
        snprintf(layout_path, sizeof(layout_path), "templates/layouts/%s", layout_buf);
        char *final_html = cax_template_render_file(layout_path, context);
        if (!final_html) final_html = cax_template_render_file("templates/layouts/default.cax", context);
        if (!final_html) final_html = cax_strdup("<h1>{{ title }}</h1>{{ content }}");
        // LOGIKA: seo:false = manual {{ seo_tags }} / {% include seo.cax %}, seo:true = auto inject
        char *seo_final = final_html;
        if(seo_is_enabled(context)){
            // if template already has generator (manual include used), skip auto inject to avoid duplicate
            if(strstr(final_html, "name=\"generator\"")==NULL && strstr(final_html, "name='generator'")==NULL){
                char *injected = inject_seo_into_html(final_html, seo_tags_str);
                free(final_html);
                seo_final = injected;
            }
        }
        free(seo_tags_str);
        char out_dir[8192];
        snprintf(out_dir, sizeof(out_dir), "site/%s/%s", coll_name, slug);
        cax_create_directory(out_dir);
        char out_path[8192];
        snprintf(out_path, sizeof(out_path), "%s/index.html", out_dir);
        cax_write_file(out_path, seo_final);
        free(seo_final);
        cax_object_free(context);
        cax_frontmatter_free(doc);
    }
    closedir(dir);
}
void cax_builder_run(void) {
    if(check_cache_valid()){
        printf("\n [CACHE] No changes - site/ is fresh - 0ms\n");
        printf(" [CACHE] Horologe Atelier - Brass Chronometer\n\n");
        return;
    }
    clock_t start = clock();
    cax_create_directory("site");
    minify_and_copy_assets();
    CAXObject *global_data = cax_object_new();
    cax_load_all_data("_data", global_data);
    // PHASE SEO: inject generator meta + version - CAX SSG vX - Static Site Generator in C
    char gen_buf[512];
    snprintf(gen_buf, sizeof(gen_buf), "CAX SSG v%s - Static Site Generator in C", CAX_VERSION);
    cax_object_set_string(global_data, "generator", gen_buf);
    cax_object_set_string(global_data, "cax_version", CAX_VERSION);
    cax_object_set_string(global_data, "cax_codename", CAX_CODENAME);
    cax_object_set_string(global_data, "cax_edition", CAX_EDITION);
    cax_object_set_string(global_data, "cax_url", CAX_URL);
    // SEO defaults
    const char *site_url = cax_object_get_string(global_data, "url");
    if(!site_url){
        CAXObject *meta = cax_object_get_pointer(global_data, "metadata");
        if(meta){
            CAXObject *site = cax_object_get_pointer(meta, "site");
            if(site) site_url = cax_object_get_string(site, "url");
        }
    }
    if(site_url) cax_object_set_string(global_data, "site_url", site_url);
    else cax_object_set_string(global_data, "site_url", "http://localhost:8080");
    const char *site_title = cax_object_get_string(global_data, "title");
    if(site_title) cax_object_set_string(global_data, "site_title", site_title);
    else cax_object_set_string(global_data, "site_title", "CAX Atelier");
    CAXObject *pagination_controllers = cax_object_new();
    CAXObject *collections_obj = cax_object_new();
    cax_object_set_pointer(global_data, "collections", collections_obj);
    DIR *scan = opendir("content");
    if(scan){
        struct dirent *e;
        while((e=readdir(scan))!=NULL){
            if(e->d_name[0]=='.') continue;
            char fp[2048]; snprintf(fp,sizeof(fp),"content/%s",e->d_name);
            if(cax_is_directory(fp)) continue;
            char *ext = strrchr(e->d_name,'.');
            if(!ext || strcmp(ext,".md")!=0) continue;
            char *fc = cax_read_file(fp);
            if(!fc) continue;
            CAXParsedDocument *doc = cax_frontmatter_parse(fc);
            free(fc);
            if(!doc ||!doc->metadata){ if(doc) cax_frontmatter_free(doc); continue; }
            const char *coll_raw = cax_object_get_string(doc->metadata,"collection");
             if(coll_raw){
                char coll[512];
                normalize_coll_name(coll_raw, coll, sizeof(coll));
                CAXObject *ctrl = cax_object_new();
                for(int i=0;i<doc->metadata->count;i++){
                    CAXField *f = &doc->metadata->fields[i];
                    if(strcmp(f->key,"collection")==0) continue;
                    if(f->type==CAX_TYPE_STRING) cax_object_set_string(ctrl,f->key,f->string_val);
                    else cax_object_set_pointer(ctrl,f->key,f->pointer_val);
                }
                if(doc->body) cax_object_set_string(ctrl,"content",doc->body);
                cax_object_set_pointer(pagination_controllers, coll, ctrl);
            }
            cax_frontmatter_free(doc);
        }
        closedir(scan);
    }
    CAXArray *all_collections_master = cax_array_new();
    DIR *content_dir = opendir("content");
    if (content_dir) {
        struct dirent *entry;
        while ((entry = readdir(content_dir))!= NULL) {
            if (entry->d_name[0] == '.') continue;
            char sub_path[8192];
            snprintf(sub_path, sizeof(sub_path), "content/%s", entry->d_name);
            if (cax_is_directory(sub_path)) {
                CAXArray *coll_array = cax_array_new();
                process_collection_dir(sub_path, entry->d_name, coll_array);
                cax_object_set_pointer(collections_obj, entry->d_name, coll_array);
                cax_object_set_pointer(global_data, entry->d_name, coll_array);
                DIR *sub = opendir(sub_path);
                if(sub){
                    struct dirent *se;
                    while((se=readdir(sub))!=NULL){
                        if(se->d_name[0]=='.') continue;
                        char sub_full[12288];
                        snprintf(sub_full, sizeof(sub_full), "%s/%s", sub_path, se->d_name);
                        if(cax_is_directory(sub_full)){
                            char nested_key[1024];
                            snprintf(nested_key, sizeof(nested_key), "%s/%s", entry->d_name, se->d_name);
                            CAXArray *nested_arr = cax_array_new();
                            process_collection_dir(sub_full, nested_key, nested_arr);
                            cax_object_set_pointer(collections_obj, nested_key, nested_arr);
                            cax_object_set_pointer(global_data, nested_key, nested_arr);
                        }
                    }
                    closedir(sub);
                }
            }
        }
        // 11ty style: featured_themes biar template {% for theme in featured_themes %} tetep jalan
        CAXArray *themes_src = (CAXArray*)cax_object_get_pointer(collections_obj, "themes");
        if(!themes_src) themes_src = (CAXArray*)cax_object_get_pointer(global_data, "themes");
        if(themes_src){
            CAXArray *featured_themes = cax_array_new();
            for(int i=0;i<themes_src->count;i++){
                CAXObject *post=(CAXObject*)themes_src->items[i];
                if(!post) continue;
                // cek tags array atau string
                CAXArray *arr=(CAXArray*)cax_object_get_pointer(post,"tags");
                int ok=0;
                if(arr){
                    for(int k=0;k<arr->count;k++){
                        void *p=arr->items[k];
                        if(!p) continue;
                        CAXObject *o=(CAXObject*)p;
                        const char *v=cax_object_get_string(o,"value");
                        if(!v) v=cax_object_get_string(o,"name");
                        if(!v) v=(const char*)p;
                        if(!v) continue;
                        if(strcmp(v,"featured")==0 || strcmp(v,"featuredthemes")==0){ ok=1; break; }
                    }
                } else {
                    const char *s=cax_object_get_string(post,"tags");
                    if(s && (strstr(s,"featured")||strstr(s,"featuredthemes"))) ok=1;
                }
                if(ok) cax_array_add(featured_themes, post);
            }
            cax_object_set_pointer(global_data,"featured_themes",featured_themes);
            cax_object_set_pointer(collections_obj,"featured_themes",featured_themes);
            // juga expose sebagai global langsung biar {{ featured_themes }} kepanggil
            cax_object_set_pointer(global_data, "featured_themes", featured_themes);
        }
        rewinddir(content_dir);
        while ((entry = readdir(content_dir))!= NULL) {
            if (entry->d_name[0] == '.') continue;
            char sub_path[8192];
            snprintf(sub_path, sizeof(sub_path), "content/%s", entry->d_name);
            if (cax_is_directory(sub_path)) {
                CAXArray *coll_array = (CAXArray*)cax_object_get_pointer(collections_obj, entry->d_name);
                if (!coll_array) continue;
                render_collection_items(sub_path, entry->d_name, coll_array, global_data);
                for (int i = 0; i < coll_array->count; i++) cax_array_add(all_collections_master, coll_array->items[i]);
                char out_sub_dir[512];
                snprintf(out_sub_dir, sizeof(out_sub_dir), "site/%s", entry->d_name);
                cax_create_directory(out_sub_dir);
                int per_page = 5;
                char list_tpl_name[512] = "posts-list.cax";
                char normalized_entry[512];
                normalize_coll_name(entry->d_name, normalized_entry, sizeof(normalized_entry));
                CAXObject *ctrl = cax_object_get_pointer(pagination_controllers, entry->d_name);
                if(!ctrl) ctrl = cax_object_get_pointer(pagination_controllers, normalized_entry);
                if(ctrl){
                    const char *pp = cax_object_get_string(ctrl,"pagination");
                    if(pp) per_page = atoi(pp);
                    const char *ll = cax_object_get_string(ctrl,"layout");
                    if(ll) snprintf(list_tpl_name, sizeof(list_tpl_name), "%.511s", ll);
                } else {
                    char tmp[512];
                    get_coll_list_template(entry->d_name, tmp, sizeof(tmp));
                    snprintf(list_tpl_name, sizeof(list_tpl_name), "%.511s", tmp);
                }
                char full_list_tpl[1024];
                snprintf(full_list_tpl, sizeof(full_list_tpl), "templates/layouts/%s", list_tpl_name);
                if(!file_exists(full_list_tpl)){
                    snprintf(full_list_tpl, sizeof(full_list_tpl), "%s", list_tpl_name);
                    if(!file_exists(full_list_tpl)) strcpy(full_list_tpl, "templates/layouts/default.cax");
                }
                cax_pagination_process(coll_array, per_page, out_sub_dir, full_list_tpl, global_data, pagination_controllers, entry->d_name);
                printf(" + %s (%d)\n", entry->d_name, coll_array->count);
            } else {
                char *ext = strrchr(entry->d_name, '.');
                if (ext && strcmp(ext, ".md") == 0) {
                    char file_path[8192];
                    snprintf(file_path, sizeof(file_path), "content/%s", entry->d_name);
                    char *file_content = cax_read_file(file_path);
                    if (file_content) {
                        CAXParsedDocument *doc = cax_frontmatter_parse(file_content);
                        free(file_content);
                        if (doc) {
                            const char *is_coll_raw = NULL;
                            if(doc->metadata) is_coll_raw = cax_object_get_string(doc->metadata,"collection");
                            if(is_coll_raw){
                                char is_coll[512];
                                normalize_coll_name(is_coll_raw, is_coll, sizeof(is_coll));
                                CAXArray *sub_coll = (CAXArray*)cax_object_get_pointer(collections_obj, is_coll);
                                if(sub_coll){
                                    char rel_name[1024];
                                    strncpy(rel_name, entry->d_name, sizeof(rel_name) - 1);
                                    rel_name[sizeof(rel_name) - 1] = '\0';
                                    char *dot = strrchr(rel_name, '.'); if (dot) *dot = '\0';
                                    char out_dir_p[2048];
                                    snprintf(out_dir_p, sizeof(out_dir_p), "site/%s", rel_name);
                                    cax_create_directory(out_dir_p);
                                    int per_page = 5;
                                    const char *pp = cax_object_get_string(doc->metadata,"pagination");
                                    if(pp) per_page = atoi(pp);
                                    char list_tpl_name[256]="posts-list.cax";
                                    const char *ll = cax_object_get_string(doc->metadata,"layout");
                                    if(ll) snprintf(list_tpl_name, sizeof(list_tpl_name), "%.511s", ll);
                                    char full_list_tpl[1024];
                                    snprintf(full_list_tpl, sizeof(full_list_tpl), "templates/layouts/%s", list_tpl_name);
                                    if(!file_exists(full_list_tpl)){
                                        snprintf(full_list_tpl, sizeof(full_list_tpl), "%s", list_tpl_name);
                                        if(!file_exists(full_list_tpl)) strcpy(full_list_tpl, "templates/layouts/default.cax");
                                    }
                                    cax_pagination_process(sub_coll, per_page, out_dir_p, full_list_tpl, global_data, pagination_controllers, is_coll);
                                    printf(" + %s -> %s (%d) [CTRL]\n", rel_name, is_coll, sub_coll->count);
                                }
                                cax_frontmatter_free(doc);
                                continue;
                            }
                            CAXObject *ctx = cax_object_new();
                            copy_all_data_to_context(global_data, ctx);
                            flatten_site_from_metadata(global_data, ctx);
                            if (doc->metadata) {
                                for (int i = 0; i < doc->metadata->count; i++) {
                                    if (doc->metadata->fields[i].type == CAX_TYPE_STRING) cax_object_set_string(ctx, doc->metadata->fields[i].key, doc->metadata->fields[i].string_val);
                                    else if (doc->metadata->fields[i].type == CAX_TYPE_POINTER) cax_object_set_pointer(ctx, doc->metadata->fields[i].key, doc->metadata->fields[i].pointer_val);
                                }
                            }
                            CAXArray *root_tags_arr = cax_object_get_pointer(ctx, "tags");
                            if (root_tags_arr) { char *tags_html = build_tags_html(root_tags_arr); cax_object_set_string(ctx, "tags_html", tags_html); free(tags_html); }
                            else cax_object_set_string(ctx, "tags_html", "");
                            char rel_name[1024];
                            strncpy(rel_name, entry->d_name, sizeof(rel_name) - 1);
                            rel_name[sizeof(rel_name) - 1] = '\0';
                            char *dot = strrchr(rel_name, '.'); if (dot) *dot = '\0';
                            char url_buf[2048];
                            if (strcmp(rel_name, "index") == 0) snprintf(url_buf, sizeof(url_buf), "/");
                            else snprintf(url_buf, sizeof(url_buf), "/%s/", rel_name);
                            cax_object_set_string(ctx, "url", url_buf);
                            cax_object_set_string(ctx, "permalink", url_buf);
                            CAXObject *root_page_item = copy_metadata_object(ctx);
                            cax_array_add(all_collections_master, root_page_item);
                            // BUILD SEO BEFORE RENDER so {{ seo_tags }} works
                            char *seo_pre2 = build_seo_tags(ctx, global_data);
                            cax_object_set_string(ctx, "seo_tags", seo_pre2);
                            free(seo_pre2);
                            char *seo_tags_str2 = build_seo_tags(ctx, global_data);
                            // ELEVENTY STYLE: templating in markdown root pages
                            char *templated_md2 = cax_template_render(doc->body, ctx);
                            if(!templated_md2) templated_md2 = cax_strdup(doc->body ? doc->body : "");
                            char *html_body = cax_markdown_to_html(templated_md2);
                            if (html_body) {
                                char *final_content2 = cax_template_render(html_body, ctx);
                                if(!final_content2) final_content2 = cax_strdup(html_body);
                                cax_object_set_string(ctx, "content", final_content2);
                                free(final_content2);
                                char *toc_html = cax_markdown_generate_toc(templated_md2);
                                cax_object_set_string(ctx, "toc", toc_html);
                                free(toc_html);
                                free(html_body);
                            }
                            free(templated_md2);
                            const char *raw_layout = cax_object_get_string(ctx, "layout");                          
                            char layout_buf[256] = {0};
                            if (raw_layout) { snprintf(layout_buf, sizeof(layout_buf), "%s", raw_layout); char *tmp=clean_trim(layout_buf); memmove(layout_buf, tmp, strlen(tmp)+1); }
                            if (strlen(layout_buf) == 0) strcpy(layout_buf, "default.cax");
                            char layout_path[2048];
                            snprintf(layout_path, sizeof(layout_path), "templates/layouts/%s", layout_buf);
                            char *final = cax_template_render_file(layout_path, ctx);
                            if(!final) final = cax_template_render_file("templates/layouts/default.cax", ctx);
                            if(!final) final = cax_strdup("<h1>{{ title }}</h1>{{ content }}");
                            char *seo_final = final;
                            if(seo_is_enabled(ctx)){
                                if(strstr(final, "name=\"generator\"")==NULL && strstr(final, "name='generator'")==NULL){
                                    char *injected = inject_seo_into_html(final, seo_tags_str2);
                                    free(final);
                                    seo_final = injected;
                                }
                            }
                            free(seo_tags_str2);
                            if (strcmp(rel_name, "index") == 0) cax_write_file("site/index.html", seo_final);
                            else {
                                char page_dir[2048]; snprintf(page_dir, sizeof(page_dir), "site/%s", rel_name);
                                cax_create_directory(page_dir);
                                char page_file[4096]; snprintf(page_file, sizeof(page_file), "%s/index.html", page_dir);
                                cax_write_file(page_file, seo_final);
                            }
                            free(seo_final);
                            cax_object_free(ctx);
                            cax_frontmatter_free(doc);
                        }
                    }
                }
            }
        }
        closedir(content_dir);
    }
    cax_tags_generate(all_collections_master, "site", global_data);
    cax_sitemap_generate_full(all_collections_master, global_data, "site", pagination_controllers);
    // PHASE SEO: robots.txt - sitemap dari metadata.url / config.url
    {
        const char *robots_site_url = seo_resolve_url(global_data);
        char robots_buf[1024];
        snprintf(robots_buf, sizeof(robots_buf), "User-agent: *\nAllow: /\nSitemap: %s/sitemap.xml\n", robots_site_url);
        cax_write_file("site/robots.txt", robots_buf);
    }
    // PHASE SEO: RSS feed
    {
        char rss[65536];
        snprintf(rss, sizeof(rss), "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<rss version=\"2.0\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n<channel>\n<title>%s</title>\n<link>%s</link>\n<description>%s - Powered by %s</description>\n<generator>%s</generator>\n<language>en</language>\n",
            cax_object_get_string(global_data, "site_title") ? cax_object_get_string(global_data, "site_title") : "CAX Atelier",
            cax_object_get_string(global_data, "site_url"),
            cax_object_get_string(global_data, "site_title") ? cax_object_get_string(global_data, "site_title") : "CAX Atelier",
            "CAX SSG",
            cax_object_get_string(global_data, "generator"));
        // add items from master
        for(int i=0;i<all_collections_master->count && i<50;i++){
            CAXObject *it = all_collections_master->items[i];
            if(!it) continue;
            const char *t = cax_object_get_string(it, "title");
            const char *u = cax_object_get_string(it, "url");
            const char *d = cax_object_get_string(it, "description");
            if(!t || !u) continue;
            char item[2048];
            snprintf(item, sizeof(item), "<item><title><![CDATA[%s]]></title><link>%s%s</link><guid>%s%s</guid><description><![CDATA[%s]]></description></item>\n",
                t, cax_object_get_string(global_data, "site_url"), u, cax_object_get_string(global_data, "site_url"), u, d?d:t);
            strncat(rss, item, sizeof(rss)-strlen(rss)-1);
        }
        strncat(rss, "</channel></rss>", sizeof(rss)-strlen(rss)-1);
        cax_write_file("site/rss.xml", rss);
    }
    save_cache();
    clock_t end = clock();
    double ms = ((double)(end-start))/CLOCKS_PER_SEC*1000;
    printf("\n [PERF] Build forged in %.0fms - Horologe Atelier\n", ms);
    for (int i = 0; i < all_collections_master->count; i++) if (all_collections_master->items[i]) cax_object_free(all_collections_master->items[i]);
    cax_array_free(all_collections_master);
    cax_object_free(global_data);
    cax_object_free(pagination_controllers);
    remove_livereload_script();
#ifdef _WIN32
    printf("\n------------------------------------------\n");
    printf(" CAX Engine %s - %s\n", CAX_VERSION, CAX_CODENAME);
    printf(" %s - %s\n", CAX_MAKER, CAX_URL);
    printf("------------------------------------------\n");
    printf(" [SUCCESS] Build completed in site/\n");
    printf(" -> pretty urls enabled\n\n");
#else
    printf("\n------------------------------------------\n");
    printf(" CAX Engine %s - %s\n", CAX_VERSION, CAX_CODENAME);
    printf(" %s - %s\n", CAX_MAKER, CAX_URL);
    printf("------------------------------------------\n");
    printf(" Build completed in site/\n\n");
#endif
}
void cax_builder_start_server(void) {
    cax_builder_run();
#ifdef _WIN32
    printf("\n [SERVER] Native C - http://localhost:8080\n");
    printf(" [INFO] Serving site/ folder - No PHP/Python!\n\n");
    (void)system("start http://localhost:8080");
#else
    printf("\n [SERVER] Native C - http://localhost:8080\n");
#endif
    cax_server_start("site", 8080);
}
void cax_builder_serve(void){
    cax_builder_start_server();
}
#ifdef _WIN32
static DWORD WINAPI server_thread_func(LPVOID lpParam){
    (void)lpParam;
    cax_server_start("site", 8080);
    return 0;
}
#endif
void cax_builder_start_with_watch(void){
    cax_builder_run();
    inject_livereload_script();
    printf("\n [WATCH] Live Reload - Native C Server http://localhost:8080\n");
    printf(" [WATCH] Watching content/ templates/ _data/ public/\n");
    printf(" [SERVER] Starting server in background thread...\n\n");
#ifdef _WIN32
    HANDLE hThread = CreateThread(NULL, 0, server_thread_func, NULL, 0, NULL);
    if(hThread){
        printf(" [SERVER] Thread started - http://localhost:8080\n");
        (void)system("start http://localhost:8080");
    }
    time_t lc=scan_dir("content");
    time_t lt=scan_dir("templates");
    time_t ld=scan_dir("_data");
    time_t lp=scan_dir("public");
    while(1){
        Sleep(1000);
        time_t c=scan_dir("content");
        time_t t=scan_dir("templates");
        time_t d=scan_dir("_data");
        time_t p=scan_dir("public");
        if(c!=lc||t!=lt||d!=ld||p!=lp){
            printf(" [CHANGE] rebuilding...\n");
            cax_builder_run();
            inject_livereload_script();
            printf(" [DONE] rebuilt - browser will auto reload\n");
            lc=c; lt=t; ld=d; lp=p;
        }
    }
#else
    if(fork()==0){ cax_server_start("site",8080); exit(0); }
    time_t lc=scan_dir("content");
    time_t lt=scan_dir("templates");
    time_t ld=scan_dir("_data");
    time_t lp=scan_dir("public");
    { int _cax_sys2 = system("xdg-open http://localhost:8080 2>/dev/null &"); if(_cax_sys2!=0) {} }
    while(1){
        sleep(1);
        time_t c=scan_dir("content"); time_t t=scan_dir("templates");
        time_t d=scan_dir("_data"); time_t p=scan_dir("public");
        if(c!=lc||t!=lt||d!=ld||p!=lp){
            printf(" [change] rebuilding...\n");
            cax_builder_run();
            inject_livereload_script();
            printf(" rebuilt\n");
            lc=c; lt=t; ld=d; lp=p;
        }
    }
#endif
}

void cax_builder_new_content(int argc, char *argv[]){
    if(argc < 4){
        printf("\n Usage:\n   cax new post \"My Title\"\n   cax new page \"About\"\n\n");
        return;
    }
    const char *type = argv[2];
    const char *title = argv[3];
    char slug[256]={0}; int j=0;
    for(int i=0; title[i] && j<250; i++){
        char c=title[i];
        if(c>='A' && c<='Z') c+=32;
        if((c>='a' && c<='z') || (c>='0' && c<='9')) slug[j++]=c;
        else if(c==' ' || c=='-' || c=='_') slug[j++]='-';
    }
    slug[j]='\0';
    char filepath[1024]; char filecontent[2048];
    if(strcmp(type,"post")==0){
        snprintf(filepath,sizeof(filepath),"content/posts/%s.md",slug);
        snprintf(filecontent,sizeof(filecontent),"---\ntitle: %s\ndescription: %s\nlayout: default.cax\ntags:\n - blog\n---\n\n<p>%s</p>\n",title,title,title);
    } else {
        snprintf(filepath,sizeof(filepath),"content/%s.md",slug);
        snprintf(filecontent,sizeof(filecontent),"---\ntitle: %s\ndescription: %s\nlayout: default.cax\n---\n\n<p>%s</p>\n",title,title,title);
    }
    FILE *f=fopen(filepath,"r"); if(f){ fclose(f); printf(" [ERROR] Exists: %s\n",filepath); return; }
    cax_write_file(filepath,filecontent);
    printf(" [NEW] Created %s\n",filepath);
}
