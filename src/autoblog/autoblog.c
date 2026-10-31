#include "autoblog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#define MAX_THEMES 512
#define MAX_TAGS 64
#define MAX_TAG_LEN 128
#define MIN_WORDS 1800
#define MAX_RETRIES 2
#define GEMINI_MODEL "gemini-3.8-flash"
#define SITE_BASE "https://www.hockeycomputindo.com"
#define THEMES_JSON "site/themes-index.json"
#define STATE_FILE "autoblog/state.json"
#define POSTS_DIR "content/blog"
#define FALLBACK_IMAGE "logo-192_a7rkga.webp"
#define STACKS_COUNT 10
#define HN_URL "https://hn.algolia.com/api/v1/search?tags=front_page&hitsPerPage=30"

typedef struct {
    char title[512];
    char description[2048];
    char slug[256];
    char url[512];
    char image[512];
    char price[64];
    char demo[512];
    char tags[MAX_TAGS][MAX_TAG_LEN];
    int tag_count;
    int is_premium;
} Theme;

static const char *STACKS[STACKS_COUNT] = {
    "astro", "next", "nuxt", "docusaurus", "starlight",
    "hugo", "jekyll", "svelte", "remix", "solid"
};

static const char *FORBIDDEN[] = {
    "revolutionary", "game-changing", "seamless", "cutting-edge"
};
static const int FORBIDDEN_COUNT = 4;

static int ci_equal(const char *a, const char *b) {
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) return 0;
        a++; b++;
    }
    return *a == *b;
}

static int ci_contains(const char *hay, const char *needle) {
    if (!hay || !needle) return 0;
    size_t nl = strlen(needle);
    if (!nl) return 0;
    for (const char *p = hay; *p; p++) {
        size_t i = 0;
        while (i < nl && p[i] && tolower((unsigned char)p[i]) == tolower((unsigned char)needle[i])) i++;
        if (i == nl) return 1;
    }
    return 0;
}

static char *trim(char *s) {
    while (*s && isspace((unsigned char)*s)) s++;
    if (!*s) return s;
    char *e = s + strlen(s) - 1;
    while (e > s && isspace((unsigned char)*e)) e--;
    e[1] = '\0';
    return s;
}

static void slug_from(const char *in, char *out, size_t out_size) {
    size_t j = 0;
    for (size_t i = 0; in[i] && j < out_size - 1; i++) {
        char c = tolower((unsigned char)in[i]);
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) out[j++] = c;
        else if (c == ' ' || c == '-' || c == '_') out[j++] = '-';
    }
    while (j > 0 && out[j-1] == '-') j--;
    out[j] = '\0';
}

static void json_escape(const char *in, char *out, size_t out_size) {
    if (!in) { out[0] = '\0'; return; }
    size_t j = 0;
    for (size_t i = 0; in[i] && j < out_size - 1; i++) {
        char c = in[i];
        if (c == '"' || c == '\\') { if (j + 2 >= out_size) break; out[j++] = '\\'; out[j++] = c; }
        else if (c == '\n') { if (j + 2 >= out_size) break; out[j++] = '\\'; out[j++] = 'n'; }
        else if (c == '\r') { if (j + 2 >= out_size) break; out[j++] = '\\'; out[j++] = 'r'; }
        else if (c == '\t') { if (j + 2 >= out_size) break; out[j++] = '\\'; out[j++] = 't'; }
        else out[j++] = c;
    }
    out[j] = '\0';
}

static char *read_file(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz < 0) { fclose(f); return NULL; }
    char *buf = malloc(sz + 1);
    if (!buf) { fclose(f); return NULL; }
    size_t rd = fread(buf, 1, sz, f);
    buf[rd] = '\0';
    fclose(f);
    return buf;
}

static int write_file(const char *path, const char *content) {
    FILE *f = fopen(path, "wb");
    if (!f) return 0;
    fputs(content, f);
    fclose(f);
    return 1;
}

static int word_count_body(const char *md) {
    const char *body = md;
    if (strncmp(md, "---", 3) == 0) {
        const char *end = strstr(md + 3, "\n---");
        if (end) body = end + 4;
    }
    int count = 0, in_word = 0;
    for (const char *p = body; *p; p++) {
        if (isspace((unsigned char)*p)) in_word = 0;
        else if (!in_word) { in_word = 1; count++; }
    }
    return count;
}

static const char *json_get_string(const char *obj, const char *key, char *out, size_t out_size) {
    char needle[128];
    snprintf(needle, sizeof(needle), "\"%s\":\"", key);
    const char *p = strstr(obj, needle);
    if (!p) return NULL;
    p += strlen(needle);
    size_t j = 0;
    while (*p && *p != '"' && j < out_size - 1) {
        if (*p == '\\' && *(p+1)) {
            p++;
            if (*p == 'n') out[j++] = '\n';
            else if (*p == 't') out[j++] = '\t';
            else if (*p == '"') out[j++] = '"';
            else if (*p == '\\') out[j++] = '\\';
            else out[j++] = *p;
            p++;
        } else {
            out[j++] = *p++;
        }
    }
    out[j] = '\0';
    return out;
}

static int json_get_bool(const char *obj, const char *key) {
    char needle[128];
    snprintf(needle, sizeof(needle), "\"%s\":", key);
    const char *p = strstr(obj, needle);
    if (!p) return 0;
    p += strlen(needle);
    while (*p == ' ') p++;
    return strncmp(p, "true", 4) == 0;
}

static int parse_themes(const char *json, Theme *themes, int max) {
    int count = 0;
    const char *p = json;
    while (count < max && (p = strstr(p, "{\"title\"")) != NULL) {
        const char *scan = p + 1;
        int depth = 1;
        while (*scan && depth > 0) {
            if (*scan == '{') depth++;
            else if (*scan == '}') depth--;
            else if (*scan == '"') {
                scan++;
                while (*scan && *scan != '"') { if (*scan == '\\') scan++; scan++; }
            }
            scan++;
        }
        if (depth != 0) break;
        size_t len = scan - p;
        if (len > 16384) { p = scan; continue; }

        char *obj = malloc(len + 1);
        if (!obj) break;
        memcpy(obj, p, len);
        obj[len] = '\0';

        Theme *t = &themes[count];
        memset(t, 0, sizeof(*t));

        json_get_string(obj, "title", t->title, sizeof(t->title));
        json_get_string(obj, "slug", t->slug, sizeof(t->slug));
        json_get_string(obj, "url", t->url, sizeof(t->url));
        json_get_string(obj, "image", t->image, sizeof(t->image));
        json_get_string(obj, "description", t->description, sizeof(t->description));
        json_get_string(obj, "price", t->price, sizeof(t->price));
        json_get_string(obj, "demo", t->demo, sizeof(t->demo));
        t->is_premium = json_get_bool(obj, "is_premium");

        const char *tags_p = strstr(obj, "\"tags\":[");
        if (tags_p) {
            tags_p += 8;
            const char *tags_e = strchr(tags_p, ']');
            if (tags_e) {
                const char *cur = tags_p;
                while (cur < tags_e && t->tag_count < MAX_TAGS) {
                    const char *q1 = strchr(cur, '"');
                    if (!q1 || q1 >= tags_e) break;
                    q1++;
                    const char *q2 = q1;
                    while (q2 < tags_e && *q2 != '"') { if (*q2 == '\\') q2++; q2++; }
                    if (q2 >= tags_e) break;
                    size_t tl = q2 - q1;
                    if (tl > 0 && tl < MAX_TAG_LEN) {
                        memcpy(t->tags[t->tag_count], q1, tl);
                        t->tags[t->tag_count][tl] = '\0';
                        t->tag_count++;
                    }
                    cur = q2 + 1;
                }
            }
        }

        if (t->title[0] && t->url[0]) count++;
        free(obj);
        p = scan;
    }
    return count;
}

static int has_tag(Theme *t, const char *tag) {
    for (int i = 0; i < t->tag_count; i++) {
        if (ci_equal(t->tags[i], tag)) return 1;
    }
    return 0;
}

static int run_curl(const char *url, const char *output_file, int timeout, int post_body) {
    char cmd[8192];
    if (post_body) {
                snprintf(cmd, sizeof(cmd),
            "curl -sfL --max-time %d -X POST "
            "-H \"Content-Type: application/json\" "
            "-d @\"%s\" -o \"%s\" \"%s\" 2>nul",
            timeout, output_file, output_file, url);
    } else {
        snprintf(cmd, sizeof(cmd),
            "curl -sfL --max-time %d -A \"Mozilla/5.0\" -o \"%s\" \"%s\" 2>nul",
            timeout, output_file, url);
    }
    return system(cmd);
}

static char *fetch_url_text(const char *url, int timeout) {
    if (!url || !*url) return strdup("");
    char tmp[] = "autoblog_XXXXXX";
    int fd = mkstemp(tmp);
    if (fd < 0) return strdup("");
    close(fd);

    if (run_curl(url, tmp, timeout, 0) != 0) { remove(tmp); return strdup(""); }

    char *raw = read_file(tmp);
    remove(tmp);
    if (!raw) return strdup("");

    size_t len = strlen(raw);
    size_t cap = len + 1;
    char *clean = malloc(cap);
    if (!clean) { free(raw); return strdup(""); }

    size_t j = 0;
    int in_tag = 0, in_script = 0, in_style = 0;
    for (size_t i = 0; i < len && j < 6000; i++) {
        char c = raw[i];
        if (!in_script && !in_style && c == '<') {
            if (i + 7 < len && strncasecmp(raw + i, "<script", 7) == 0) { in_script = 1; i += 6; continue; }
            if (i + 6 < len && strncasecmp(raw + i, "<style", 6) == 0) { in_style = 1; i += 5; continue; }
            in_tag = 1;
            continue;
        }
        if (in_script && i + 8 < len && strncasecmp(raw + i, "</script", 8) == 0) { in_script = 0; i += 7; continue; }
        if (in_style && i + 7 < len && strncasecmp(raw + i, "</style", 7) == 0) { in_style = 0; i += 6; continue; }
        if (in_tag) {
            if (c == '>') in_tag = 0;
            continue;
        }
        if (in_script || in_style) continue;
        if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
            if (j > 0 && clean[j-1] != ' ') clean[j++] = ' ';
        } else {
            clean[j++] = c;
        }
    }
    clean[j] = '\0';
    free(raw);
    return clean;
}

static char *call_gemini(const char *prompt) {
        const char *key = getenv("GEMINI_API_KEY");
    if (!key || !*key) { fprintf(stderr, "[gemini] NO KEY\n"); return NULL; }

    size_t prompt_len = strlen(prompt);
    size_t esc_cap = prompt_len * 2 + 16;
    char *prompt_esc = malloc(esc_cap);
    if (!prompt_esc) return NULL;
    json_escape(prompt, prompt_esc, esc_cap);

    size_t body_cap = strlen(prompt_esc) + 1024;
    char *body = malloc(body_cap);
    if (!body) { free(prompt_esc); return NULL; }
    snprintf(body, body_cap,
        "{\"contents\":[{\"parts\":[{\"text\":\"%s\"}]}],"
        "\"generationConfig\":{\"temperature\":0.7,\"maxOutputTokens\":8192}}",
        prompt_esc);
    free(prompt_esc);

    char bodyfile[] = "gemini_body_XXXXXX";
    int bfd = mkstemp(bodyfile);
    if (bfd < 0) { free(body); return NULL; }
    FILE *bf = fdopen(bfd, "wb");
    if (!bf) { close(bfd); remove(bodyfile); free(body); return NULL; }
    fputs(body, bf);
    fclose(bf);
    free(body);

    char respfile[] = "gemini_resp_XXXXXX";
    int rfd = mkstemp(respfile);
    if (rfd < 0) { remove(bodyfile); return NULL; }
    close(rfd);

    char url[1024];
    snprintf(url, sizeof(url),
        "https://generativelanguage.googleapis.com/v1beta/models/%s:generateContent?key=%s",
        GEMINI_MODEL, key);

    char cmd[8192];
    snprintf(cmd, sizeof(cmd),
        "curl -sf --max-time 180 -X POST "
        "-H \"Content-Type: application/json\" "
        "-d @\"%s\" -o \"%s\" \"%s\" 2>nul",
        bodyfile, respfile, url);

    int rc = system(cmd);
    remove(bodyfile);
        if (rc != 0) { fprintf(stderr, "[gemini] curl rc=%d\n", rc); remove(respfile); return NULL; }

    char *resp = read_file(respfile);
    remove(respfile);
    if (!resp) return NULL;

        const char *p = strstr(resp, "\"text\":");
    if (!p) { fprintf(stderr, "[gemini] no text: %.300s\n", resp); free(resp); return NULL; }
    p += 7;
    while (*p == ' ') p++;
    if (*p != '"') { free(resp); return NULL; }
    p++;

    size_t cap = strlen(p) + 1;
    char *out = malloc(cap);
    if (!out) { free(resp); return NULL; }
    size_t j = 0;
    while (*p && j < cap - 1) {
        if (*p == '\\' && *(p+1)) {
            p++;
            if (*p == 'n') out[j++] = '\n';
            else if (*p == 't') out[j++] = '\t';
            else if (*p == '"') out[j++] = '"';
            else if (*p == '\\') out[j++] = '\\';
            else if (*p == '/') out[j++] = '/';
            else if (*p == 'u') {
                if (j + 1 < cap) { out[j++] = '?'; }
                p += 4;
            } else out[j++] = *p;
            p++;
        } else if (*p == '"') {
            break;
        } else {
            out[j++] = *p++;
        }
    }
    out[j] = '\0';
    free(resp);
    return out;
}

static char *inject_toc(const char *md) {
    if (!md) return NULL;
    if (strstr(md, "## Table of Contents")) return strdup(md);

    char toc[8192] = "## Table of Contents\n";
    const char *p = md;
    int found = 0;
    while ((p = strstr(p, "\n## ")) != NULL) {
        p += 4;
        const char *e = strchr(p, '\n');
        if (!e) e = p + strlen(p);
        size_t l = e - p;
        if (l > 0 && l < 200) {
            char heading[256];
            memcpy(heading, p, l);
            heading[l] = '\0';
            char slug[256];
            slug_from(heading, slug, sizeof(slug));
            char line[512];
            snprintf(line, sizeof(line), "- [%s](#%s)\n", heading, slug);
            strncat(toc, line, sizeof(toc) - strlen(toc) - 1);
            found = 1;
        }
        p = e;
    }
    if (!found) return strdup(md);

    const char *first_h2 = strstr(md, "\n## ");
    if (!first_h2) return strdup(md);
    size_t prefix_len = first_h2 - md + 1;
    size_t total = prefix_len + strlen(toc) + 2 + strlen(first_h2 + 1) + 1;
    char *out = malloc(total);
    if (!out) return strdup(md);
    memcpy(out, md, prefix_len);
    out[prefix_len] = '\0';
    strcat(out, toc);
    strcat(out, "\n");
    strcat(out, first_h2 + 1);
    return out;
}

static int validate_article(const char *md, const char **required_urls, int url_count) {
    if (!md) return 0;
    if (strncmp(md, "---", 3) != 0) { printf("  [FAIL] missing frontmatter\n"); return 0; }
    if (!strstr(md, "layout: themes-detil.cax")) { printf("  [FAIL] missing layout\n"); return 0; }
    if (!strstr(md, "title:")) { printf("  [FAIL] missing title\n"); return 0; }
    if (!strstr(md, "description:")) { printf("  [FAIL] missing description\n"); return 0; }
    if (!strstr(md, "features:")) { printf("  [FAIL] missing features\n"); return 0; }
    if (!strstr(md, "download:")) { printf("  [FAIL] missing download\n"); return 0; }
    if (!strstr(md, "tags:")) { printf("  [FAIL] missing tags\n"); return 0; }
    for (int i = 0; i < url_count; i++) {
        if (!strstr(md, required_urls[i])) {
            printf("  [FAIL] missing link: %s\n", required_urls[i]);
            return 0;
        }
    }
    for (int i = 0; i < FORBIDDEN_COUNT; i++) {
        if (ci_contains(md, FORBIDDEN[i])) {
            printf("  [FAIL] forbidden phrase: %s\n", FORBIDDEN[i]);
            return 0;
        }
    }
    return 1;
}

static char *build_prompt_comparison(Theme *a, Theme *b, const char *aText, const char *aDemo, const char *bText, const char *bDemo) {
    size_t cap = 32768;
    char *p = malloc(cap);
    if (!p) return NULL;
    int n = snprintf(p, cap,
        "Generate a comparison page for a premium theme shop. Output ONLY markdown. No explanation.\n\n"
        "THEME A:\ntitle: %s\ndescription: %s\nimage: %s\nprice: %s\nurl: %s\ndemo: %s\nraw tags: ",
        a->title, a->description, a->image, a->price, a->url, a->demo);
    for (int i = 0; i < a->tag_count && (size_t)n < cap - 128; i++) {
        n += snprintf(p + n, cap - n, "%s%s", a->tags[i], (i < a->tag_count - 1) ? ", " : "");
    }
    n += snprintf(p + n, cap - n,
        "\n\nTHEME B:\ntitle: %s\ndescription: %s\nimage: %s\nprice: %s\nurl: %s\ndemo: %s\nraw tags: ",
        b->title, b->description, b->image, b->price, b->url, b->demo);
    for (int i = 0; i < b->tag_count && (size_t)n < cap - 128; i++) {
        n += snprintf(p + n, cap - n, "%s%s", b->tags[i], (i < b->tag_count - 1) ? ", " : "");
    }
    snprintf(p + n, cap - n,
        "\n\nA TEXT: %.2000s\nA DEMO: %.1000s\nB TEXT: %.2000s\nB DEMO: %.1000s\n\n"
        "OUTPUT FORMAT (must match exactly):\n"
        "---\n"
        "layout: themes-detil.cax\n"
        "title: %s vs %s - Which Is Better?\n"
        "description: <120-160 chars comparison summary>\n"
        "image: %s\n"
        "features:\n"
        "  - <feature 1>\n"
        "  - <feature 2>\n"
        "  - <feature 3>\n"
        "  - <feature 4>\n"
        "  - <feature 5>\n"
        "download: %s\n"
        "demo: %s\n"
        "tags:\n"
        "  - <tag 1>\n"
        "  - <tag 2>\n"
        "  - <tag 3>\n"
        "  - <tag 4>\n"
        "  - <tag 5>\n"
        "  - <tag 6>\n"
        "  - <tag 7>\n"
        "  - <tag 8>\n"
        "---\n\n"
        "### %s vs %s\n\n"
        "<3-4 sentences comparing both themes, based on data only.>\n\n"
        "RULES:\n"
        "- FEATURES: 5-7 comparison points.\n"
        "- TAGS: 8-10 SEO tags covering both stacks + 'comparison' + 'premiumthemes'.\n"
        "- BODY: 3-4 sentences only. MUST link to %s and %s.\n"
        "- Output ONLY the markdown. No code fences, no explanation.",
        aText, aDemo, bText, bDemo,
        a->title, b->title, a->image,
        a->url, a->demo,
        a->title, b->title,
        a->url, b->url);
    return p;
}

static char *build_prompt_review(Theme *t, const char *text, const char *demo) {
    size_t cap = 32768;
    char *p = malloc(cap);
    if (!p) return NULL;
    int n = snprintf(p, cap,
        "Generate a theme detail page for a premium theme shop. Output ONLY markdown. No explanation.\n\n"
        "THEME DATA:\n"
        "title: %s\n"
        "description: %s\n"
        "image: %s\n"
        "price: %s\n"
        "url: %s\n"
        "demo: %s\n"
        "raw tags: ",
        t->title, t->description, t->image, t->price, t->url, t->demo);
    for (int i = 0; i < t->tag_count && (size_t)n < cap - 128; i++) {
        n += snprintf(p + n, cap - n, "%s%s", t->tags[i], (i < t->tag_count - 1) ? ", " : "");
    }
    snprintf(p + n, cap - n,
        "\n\nPAGE TEXT (context only): %.3000s\nDEMO TEXT (context only): %.1500s\n\n"
        "OUTPUT FORMAT (must match exactly):\n"
        "---\n"
        "layout: themes-detil.cax\n"
        "title: %s\n"
        "description: %s\n"
        "image: %s\n"
        "features:\n"
        "  - <feature 1>\n"
        "  - <feature 2>\n"
        "  - <feature 3>\n"
        "  - <feature 4>\n"
        "  - <feature 5>\n"
        "download: %s\n"
        "demo: %s\n"
        "tags:\n"
        "  - <tag 1>\n"
        "  - <tag 2>\n"
        "  - <tag 3>\n"
        "  - <tag 4>\n"
        "  - <tag 5>\n"
        "  - <tag 6>\n"
        "  - <tag 7>\n"
        "  - <tag 8>\n"
        "---\n\n"
        "### <short title>\n\n"
        "<2-3 sentences describing the theme, based on data only. No fluff.>\n\n"
        "RULES:\n"
        "- FEATURES: 5-7 descriptive lines. Convert raw tags into readable features. "
        "Example: 'bludit' → 'Bludit Flat-File CMS', 'dark mode' → 'Dark Mode + Modern'. "
        "Do NOT copy raw tags verbatim.\n"
        "- TAGS: 8-10 SEO-relevant tags. Include: stack tag, category tags, type tags "
        "(e.g. 'bluditthemes', 'premiumthemes'), descriptive tags. "
        "Do NOT include generic tags like 'website' or 'template' alone.\n"
        "- BODY: 2-3 sentences only. Based on data only. Do NOT invent features.\n"
        "- download MUST be %s (the theme page URL, not Gumroad).\n"
        "- Output ONLY the markdown. No code fences, no explanation.",
        text, demo,
        t->title, t->description, t->image,
        t->url, t->demo,
        t->url);
    return p;
}

static char *build_prompt_trend(const char *topic, Theme **themes, int count, const char *image) {
    size_t cap = 32768;
    char *p = malloc(cap);
    if (!p) return NULL;
    int n = snprintf(p, cap,
        "Generate a trend article for a premium theme shop. Output ONLY markdown. No explanation.\n\n"
        "TRENDING TOPIC: %s\n\n"
        "OUR PREMIUM THEMES:\n", topic);
    for (int i = 0; i < count && (size_t)n < cap - 512; i++) {
        n += snprintf(p + n, cap - n,
            "- %s | url: %s | demo: %s | desc: %s\n",
            themes[i]->title, themes[i]->url, themes[i]->demo, themes[i]->description);
    }
    snprintf(p + n, cap - n,
        "\nOUTPUT FORMAT (must match exactly):\n"
        "---\n"
        "layout: themes-detil.cax\n"
        "title: <trend keyword> - Premium Themes That Fit\n"
        "description: <120-160 chars>\n"
        "image: %s\n"
        "features:\n"
        "  - <feature 1>\n"
        "  - <feature 2>\n"
        "  - <feature 3>\n"
        "  - <feature 4>\n"
        "  - <feature 5>\n"
        "download: %s\n"
        "demo: %s\n"
        "tags:\n"
        "  - <tag 1>\n"
        "  - <tag 2>\n"
        "  - <tag 3>\n"
        "  - <tag 4>\n"
        "  - <tag 5>\n"
        "  - <tag 6>\n"
        "  - <tag 7>\n"
        "  - <tag 8>\n"
        "---\n\n"
        "### <trend title>\n\n"
        "<3-4 sentences about why this trend matters and which of our themes fit.>\n\n"
        "RULES:\n"
        "- FOCUS ON OUR PREMIUM THEMES, not the trend itself.\n"
        "- FEATURES: 5-7 points about our themes that fit the trend.\n"
        "- TAGS: 8-10 tags including trend keyword + 'premiumthemes'.\n"
        "- BODY: 3-4 sentences only. MUST link to each theme URL.\n"
        "- Output ONLY the markdown. No code fences, no explanation.",
                image, themes[0]->url, themes[0]->demo);
    return p;
}

static int state_contains(const char *content, const char *value) {
    return content && strstr(content, value) != NULL;
}

static int save_state(const char *key, const char *value) {
    char *content = read_file(STATE_FILE);
    char buf[32768];
    int n = 0;

    if (!content) {
        n = snprintf(buf, sizeof(buf), "{\n  \"%s\": [\"%s\"]\n}\n", key, value);
        return write_file(STATE_FILE, buf);
    }

    const char *keypos = strstr(content, key);
    if (!keypos) {
        size_t clen = strlen(content);
        if (clen > 0 && content[clen-1] == '}') {
            n = snprintf(buf, sizeof(buf), "%.*s,\n  \"%s\": [\"%s\"]\n}\n",
                (int)(clen - 2), content, key, value);
        } else {
            n = snprintf(buf, sizeof(buf), "%s", content);
        }
        free(content);
        return write_file(STATE_FILE, buf);
    }

    const char *open = strchr(keypos, '[');
    const char *close = open ? strchr(open, ']') : NULL;
    if (!open || !close) { free(content); return 0; }

    size_t prefix = open - content + 1;
    const char *inner = open + 1;
    size_t inner_len = close - inner;
    int empty = 1;
    for (size_t i = 0; i < inner_len; i++) {
        if (!isspace((unsigned char)inner[i])) { empty = 0; break; }
    }

    if (prefix + inner_len + strlen(value) + 32 >= sizeof(buf)) { free(content); return 0; }

    memcpy(buf, content, prefix);
    buf[prefix] = '\0';
    n = prefix;

    if (empty) {
        n += snprintf(buf + n, sizeof(buf) - n, "\"%s\"", value);
    } else {
        n += snprintf(buf + n, sizeof(buf) - n, "\"%s\",%.*s", value, (int)inner_len, inner);
    }

    size_t remaining = strlen(close);
    if (n + remaining + 1 < sizeof(buf)) {
        memcpy(buf + n, close, remaining + 1);
    }

    free(content);
    return write_file(STATE_FILE, buf);
}

static int already_done(const char *key, const char *value) {
    char *content = read_file(STATE_FILE);
    if (!content) return 0;
    const char *p = strstr(content, key);
    if (!p) { free(content); return 0; }
    const char *open = strchr(p, '[');
    const char *close = open ? strchr(open, ']') : NULL;
    if (!open || !close) { free(content); return 0; }
    char inner[8192];
    size_t il = close - open - 1;
    if (il >= sizeof(inner)) il = sizeof(inner) - 1;
    memcpy(inner, open + 1, il);
    inner[il] = '\0';
    int found = strstr(inner, value) != NULL;
    free(content);
    return found;
}

static int get_task_for_today(void) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    int d = tm->tm_wday;
    if (d == 1 || d == 4) return 1;
    if (d == 2 || d == 5) return 2;
    if (d == 3 || d == 6) return 3;
    return 0;
}

static char *extract_hn_titles(const char *json) {
    if (!json) return NULL;
    const char *p = json;
    char *result = malloc(16384);
    if (!result) return NULL;
    result[0] = '\0';
    while ((p = strstr(p, "\"title\":\"")) != NULL) {
        p += 9;
        const char *e = p;
        while (*e && *e != '"') { if (*e == '\\') e++; e++; }
        if (*e != '"') break;
        size_t l = e - p;
        if (l > 0 && l < 300) {
            if (strlen(result) + l + 2 < 16000) {
                strncat(result, p, l);
                strncat(result, "\n", 2);
            }
        }
        p = e + 1;
    }
    return result;
}

static int do_comparison(Theme *themes, int count) {
    Theme *premium[MAX_THEMES];
    int pcount = 0;
    for (int i = 0; i < count && pcount < MAX_THEMES; i++) {
        if (themes[i].is_premium) premium[pcount++] = &themes[i];
    }

    for (int s = 0; s < STACKS_COUNT; s++) {
        Theme *group[128];
        int gcount = 0;
        for (int i = 0; i < pcount && gcount < 128; i++) {
            if (has_tag(premium[i], STACKS[s])) group[gcount++] = premium[i];
        }
        if (gcount < 2) continue;

        for (int i = 0; i < gcount; i++) {
            for (int j = i + 1; j < gcount; j++) {
                char key[1024], revkey[1024];
                snprintf(key, sizeof(key), "%s-vs-%s", group[i]->slug, group[j]->slug);
                snprintf(revkey, sizeof(revkey), "%s-vs-%s", group[j]->slug, group[i]->slug);

                if (already_done("comparisons", key) || already_done("comparisons", revkey)) continue;

                printf("Comparison: %s vs %s\n", group[i]->title, group[j]->title);

                char urlA[1024], urlB[1024];
                snprintf(urlA, sizeof(urlA), "%s%s", SITE_BASE, group[i]->url);
                snprintf(urlB, sizeof(urlB), "%s%s", SITE_BASE, group[j]->url);

                char *aText = fetch_url_text(urlA, 15);
                char *aDemo = group[i]->demo[0] ? fetch_url_text(group[i]->demo, 15) : strdup("");
                char *bText = fetch_url_text(urlB, 15);
                char *bDemo = group[j]->demo[0] ? fetch_url_text(group[j]->demo, 15) : strdup("");

                char *prompt = build_prompt_comparison(group[i], group[j], aText, aDemo, bText, bDemo);
                if (!prompt) { free(aText); free(aDemo); free(bText); free(bDemo); continue; }

                char *md = NULL;
                                for (int attempt = 0; attempt <= MAX_RETRIES; attempt++) {
                    char *raw = call_gemini(prompt);
                    if (!raw) break;
                    const char *required[] = { group[i]->url, group[j]->url };
                    if (validate_article(raw, required, 2)) { md = raw; break; }
                    free(raw);
                }

                free(prompt);
                free(aText); free(aDemo); free(bText); free(bDemo);

                if (md) {
                    char file[512];
                    snprintf(file, sizeof(file), "%s/compare-%s.md", POSTS_DIR, key);
                    if (write_file(file, md)) {
                        printf("Written: %s\n", file);
                        save_state("comparisons", key);
                        free(md);
                        return 1;
                    }
                    free(md);
                }
            }
        }
    }
    return 0;
}

static int do_review(Theme *themes, int count) {
    for (int i = 0; i < count; i++) {
        if (!themes[i].is_premium) continue;
        if (already_done("reviews", themes[i].slug)) continue;

        printf("Review: %s\n", themes[i].title);

        char url[1024];
        snprintf(url, sizeof(url), "%s%s", SITE_BASE, themes[i].url);
        char *text = fetch_url_text(url, 15);
                char *demo = themes[i].demo[0] ? fetch_url_text(themes[i].demo, 15) : strdup("");

        char *prompt = build_prompt_review(&themes[i], text, demo);
        if (!prompt) { free(text); free(demo); continue; }

        char *md = NULL;
        for (int attempt = 0; attempt <= MAX_RETRIES; attempt++) {
            char *raw = call_gemini(prompt);
            if (!raw) break;
                        const char *required[] = { themes[i].url };
            if (validate_article(raw, required, 1)) { md = raw; break; }
            free(raw);
        }

        free(prompt);
        free(text);
        free(demo);

        if (md) {
            char file[512];
            snprintf(file, sizeof(file), "%s/review-%s.md", POSTS_DIR, themes[i].slug);
            if (write_file(file, md)) {
                printf("Written: %s\n", file);
                save_state("reviews", themes[i].slug);
                free(md);
                return 1;
            }
            free(md);
        }
    }
    return 0;
}

static int do_trend(Theme *themes, int count) {
    char tmp[] = "autoblog_hn_XXXXXX";
    int fd = mkstemp(tmp);
    if (fd < 0) return 0;
    close(fd);

    if (run_curl(HN_URL, tmp, 20, 0) != 0) { remove(tmp); return 0; }
    char *hnjson = read_file(tmp);
    remove(tmp);
    if (!hnjson) return 0;

    char *titles = extract_hn_titles(hnjson);
    free(hnjson);
    if (!titles) return 0;

    Theme *premium[MAX_THEMES];
    int pcount = 0;
    for (int i = 0; i < count && pcount < MAX_THEMES; i++) {
        if (themes[i].is_premium) premium[pcount++] = &themes[i];
    }

    char *saveptr = NULL;
    char *line = strtok_r(titles, "\n", &saveptr);
    char *fallback = NULL;

    while (line) {
        char lower[512];
        size_t ll = strlen(line);
        if (ll >= sizeof(lower)) ll = sizeof(lower) - 1;
        for (size_t k = 0; k < ll; k++) lower[k] = tolower((unsigned char)line[k]);
        lower[ll] = '\0';

        for (int s = 0; s < STACKS_COUNT; s++) {
            if (!strstr(lower, STACKS[s])) continue;

            Theme *relevant[32];
            int rcount = 0;
            for (int i = 0; i < pcount && rcount < 32; i++) {
                if (has_tag(premium[i], STACKS[s])) relevant[rcount++] = premium[i];
            }
            if (!rcount) continue;

            char statekey[256];
            snprintf(statekey, sizeof(statekey), "%s-%s", STACKS[s], line);
            if (already_done("trends", statekey)) continue;

            printf("Trend: %s (stack: %s)\n", line, STACKS[s]);

			char *prompt = build_prompt_trend(line, relevant, rcount, relevant[0]->image);
            if (!prompt) continue;

            char *md = NULL;
            for (int attempt = 0; attempt <= MAX_RETRIES; attempt++) {
                char *raw = call_gemini(prompt);
                if (!raw) break;
                const char *required[32];
                for (int r = 0; r < rcount; r++) required[r] = relevant[r]->url;
                if (validate_article(raw, required, rcount)) { md = raw; break; }
                free(raw);
            }
            free(prompt);

            if (md) {
                char slug[256];
                slug_from(line, slug, sizeof(slug));
                char file[512];
                snprintf(file, sizeof(file), "%s/trend-%s.md", POSTS_DIR, slug);
                if (write_file(file, md)) {
                    printf("Written: %s\n", file);
                    save_state("trends", statekey);
                    free(md);
                    free(titles);
                    return 1;
                }
                free(md);
            }
        }

        if (!fallback && strlen(line) > 20) {
            fallback = strdup(line);
        }
        line = strtok_r(NULL, "\n", &saveptr);
    }

    free(titles);

    if (fallback && pcount > 0) {
        printf("Trend (fallback): %s\n", fallback);

        Theme *relevant[8];
        int rcount = 0;
        for (int i = 0; i < pcount && rcount < 8; i++) {
            relevant[rcount++] = premium[i];
        }

        char statekey[512];
        snprintf(statekey, sizeof(statekey), "fallback-%s", fallback);
        if (!already_done("trends", statekey)) {
            char *prompt = build_prompt_trend(fallback, relevant, rcount, FALLBACK_IMAGE);
            if (prompt) {
                char *md = NULL;
                for (int attempt = 0; attempt <= MAX_RETRIES; attempt++) {
                    char *raw = call_gemini(prompt);
                    if (!raw) break;
                    const char *required[8];
                    for (int r = 0; r < rcount; r++) required[r] = relevant[r]->url;
                    if (validate_article(raw, required, rcount)) { md = raw; break; }
                    free(raw);
                }
                free(prompt);

                if (md) {
                    char slug[256];
                    slug_from(fallback, slug, sizeof(slug));
                    char file[512];
                    snprintf(file, sizeof(file), "%s/trend-%s.md", POSTS_DIR, slug);
                    if (write_file(file, md)) {
                        printf("Written: %s\n", file);
                        save_state("trends", statekey);
                        free(md);
                        free(fallback);
                        return 1;
                    }
                    free(md);
                }
            }
        }
        free(fallback);
    }

    return 0;
}

int cax_autoblog_run(void) {
    const char *key = getenv("GEMINI_API_KEY");
    if (!key || !*key) {
        fprintf(stderr, "[autoblog] GEMINI_API_KEY missing\n");
        return 1;
    }

    char *json = read_file(THEMES_JSON);
    if (!json) {
        fprintf(stderr, "[autoblog] cannot read %s\n", THEMES_JSON);
        return 1;
    }

    Theme *themes = calloc(MAX_THEMES, sizeof(Theme));
    if (!themes) { free(json); return 1; }

    int count = parse_themes(json, themes, MAX_THEMES);
    free(json);

    if (count == 0) {
        fprintf(stderr, "[autoblog] no themes parsed\n");
        free(themes);
        return 1;
    }

    printf("[autoblog] %d themes loaded\n", count);

    int task = get_task_for_today();
    int ok = 0;

    if (task == 1) ok = do_comparison(themes, count);
    else if (task == 2) ok = do_review(themes, count);
    else if (task == 3) ok = do_trend(themes, count);
    else printf("[autoblog] rest day\n");

    if (!ok) printf("[autoblog] nothing generated\n");

    free(themes);
    return ok ? 0 : 1;
}
