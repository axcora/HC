#include <stdio.h>
#include "chat_json.h"

int main(int argc, char *argv[]) {
    const char *dir = (argc > 1) ? argv[1] : "content/themes";
    const char *out = (argc > 2) ? argv[2] : "site/themes-index.json";
    return cax_chat_generate_index(dir, out);
}