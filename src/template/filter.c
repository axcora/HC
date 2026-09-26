#include "filter.h"
#include "../utils/string_utils.h"
#include "../data/data_manager.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

static char *trim_f(char *s){
    if(!s) return s;
    while(*s==' '||*s=='\t'||*s=='\n'||*s=='\r'||*s=='('||*s==')'||*s==':' ) s++;
    if(!*s) return s;
    char *e=s+strlen(s)-1;
    while(e>s && (*e==' '||*e=='\t'||*e=='\n'||*e=='\r'||*e==')'||*e=='('||*e==':')){*e='\0'; e--;}
    return s;
}

static const char* _get_tag_val_safe(void *p){
    if(!p) return NULL;
    CAXObject *o=(CAXObject*)p;
    const char *v=cax_object_get_string(o,"value");
    if(v) return v;
    v=cax_object_get_string(o,"name");
    if(v) return v;
    return (const char*)p;
}

CAXArray* cax_filter_limit(CAXArray *arr, int limit){
    if(!arr) return NULL;
    if(limit<=0 || limit>=arr->count) return arr;
    CAXArray *out=cax_array_new();
    if(!out) return arr;
    for(int i=0;i<limit && i<arr->count;i++) cax_array_add(out, arr->items[i]);
    return out;
}

CAXArray* cax_filter_slice(CAXArray *arr, int start, int end){
    if(!arr) return NULL;
    if(start<0) start=0;
    if(end<=0 || end>arr->count) end=arr->count;
    if(start>=end) return cax_array_new();
    CAXArray *out=cax_array_new();
    if(!out) return arr;
    for(int i=start;i<end && i<arr->count;i++) cax_array_add(out, arr->items[i]);
    return out;
}

CAXArray* cax_filter_by_tag(CAXArray *arr, const char *tag_val, CAXObject *ctx){
    if(!arr) return NULL;
    if(!tag_val ||!*tag_val) return arr;

    char buf[256]; strncpy(buf, tag_val, 255); buf[255]='\0';
    char *real=trim_f(buf);
    if(!real ||!*real) return arr;

    // FIX CRASH: resolve tag.name dengan aman
    const char *final_tag=real;
    if(ctx && strchr(real,'.')){
        char b2[256]; strncpy(b2, real, 255); b2[255]='\0';
        char *save=NULL; char *tok=strtok_r(b2,".",&save);
        CAXObject *cur=ctx;
        const char *found=NULL;
        while(tok){
            if(!cur) break;
            char *nxt=strtok_r(NULL,".",&save);
            if(!nxt){
                if(cur) found=cax_object_get_string(cur,tok);
                break;
            }
            CAXObject *next_obj=(CAXObject*)cax_object_get_pointer(cur,tok);
            if(!next_obj) break;
            cur=next_obj;
            tok=nxt;
        }
        if(found && *found) final_tag=found;
        else {
            return arr;
        }
    }

    char clean_tag[256]; strncpy(clean_tag, final_tag, 255); clean_tag[255]='\0';
    char *q=clean_tag;
    while(*q=='\''||*q=='"'||*q==' '||*q=='\t') q++;
    memmove(clean_tag,q,strlen(q)+1);
    size_t n=strlen(clean_tag);
    while(n>0 && (clean_tag[n-1]=='\''||clean_tag[n-1]=='"'||clean_tag[n-1]==' '||clean_tag[n-1]=='\t')) clean_tag[--n]='\0';

    if(!clean_tag[0]) return arr;

    CAXArray *out=cax_array_new();
    if(!out) return arr;
    for(int i=0;i<arr->count;i++){
        CAXObject *obj=(CAXObject*)arr->items[i];
        if(!obj) continue;
        int ok=0;
        CAXArray *tarr=(CAXArray*)cax_object_get_pointer(obj,"tags");
        if(tarr){
            for(int k=0;k<tarr->count;k++){
                const char *v=_get_tag_val_safe(tarr->items[k]);
                if(!v) continue;
                if(strcmp(v,clean_tag)==0){ ok=1; break; }
                if(strcmp(clean_tag,"featured")==0 && (strcmp(v,"featured")==0 || strcmp(v,"featuredthemes")==0)){ ok=1; break; }
            }
        } else {
            const char *tags=cax_object_get_string(obj,"tags");
            if(tags){
                if(strstr(tags, clean_tag)) ok=1;
                if(strcmp(clean_tag,"featured")==0 && (strstr(tags,"featured")||strstr(tags,"featuredthemes"))) ok=1;
            }
        }
        if(ok) cax_array_add(out,obj);
    }
    return out->count>0? out : arr;
}

CAXArray* cax_filter_apply(CAXArray *input_array, const char *filter_expr){
    (void)filter_expr; 
    return input_array;
}

CAXArray* cax_apply_filter_chain(CAXArray *input, const char *chain, CAXObject *ctx){
    if(!input) return NULL;
    if(!chain ||!*chain) return input;
    char copy[1024]; strncpy(copy, chain, 1023); copy[1023]='\0';
    char *save=NULL; char *tok=strtok_r(copy, "|", &save);
    CAXArray *cur=input;
    while(tok){
        char *f=trim_f(tok);
        if(*f){
            if(strncmp(f,"limit",5)==0){
                char *p=f+5; while(*p &&!isdigit((unsigned char)*p)) p++;
                int v=atoi(p); if(v>0) cur=cax_filter_limit(cur, v);
            } else if(strncmp(f,"slice",5)==0){
                char *p=strchr(f,'('); if(p){ p++; int s=atoi(p); char *c=strchr(p,','); int e=-1; if(c) e=atoi(c+1); cur=cax_filter_slice(cur,s,e); }
            } else if(strncmp(f,"by",2)==0){
                char *p=strchr(f,':'); if(p) p++; else p=f+2;
                p=trim_f(p);
                if(*p) cur=cax_filter_by_tag(cur, p, ctx);
            } else if(strncmp(f,"filter",6)==0){
                char tag[256]={0};
                const char *q=strchr(f,'\'');
                if(!q) q=strchr(f,'"');
                if(q){
                    q++;
                    int j=0;
                    while(*q && *q!='\'' && *q!='"' && *q!=')' && j<255){ tag[j++]=*q++; }
                    tag[j]='\0';
                } else {
                    const char *b=strchr(f,'(');
                    if(b){
                        b++;
                        int j=0;
                        while(*b && *b!=')' && j<255){
                            if(*b!=' '&&*b!='\t'&&*b!='\''&&*b!='"') tag[j++]=*b;
                            b++;
                        }
                        tag[j]='\0';
                    }
                }
                char *tt=trim_f(tag);
                if(*tt) cur=cax_filter_by_tag(cur, tt, ctx);
            }
        }
        tok=strtok_r(NULL, "|", &save);
    }
    return cur?cur:input;
}
