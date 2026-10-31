#include "chat_json.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>

#define CHAT_MAX_TAGS 64
#define CHAT_MAX_TAG_LEN 128

typedef struct {
    char title[512];
    char description[2048];
    char slug[256];
    char image[512];
    char price[64];
    char download[512];
    char demo[512];
    char tags[CHAT_MAX_TAGS][CHAT_MAX_TAG_LEN];
    int tag_count;
    int has_collection;
} ChatTheme;

static int ci_equal(const char *a, const char *b) {
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) return 0;
        a++; b++;
    }
    return *a == *b;
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

static char *trim(char *s) {
    while (*s && isspace((unsigned char)*s)) s++;
    if (!*s) return s;
    char *e = s + strlen(s) - 1;
    while (e > s && isspace((unsigned char)*e)) e--;
    e[1] = '\0';
    return s;
}

static int parse_theme_file(const char *path, ChatTheme *t) {
    FILE *f = fopen(path, "r");
    if (!f) return 0;
    memset(t, 0, sizeof(*t));

    char line[4096];
    int fm_done = 0;
    int in_tags = 0;

    if (!fgets(line, sizeof(line), f)) { fclose(f); return 0; }
    char *l = trim(line);
    if (strcmp(l, "---") != 0) { fclose(f); return 0; }

    while (fgets(line, sizeof(line), f)) {
        l = trim(line);
        if (!*l) continue;
        if (strcmp(l, "---") == 0) { fm_done = 1; break; }

        if (l[0] == '-' && in_tags) {
            char *v = trim(l + 1);
            if ((v[0] == '"' && v[strlen(v)-1] == '"') ||
                (v[0] == '\'' && v[strlen(v)-1] == '\'')) {
                v[strlen(v)-1] = '\0'; v++;
            }
            if (t->tag_count < CHAT_MAX_TAGS && *v) {
                strncpy(t->tags[t->tag_count], v, CHAT_MAX_TAG_LEN - 1);
                t->tags[t->tag_count][CHAT_MAX_TAG_LEN - 1] = '\0';
                t->tag_count++;
            }
            continue;
        }

        char *colon = strchr(l, ':');
        if (!colon) { in_tags = 0; continue; }
        *colon = '\0';
        char *key = trim(l);
        char *val = trim(colon + 1);

        if ((val[0] == '"' && val[strlen(val)-1] == '"') ||
            (val[0] == '\'' && val[strlen(val)-1] == '\'')) {
            val[strlen(val)-1] = '\0'; val++;
        }

        if (ci_equal(key, "title")) {
            strncpy(t->title, val, sizeof(t->title) - 1);
        } else if (ci_equal(key, "description")) {
            strncpy(t->description, val, sizeof(t->description) - 1);
        } else if (ci_equal(key, "price")) {
            strncpy(t->price, val, sizeof(t->price) - 1);
        } else if (ci_equal(key, "image")) {
            strncpy(t->image, val, sizeof(t->image) - 1);
        } else if (ci_equal(key, "download")) {
            strncpy(t->download, val, sizeof(t->download) - 1);
        } else if (ci_equal(key, "demo")) {
            strncpy(t->demo, val, sizeof(t->demo) - 1);
        } else if (ci_equal(key, "collection")) {
            t->has_collection = 1;
        } else if (ci_equal(key, "tags")) {
            in_tags = 1;
            if (val[0] == '[') {
                char *p = val + 1;
                char *end = strchr(p, ']');
                if (end) *end = '\0';
                char *tok = strtok(p, ",");
                while (tok && t->tag_count < CHAT_MAX_TAGS) {
                    tok = trim(tok);
                    if ((tok[0] == '"' && tok[strlen(tok)-1] == '"') ||
                        (tok[0] == '\'' && tok[strlen(tok)-1] == '\'')) {
                        tok[strlen(tok)-1] = '\0'; tok++;
                    }
                    if (*tok) {
                        strncpy(t->tags[t->tag_count], tok, CHAT_MAX_TAG_LEN - 1);
                        t->tag_count++;
                    }
                    tok = strtok(NULL, ",");
                }
                in_tags = 0;
            }
        }
    }
    fclose(f);
    return fm_done;
}

static void slug_from_filename(const char *name, char *out, size_t out_size) {
    size_t j = 0;
    for (size_t i = 0; name[i] && j < out_size - 1; i++) {
        if (name[i] == '.') break;
        out[j++] = name[i];
    }
    out[j] = '\0';
}

static int is_premium_tag(const char *tag) {
    if (ci_equal(tag, "premium")) return 1;
    if (ci_equal(tag, "premiumthemes")) return 1;
    if (ci_equal(tag, "featuredpremium")) return 1;
    if (ci_equal(tag, "premium-themes")) return 1;
    return 0;
}

static int is_free_tag(const char *tag) {
    if (ci_equal(tag, "free")) return 1;
    if (ci_equal(tag, "freethemes")) return 1;
    if (ci_equal(tag, "featuredfree")) return 1;
    return 0;
}

static void clean_price(const char *in, char *out, size_t out_size) {
    if (!in || !*in) { strncpy(out, "0", out_size); return; }
    size_t j = 0;
    for (size_t i = 0; in[i] && j < out_size - 1; i++) {
        if (isdigit((unsigned char)in[i]) || in[i] == '.') {
            out[j++] = in[i];
        }
    }
    out[j] = '\0';
    if (j == 0) strncpy(out, "0", out_size);
}

static void scan_dir_recursive(const char *dir_path, FILE *out, int *first, int *count) {
    DIR *d = opendir(dir_path);
    if (!d) return;

    struct dirent *e;
    while ((e = readdir(d)) != NULL) {
        if (e->d_name[0] == '.') continue;
        char path[4096];
        snprintf(path, sizeof(path), "%s/%s", dir_path, e->d_name);

        struct stat st;
        if (stat(path, &st) != 0) continue;

        if (S_ISDIR(st.st_mode)) {
            scan_dir_recursive(path, out, first, count);
            continue;
        }

        const char *ext = strrchr(e->d_name, '.');
        if (!ext || strcmp(ext, ".md") != 0) continue;

        ChatTheme t;
        if (!parse_theme_file(path, &t)) continue;
        if (t.has_collection) continue;
        if (!t.title[0]) {
            slug_from_filename(e->d_name, t.title, sizeof(t.title));
        }

        slug_from_filename(e->d_name, t.slug, sizeof(t.slug));

        int is_premium = 0, is_free = 0;
        for (int i = 0; i < t.tag_count; i++) {
            if (is_premium_tag(t.tags[i])) is_premium = 1;
            if (is_free_tag(t.tags[i])) is_free = 1;
        }
        if (!is_premium && !is_free) {
            if (t.download[0] && strstr(t.download, "gumroad.com")) is_premium = 1;
            else if (t.price[0] && strcmp(t.price, "0") != 0) is_premium = 1;
            else is_free = 1;
        }

        char url[512];
        snprintf(url, sizeof(url), "/themes/stack/%s/", t.slug);

        char price_clean[64];
        clean_price(t.price, price_clean, sizeof(price_clean));

        char esc_title[1024], esc_desc[4096], esc_slug[512], esc_url[1024], esc_img[1024], esc_demo[1024];
        json_escape(t.title, esc_title, sizeof(esc_title));
        json_escape(t.description, esc_desc, sizeof(esc_desc));
        json_escape(t.slug, esc_slug, sizeof(esc_slug));
        json_escape(url, esc_url, sizeof(esc_url));
        json_escape(t.image, esc_img, sizeof(esc_img));
        json_escape(t.demo, esc_demo, sizeof(esc_demo));

        if (!*first) fprintf(out, ",\n");
        *first = 0;

        fprintf(out,
            "  {\"title\":\"%s\",\"slug\":\"%s\",\"url\":\"%s\",\"image\":\"%s\","
            "\"demo\":\"%s\","
            "\"description\":\"%s\",\"price\":\"%s\",\"is_premium\":%s,\"is_free\":%s,\"tags\":[",
            esc_title, esc_slug, esc_url, esc_img, esc_demo, esc_desc,
            price_clean,
            is_premium ? "true" : "false",
            is_free ? "true" : "false");

        for (int i = 0; i < t.tag_count; i++) {
            char esc_tag[256];
            json_escape(t.tags[i], esc_tag, sizeof(esc_tag));
            fprintf(out, "%s\"%s\"", (i == 0 ? "" : ","), esc_tag);
        }
        fprintf(out, "]}");
        (*count)++;
    }
    closedir(d);
}

int cax_chat_generate_index(const char *themes_dir, const char *out_file) {
    DIR *d = opendir(themes_dir);
    if (!d) {
        fprintf(stderr, "[chat-index] folder tidak ditemukan: %s\n", themes_dir);
        return 1;
    }
    closedir(d);

    FILE *out = fopen(out_file, "w");
    if (!out) {
        fprintf(stderr, "[chat-index] gagal tulis: %s\n", out_file);
        return 1;
    }

    fprintf(out, "[\n");
    int first = 1, count = 0;
    scan_dir_recursive(themes_dir, out, &first, &count);
    fprintf(out, "\n]\n");
    fclose(out);

    printf(" [chat-index] %d themes -> %s\n", count, out_file);
    return 0;
}