#ifndef CAX_MARKDOWN_H
#define CAX_MARKDOWN_H

char *cax_markdown_to_html(const char *md_content);
char *cax_markdown_generate_toc(const char *markdown);
void cax_markdown_free(char *html);

#endif