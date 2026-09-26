#include "markdown.h"
#include "../utils/string_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOC 256
#define MAX_FOOTNOTES 128

typedef struct { int level; char text[512]; char id[256]; } TocItem;
typedef struct { char label[64]; char text[1024]; } Footnote;

static void slugify(const char *in, char *out, size_t out_size){
    size_t j=0;
    for(size_t i=0; i<strlen(in) && j<out_size-1; i++){
        char c = tolower((unsigned char)in[i]);
        if(isalnum((unsigned char)c)) out[j++]=c;
        else if(c==' ' || c=='-' || c=='_' || c=='.'){ if(j>0 && out[j-1]!='-') out[j++]='-'; }
    }
    while(j>0 && out[j-1]=='-') j--;
    out[j]='\0';
    if(j==0) snprintf(out, out_size, "section-%d", rand()%10000);
}

char *cax_markdown_generate_toc(const char *md) {
    if (!md) return cax_strdup("");
    TocItem toc[MAX_TOC];
    int tc = 0;
    char *copy = cax_strdup(md);
    char *saveptr;
    char *line = strtok_r(copy, "\n", &saveptr);

    while (line && tc < MAX_TOC) {
        char *p = line;
        while (*p == ' ' || *p == '\t') p++;
        if (*p!= '#') { line = strtok_r(NULL, "\n", &saveptr); continue; }

        int lvl = 0;
        while (p[lvl] == '#') lvl++;
        if (lvl < 2 || lvl > 6) { line = strtok_r(NULL, "\n", &saveptr); continue; }
        if (p[lvl]!= ' ' && p[lvl]!= '\t') { line = strtok_r(NULL, "\n", &saveptr); continue; }

        char *txt = p + lvl + 1;
        while (*txt == ' ' || *txt == '\t') txt++;

        // STRIP markdown biar gak jadi []()
        char clean[512] = {0};
        size_t k=0;
        for(size_t i=0; txt[i] && k<511; i++){
            char c = txt[i];
            if(c=='\r' || c=='\n') continue;
            if(c=='*' || c=='_' || c=='`' || c=='~' || c=='[' || c==']' || c=='(' || c==')' || c=='!') continue;
            clean[k++]=c;
        }
        clean[k]='\0';
        // trim
        char *s = clean; while(*s==' '||*s=='\t') s++;
        size_t L = strlen(s);
        while(L>0 && (s[L-1]==' '||s[L-1]=='\t')) s[--L]='\0';
        if(L==0){ line = strtok_r(NULL, "\n", &saveptr); continue; }

        toc[tc].level = lvl;
        snprintf(toc[tc].text, sizeof(toc[tc].text), "%s", s);
        toc[tc].text[511]='\0';
        slugify(s, toc[tc].id, sizeof(toc[tc].id));
        if(toc[tc].id[0]=='\0') snprintf(toc[tc].id, sizeof(toc[tc].id), "sec-%d", tc);
        tc++;
        line = strtok_r(NULL, "\n", &saveptr);
    }
    free(copy);
    if (tc==0) return cax_strdup("");

    char *out = malloc(16384);
    size_t o=0;
    o+=snprintf(out+o, 16384-o, "<ul class=\"toc\">\n");
    int cur = toc[0].level;
    o+=snprintf(out+o, 16384-o, "<li class=\"toc-h%d\"><a href=\"#%s\">%s</a></li>\n", toc[0].level, toc[0].id, toc[0].text);
    for(int i=1;i<tc;i++){
        int lvl=toc[i].level;
        while(cur<lvl){ o+=snprintf(out+o, 16384-o, "<ul>\n"); cur++; }
        while(cur>lvl){ o+=snprintf(out+o, 16384-o, "</ul>\n"); cur--; }
        o+=snprintf(out+o, 16384-o, "<li class=\"toc-h%d\"><a href=\"#%s\">%s</a></li>\n", lvl, toc[i].id, toc[i].text);
    }
    while(cur>=toc[0].level){ o+=snprintf(out+o, 16384-o, "</ul>\n"); cur--; }
    return out;
}

static void parse_inline_formatting(const char *input, char *output, size_t out_size) {
    size_t in_len = strlen(input);
    size_t out_idx = 0;
    size_t i = 0;
    while (i < in_len && out_idx < out_size - 1) {
        if (input[i] == '`') {
            const char *end = strchr(input + i + 1, '`');
            if (end) {
                size_t len = end - (input + i + 1);
                out_idx += snprintf(output + out_idx, out_size - out_idx, "<code>%.*s</code>", (int)len, input + i + 1);
                i = (end - input) + 1; continue;
            }
        }
        if (input[i] == '!' && i + 1 < in_len && input[i + 1] == '[') {
            const char *close_bracket = strchr(input + i + 2, ']');
            if (close_bracket && *(close_bracket + 1) == '(') {
                const char *close_paren = strchr(close_bracket + 2, ')');
                if (close_paren) {
                    size_t alt_len = close_bracket - (input + i + 2);
                    size_t src_len = close_paren - (close_bracket + 2);
                    out_idx += snprintf(output + out_idx, out_size - out_idx,
                                        "<img src=\"%.*s\" alt=\"%.*s\" loading=\"lazy\" />",
                                        (int)src_len, close_bracket + 2,
                                        (int)alt_len, input + i + 2);
                    i = (close_paren - input) + 1; continue;
                }
            }
        }
        if (input[i] == '[') {
            if(i+1<in_len && input[i+1]=='^'){
                const char *close = strchr(input+i+2, ']');
                if(close){
                    size_t ll = close - (input+i+2);
                    out_idx += snprintf(output + out_idx, out_size - out_idx,
                        "<sup id=\"fnref:%.*s\"><a href=\"#fn:%.*s\">%.*s</a></sup>",
                        (int)ll, input+i+2, (int)ll, input+i+2, (int)ll, input+i+2);
                    i = (close - input)+1; continue;
                }
            }
            const char *close_bracket = strchr(input + i + 1, ']');
            if (close_bracket && *(close_bracket + 1) == '(') {
                const char *close_paren = strchr(close_bracket + 2, ')');
                if (close_paren) {
                    size_t text_len = close_bracket - (input + i + 1);
                    size_t url_len = close_paren - (close_bracket + 2);
                    char text_buf[512] = {0};
                    snprintf(text_buf, sizeof(text_buf), "%.*s", (int)text_len, input + i + 1);
                    char parsed_text[1024] = {0};
                    parse_inline_formatting(text_buf, parsed_text, sizeof(parsed_text));
                    out_idx += snprintf(output + out_idx, out_size - out_idx,
                                        "<a href=\"%.*s\">%s</a>",
                                        (int)url_len, close_bracket + 2, parsed_text);
                    i = (close_paren - input) + 1; continue;
                }
            }
        }
        if (i + 1 < in_len && input[i] == '*' && input[i + 1] == '*') {
            const char *end = strstr(input + i + 2, "**");
            if (end) {
                size_t len = end - (input + i + 2);
                char inner[1024]={0}; snprintf(inner, sizeof(inner), "%.*s", (int)len, input+i+2);
                char parsed[1024]={0}; parse_inline_formatting(inner, parsed, sizeof(parsed));
                out_idx += snprintf(output + out_idx, out_size - out_idx, "<strong>%s</strong>", parsed);
                i = (end - input) + 2; continue;
            }
        }
        if (i + 1 < in_len && input[i] == '~' && input[i + 1] == '~') {
            const char *end = strstr(input + i + 2, "~~");
            if (end) {
                size_t len = end - (input + i + 2);
                out_idx += snprintf(output + out_idx, out_size - out_idx, "<del>%.*s</del>", (int)len, input + i + 2);
                i = (end - input) + 2; continue;
            }
        }
        if (input[i] == '*' || input[i] == '_') {
            char target = input[i];
            const char *end = strchr(input + i + 1, target);
            if (end && (end == input + i + 1 || *(end - 1)!= target)) {
                size_t len = end - (input + i + 1);
                char inner[1024]={0}; snprintf(inner, sizeof(inner), "%.*s", (int)len, input+i+1);
                char parsed[1024]={0}; parse_inline_formatting(inner, parsed, sizeof(parsed));
                out_idx += snprintf(output + out_idx, out_size - out_idx, "<em>%s</em>", parsed);
                i = (end - input) + 1; continue;
            }
        }
        output[out_idx++] = input[i++];
    }
    output[out_idx] = '\0';
}

static void render_table_row(const char *line, char *output, size_t out_size, const char *tag) {
    char temp[4096]; strncpy(temp, line, sizeof(temp) - 1); temp[sizeof(temp) - 1] = '\0';
    snprintf(output, out_size, "<tr>");
    char *save; char *token = strtok_r(temp, "|", &save);
    while (token) {
        while (isspace((unsigned char)*token)) token++;
        char *end = token + strlen(token) - 1;
        while (end > token && isspace((unsigned char)*end)) { *end = '\0'; end--; }
        if (strlen(token) > 0) {
            char cell_out[2048]; parse_inline_formatting(token, cell_out, sizeof(cell_out));
            char cell_buf[4096]; snprintf(cell_buf, sizeof(cell_buf), "<%s>%s</%s>", tag, cell_out, tag);
            strncat(output, cell_buf, out_size - strlen(output) - 1);
        }
        token = strtok_r(NULL, "|", &save);
    }
    strncat(output, "</tr>\n", out_size - strlen(output) - 1);
}

static int is_table_divider(const char *line) {
    if (!strchr(line, '|')) return 0;
    for (size_t i = 0; line[i]!= '\0'; i++) {
        if (line[i]!= '|' && line[i]!= '-' && line[i]!= ':' &&!isspace((unsigned char)line[i])) return 0;
    }
    return 1;
}

char *cax_markdown_to_html(const char *md_content) {
    if (!md_content) return NULL;
    size_t buf_size = strlen(md_content) * 6 + 8192;
    char *html_output = malloc(buf_size); if (!html_output) return NULL; html_output[0] = '\0';
    char *work_copy = cax_strdup(md_content); if (!work_copy) { free(html_output); return NULL; }

    Footnote fns[MAX_FOOTNOTES]; int fc=0;
    char *filtered[8192]; int fbl=0;
    char *save; char *line = strtok_r(work_copy, "\n", &save);
    while(line && fbl<8192){
        char *t=line; while(*t==' '||*t=='\t') t++;
        if(strncmp(t, "[^", 2)==0){
            char *c=strstr(t, "]:");
                        if(c){
                char lab[64]={0};
                size_t ll=c-(t+2);
                if(ll>63) ll=63;
                snprintf(lab, sizeof(lab), "%.*s", (int)ll, t+2);
                char *txt=c+2; while(*txt==' ') txt++;
                snprintf(fns[fc].label, sizeof(fns[fc].label), "%s", lab);
                snprintf(fns[fc].text, sizeof(fns[fc].text), "%s", txt);
                fc++; if(fc>=MAX_FOOTNOTES) fc=MAX_FOOTNOTES-1;
            }
        } else { filtered[fbl++]=cax_strdup(line); }
        line=strtok_r(NULL, "\n", &save);
    }
    free(work_copy);

    int in_ul = 0, in_ol = 0, in_table = 0, in_code = 0, in_bq = 0;
    for(int idx=0; idx<fbl; idx++){
        char *line_start = filtered[idx];
        size_t line_len = strlen(line_start);
        if (line_len > 0 && line_start[line_len - 1] == '\r') line_start[line_len - 1] = '\0';

        if (strncmp(line_start, "```", 3) == 0) {
            if (in_code) { strncat(html_output, "</code></pre>\n", buf_size - strlen(html_output) - 1); in_code = 0; }
            else {
                if (in_ul) { strncat(html_output, "</ul>\n", buf_size - strlen(html_output) - 1); in_ul = 0; }
                if (in_ol) { strncat(html_output, "</ol>\n", buf_size - strlen(html_output) - 1); in_ol = 0; }
                if (in_table) { strncat(html_output, "</tbody></table>\n", buf_size - strlen(html_output) - 1); in_table = 0; }
                if (in_bq) { strncat(html_output, "</blockquote>\n", buf_size - strlen(html_output) - 1); in_bq=0; }
                char *lang=line_start+3; while(*lang==' ') lang++;
                if(strlen(lang)>0) strncat(html_output, "<pre><code class=\"language-", buf_size - strlen(html_output) - 1), strncat(html_output, lang, buf_size - strlen(html_output) - 1), strncat(html_output, "\">", buf_size - strlen(html_output) - 1);
                else strncat(html_output, "<pre><code>", buf_size - strlen(html_output) - 1);
                in_code = 1;
            }
            continue;
        }
        if (in_code) { strncat(html_output, line_start, buf_size - strlen(html_output) - 1); strncat(html_output, "\n", buf_size - strlen(html_output) - 1); continue; }
        if (is_table_divider(line_start)) continue;

        char *trim=line_start; while(*trim==' '||*trim=='\t') trim++;
        if (strlen(trim)==0) {
            if (in_ul) { strncat(html_output, "</ul>\n", buf_size - strlen(html_output) - 1); in_ul = 0; }
            if (in_ol) { strncat(html_output, "</ol>\n", buf_size - strlen(html_output) - 1); in_ol = 0; }
            if (in_bq) { strncat(html_output, "</blockquote>\n", buf_size - strlen(html_output) - 1); in_bq=0; }
            continue;
        }

        if (trim[0]=='|' || strchr(trim, '|')!=NULL) {
            char *next = (idx+1<fbl)? filtered[idx+1] : NULL;
            int is_next_div = next? is_table_divider(next) : 0;
            if (is_next_div || in_table) {
                if (in_ul) { strncat(html_output, "</ul>\n", buf_size - strlen(html_output) - 1); in_ul = 0; }
                if (in_ol) { strncat(html_output, "</ol>\n", buf_size - strlen(html_output) - 1); in_ol = 0; }
                if (in_bq) { strncat(html_output, "</blockquote>\n", buf_size - strlen(html_output) - 1); in_bq=0; }
                char row_buf[4096] = {0};
                if (!in_table) {
                    strncat(html_output, "<div class=\"table-responsive\"><table><thead>\n", buf_size - strlen(html_output) - 1);
                    render_table_row(trim, row_buf, sizeof(row_buf), "th");
                    strncat(html_output, row_buf, buf_size - strlen(html_output) - 1);
                    strncat(html_output, "</thead><tbody>\n", buf_size - strlen(html_output) - 1);
                    in_table = 1; idx++; // skip divider
                } else {
                    render_table_row(trim, row_buf, sizeof(row_buf), "td");
                    strncat(html_output, row_buf, buf_size - strlen(html_output) - 1);
                }
                if(idx+1>=fbl ||!strchr(filtered[idx+1], '|')){ strncat(html_output, "</tbody></table></div>\n", buf_size - strlen(html_output) - 1); in_table=0; }
                continue;
            }
        } else if (in_table) { strncat(html_output, "</tbody></table></div>\n", buf_size - strlen(html_output) - 1); in_table = 0; }

        if (strncmp(trim, "> ", 2)==0 || strcmp(trim, ">")==0 || strncmp(trim, ">>",2)==0) {
            if(!in_bq){ strncat(html_output, "<blockquote>\n", buf_size - strlen(html_output) - 1); in_bq=1; }
            char *txt=trim; int nest=0; while(*txt=='>'){ nest++; txt++; } while(*txt==' ') txt++;
            char inline_buf[2048]; parse_inline_formatting(txt, inline_buf, sizeof(inline_buf));
            if(nest>1) { char tmp[4096]; snprintf(tmp, sizeof(tmp), "<blockquote>%s</blockquote>\n", inline_buf); strncat(html_output, tmp, buf_size - strlen(html_output) - 1); }
            else { char tmp[4096]; snprintf(tmp, sizeof(tmp), "<p>%s</p>\n", inline_buf); strncat(html_output, tmp, buf_size - strlen(html_output) - 1); }
            if(idx+1>=fbl || strncmp(filtered[idx+1], ">",1)!=0){ strncat(html_output, "</blockquote>\n", buf_size - strlen(html_output) - 1); in_bq=0; }
            continue;
        }

        if ((strncmp(trim, "* ", 2)==0)||(strncmp(trim, "- ",2)==0)||(strncmp(trim, "+ ",2)==0)) {
            if (in_ol) { strncat(html_output, "</ol>\n", buf_size - strlen(html_output) - 1); in_ol = 0; }
            if (!in_ul) { strncat(html_output, "<ul>\n", buf_size - strlen(html_output) - 1); in_ul = 1; }
            char *txt=trim+2;
            int checked=0, is_task=0;
            if(strncmp(txt, "[x] ",4)==0||strncmp(txt, "[X] ",4)==0){ is_task=1; checked=1; txt+=4; }
            else if(strncmp(txt, "[ ] ",4)==0){ is_task=1; checked=0; txt+=4; }
            char inline_buf[2048]; parse_inline_formatting(txt, inline_buf, sizeof(inline_buf));
            char line_buf[4096];
            if(is_task) snprintf(line_buf, sizeof(line_buf), "<li class=\"task\"><input type=\"checkbox\" %s disabled> %s</li>\n", checked?"checked":"", inline_buf);
            else snprintf(line_buf, sizeof(line_buf), "<li>%s</li>\n", inline_buf);
            strncat(html_output, line_buf, buf_size - strlen(html_output) - 1);
            continue;
        } else if (in_ul && strlen(trim)>0 && (trim[0]!='-' && trim[0]!='*')) {
            if(trim[0]!=' ' && trim[0]!='\t'){ strncat(html_output, "</ul>\n", buf_size - strlen(html_output) - 1); in_ul = 0; }
        }

        if (isdigit((unsigned char)trim[0]) && trim[1]=='.' && trim[2]==' ') {
            if (in_ul) { strncat(html_output, "</ul>\n", buf_size - strlen(html_output) - 1); in_ul = 0; }
            if (!in_ol) { strncat(html_output, "<ol>\n", buf_size - strlen(html_output) - 1); in_ol = 1; }
            char inline_buf[2048]; parse_inline_formatting(trim+3, inline_buf, sizeof(inline_buf));
            char line_buf[4096]; snprintf(line_buf, sizeof(line_buf), "<li>%s</li>\n", inline_buf);
            strncat(html_output, line_buf, buf_size - strlen(html_output) - 1);
            continue;
        } else if (in_ol) {
            if(!isdigit((unsigned char)trim[0])){ strncat(html_output, "</ol>\n", buf_size - strlen(html_output) - 1); in_ol = 0; }
        }

        char inline_buf[4096]; char final_line[8192];
        if (strncmp(trim, "###### ", 7)==0){ parse_inline_formatting(trim+7, inline_buf, sizeof(inline_buf)); char id[256]; slugify(trim+7, id, sizeof(id)); snprintf(final_line, sizeof(final_line), "<h6 id=\"%s\">%s</h6>\n", id, inline_buf); }
        else if (strncmp(trim, "##### ", 6)==0){ parse_inline_formatting(trim+6, inline_buf, sizeof(inline_buf)); char id[256]; slugify(trim+6, id, sizeof(id)); snprintf(final_line, sizeof(final_line), "<h5 id=\"%s\">%s</h5>\n", id, inline_buf); }
        else if (strncmp(trim, "#### ", 5)==0){ parse_inline_formatting(trim+5, inline_buf, sizeof(inline_buf)); char id[256]; slugify(trim+5, id, sizeof(id)); snprintf(final_line, sizeof(final_line), "<h4 id=\"%s\">%s</h4>\n", id, inline_buf); }
        else if (strncmp(trim, "### ", 4)==0){ parse_inline_formatting(trim+4, inline_buf, sizeof(inline_buf)); char id[256]; slugify(trim+4, id, sizeof(id)); snprintf(final_line, sizeof(final_line), "<h3 id=\"%s\">%s</h3>\n", id, inline_buf); }
        else if (strncmp(trim, "## ", 3)==0){ parse_inline_formatting(trim+3, inline_buf, sizeof(inline_buf)); char id[256]; slugify(trim+3, id, sizeof(id)); snprintf(final_line, sizeof(final_line), "<h2 id=\"%s\">%s</h2>\n", id, inline_buf); }
        else if (strncmp(trim, "# ", 2)==0){ parse_inline_formatting(trim+2, inline_buf, sizeof(inline_buf)); char id[256]; slugify(trim+2, id, sizeof(id)); snprintf(final_line, sizeof(final_line), "<h1 id=\"%s\">%s</h1>\n", id, inline_buf); }
        else { parse_inline_formatting(trim, inline_buf, sizeof(inline_buf)); snprintf(final_line, sizeof(final_line), "<p>%s</p>\n", inline_buf); }
        strncat(html_output, final_line, buf_size - strlen(html_output) - 1);
    }

    if (in_ul) strncat(html_output, "</ul>\n", buf_size - strlen(html_output) - 1);
    if (in_ol) strncat(html_output, "</ol>\n", buf_size - strlen(html_output) - 1);
    if (in_table) strncat(html_output, "</tbody></table></div>\n", buf_size - strlen(html_output) - 1);
    if (in_code) strncat(html_output, "</code></pre>\n", buf_size - strlen(html_output) - 1);
    if (in_bq) strncat(html_output, "</blockquote>\n", buf_size - strlen(html_output) - 1);

    if(fc>0){
        strncat(html_output, "<section class=\"footnotes\"><hr><ol>\n", buf_size - strlen(html_output) - 1);
        for(int i=0;i<fc;i++){
            char inline_buf[2048]; parse_inline_formatting(fns[i].text, inline_buf, sizeof(inline_buf));
            char foot[4096]; snprintf(foot, sizeof(foot), "<li id=\"fn:%s\">%s <a href=\"#fnref:%s\" class=\"footnote-backref\">↩</a></li>\n", fns[i].label, inline_buf, fns[i].label);
            strncat(html_output, foot, buf_size - strlen(html_output) - 1);
        }
        strncat(html_output, "</ol></section>\n", buf_size - strlen(html_output) - 1);
    }

    for(int i=0;i<fbl;i++) free(filtered[i]);
    return html_output;
}

void cax_markdown_free(char *html){ if(html) free(html); }