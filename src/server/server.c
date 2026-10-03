#include "server.h"
#include "../utils/file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#endif

static const char* get_mime(const char *path){
    if(strstr(path,".html")) return "text/html";
    if(strstr(path,".css")) return "text/css";
    if(strstr(path,".js")) return "application/javascript";
    if(strstr(path,".json")) return "application/json";
    if(strstr(path,".png")) return "image/png";
    if(strstr(path,".jpg")||strstr(path,".jpeg")) return "image/jpeg";
    if(strstr(path,".svg")) return "image/svg+xml";
    if(strstr(path,".ico")) return "image/x-icon";
    if(strstr(path,".woff")) return "font/woff";
    if(strstr(path,".woff2")) return "font/woff2";
    return "text/plain";
}

static char* read_file_bin(const char *path, size_t *out_len){
    FILE *f=fopen(path,"rb");
    if(!f) return NULL;
    fseek(f,0,SEEK_END);
    long sz=ftell(f);
    fseek(f,0,SEEK_SET);
    if(sz<0){ fclose(f); return NULL; }
    char *buf=malloc(sz+1);
    if(!buf){ fclose(f); return NULL; }
    size_t r=fread(buf,1,sz,f);
    fclose(f);
    buf[r]='\0';
    if(out_len) *out_len=r;
    return buf;
}

int cax_server_start(const char *root_dir, int port){
    if(!root_dir) root_dir="site";
    printf("\n [SERVER] CAX Native C Server\n");
    printf(" [SERVER] Root: %s\n", root_dir);
    printf(" [SERVER] URL: http://localhost:%d\n", port);
    printf(" [SERVER] Press Ctrl+C to stop\n\n");

#ifdef _WIN32
    WSADATA wsa; WSAStartup(MAKEWORD(2,2),&wsa);
#endif
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    if(srv < 0){ printf(" socket error\n"); return 1; }
    int opt=1;
#ifdef _WIN32
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));
#else
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
#endif
    struct sockaddr_in addr; memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=INADDR_ANY;
    addr.sin_port=htons(port);
    if(bind(srv,(struct sockaddr*)&addr,sizeof(addr))<0){ printf(" bind error port %d used!\n",port); return 1; }
    if(listen(srv,10)<0){ printf(" listen error\n"); return 1; }

    while(1){
        struct sockaddr_in cli;
#ifdef _WIN32
        int clen=sizeof(cli);
#else
        socklen_t clen=sizeof(cli);
#endif
        int cl = accept(srv,(struct sockaddr*)&cli,&clen);
        if(cl<0) continue;
        char req[8192]={0};
#ifdef _WIN32
        recv(cl,req,sizeof(req)-1,0);
#else
        {
            ssize_t _cax_r = read(cl,req,sizeof(req)-1);
            if(_cax_r>0) req[_cax_r]='\0';
            (void)_cax_r;
        }
#endif
        char method[8], url[2048];
        if(sscanf(req,"%7s %2047s",method,url)!=2){
#ifdef _WIN32
            closesocket(cl);
#else
            close(cl);
#endif
            continue;
        }
        char *q=strchr(url,'?'); if(q) *q='\0';
        // prevent ..
        if(strstr(url,"..")){
#ifdef _WIN32
            closesocket(cl);
#else
            close(cl);
#endif
            continue;
        }
        char filepath[4096];
        if(strcmp(url,"/")==0){
            snprintf(filepath,sizeof(filepath),"%s/index.html",root_dir);
        } else {
            // if url ends with / -> /index.html
            size_t ul=strlen(url);
            if(url[ul-1]=='/'){
                snprintf(filepath,sizeof(filepath),"%s%sindex.html",root_dir,url);
            } else {
                snprintf(filepath,sizeof(filepath),"%s%s",root_dir,url);
                // if file is directory, try /index.html
                FILE *test=fopen(filepath,"rb");
                if(!test){
                    // try with .html? no, try index.html inside
                    char alt[4096];
                    snprintf(alt,sizeof(alt),"%s%s/index.html",root_dir,url);
                    FILE *test2=fopen(alt,"rb");
                    if(test2){ fclose(test2); strcpy(filepath,alt); }
                } else fclose(test);
            }
        }

        size_t flen=0;
        char *content=read_file_bin(filepath,&flen);
        char header[1024];
        if(content){
            snprintf(header,sizeof(header),
                "HTTP/1.1 200 OK\r\nContent-Type: %s\r\nContent-Length: %zu\r\nCache-Control: no-cache\r\nConnection: close\r\n\r\n",
                get_mime(filepath), flen);
#ifdef _WIN32
            send(cl,header,strlen(header),0);
            send(cl,content,flen,0);
#else
            {
                ssize_t _w1 = write(cl,header,strlen(header));
                ssize_t _w2 = write(cl,content,flen);
                (void)_w1; (void)_w2;
            }
#endif
            free(content);
        } else {
            const char *notfound="<html><body><h1>404 CAX - Not Found</h1><p>File not found</p><a href='/'>Home</a></body></html>";
            snprintf(header,sizeof(header),
                "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nContent-Length: %zu\r\nConnection: close\r\n\r\n",
                strlen(notfound));
#ifdef _WIN32
            send(cl,header,strlen(header),0);
            send(cl,notfound,strlen(notfound),0);
#else
            {
                ssize_t _w3 = write(cl,header,strlen(header));
                ssize_t _w4 = write(cl,notfound,strlen(notfound));
                (void)_w3; (void)_w4;
            }
#endif
        }
#ifdef _WIN32
        closesocket(cl);
#else
        close(cl);
#endif
        printf(" [GET] %s -> %s\n", url, filepath);
    }
#ifdef _WIN32
    closesocket(srv); WSACleanup();
#else
    close(srv);
#endif
    return 0;
}
