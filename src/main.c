#include <stdio.h>
#include <string.h>
#include "build/builder.h"
#include "version.h"

void print_help(void){
    printf("\n");
    printf(" CAX SSG - %s\n", CAX_CODENAME);
    printf(" %s - Est. MMXXIV\n", CAX_EDITION);
    printf(" %s\n", CAX_MAKER);
    printf(" %s - %s\n", CAX_URL, CAX_MOTTO);
    printf(" ------------------------------------------\n");
    printf(" v%s - %s\n", CAX_VERSION, CAX_TAGLINE);
    printf(" ------------------------------------------\n");
    printf(" cax init               Init new atelier project\n");
    printf(" cax build              Forge site/ from markdown\n");
    printf(" cax serve              Native C chronometer server :8080\n");
    printf(" cax start / watch      Forge + Serve + Live brass reload\n");
    printf(" cax new post \"Title\"   Draft new post in atelier\n");
    printf(" cax new page \"Title\"   Draft new page in atelier\n");
    printf(" cax --version / -v     Show horological version\n");
    printf(" cax --help / -h        Show atelier manual\n\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return 0;
    }

    // FIX: support --v, --version, -v, -V, version, --help, -h, help
    if (strcmp(argv[1], "--version")==0 || strcmp(argv[1], "--v")==0 || 
        strcmp(argv[1], "-v")==0 || strcmp(argv[1], "-V")==0 ||
        strcmp(argv[1], "version")==0 || strcmp(argv[1], "--Version")==0){
        printf("\n CAX Engine %s\n", CAX_VERSION);
        printf(" %s\n", CAX_CODENAME);
        printf(" %s\n", CAX_EDITION);
        printf(" %s - %s\n\n", CAX_MAKER, CAX_URL);
        printf(" %s\n\n", CAX_MOTTO);
        printf(" %s\n\n", CAX_TAGLINE);
        return 0;
    }
    if (strcmp(argv[1], "--help")==0 || strcmp(argv[1], "-h")==0 ||
        strcmp(argv[1], "help")==0 || strcmp(argv[1], "--h")==0){
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "init") == 0) { cax_builder_init_project(); }
    else if (strcmp(argv[1], "build") == 0) { cax_builder_run(); }
    else if (strcmp(argv[1], "serve") == 0) { cax_builder_serve(); }
    else if (strcmp(argv[1], "start") == 0 || strcmp(argv[1], "watch") == 0) { cax_builder_start_with_watch(); }
    else if (strcmp(argv[1], "new") == 0) { cax_builder_new_content(argc, argv); }
    else {
        printf(" [ERROR] Unknown calibre: %s\n", argv[1]);
        print_help();
    }
    return 0;
}
