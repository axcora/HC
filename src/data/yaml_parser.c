#include "yaml_parser.h"
#include "data_manager.h"
#include "../utils/string_utils.h"
#include "../utils/file_utils.h"
#include "../../include/cax.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DEPTH 32
#define MAX_LINES 4096

static char *trim_spaces(char *s){ if(!s) return NULL; while(*s&&isspace((unsigned char)*s)) s++; if(!*s) return s; char *e=s+strlen(s)-1; while(e>s&&isspace((unsigned char)*e)){*e='\0'; e--;} return s; }
static char *strip_quotes(char *s){ if(!s) return s; size_t l=strlen(s); if(l>=2&&((s[0]=='"'&&s[l-1]=='"')||(s[0]=='\''&&s[l-1]=='\''))){ s[l-1]='\0'; return s+1; } return s; }
static int get_indent(const char *line){ int i=0; while(line[i]==' ') i++; return i; }

typedef struct { int indent; int is_arr; CAXObject *obj; CAXArray *arr; } Stack;

CAXObject* cax_parse_yaml(const char *yaml_str){
    if(!yaml_str) return NULL;
    CAXObject *root=cax_object_new();
    char *copy=cax_strdup(yaml_str);
    char *lines[MAX_LINES]; int total=0;
    char *save=NULL; char *l=strtok_r(copy,"\n",&save);
    while(l&&total<MAX_LINES){ lines[total++]=l; l=strtok_r(NULL,"\n",&save); }

    Stack st[MAX_DEPTH]; int top=0;
    st[0].indent=-1; st[0].is_arr=0; st[0].obj=root; st[0].arr=NULL;

    for(int idx=0; idx<total; idx++){
        char buf[4096]; strncpy(buf,lines[idx],sizeof(buf)-1); buf[sizeof(buf)-1]='\0';
        char *raw=lines[idx];
        int ind=get_indent(raw);
        char *trim=trim_spaces(buf);
        if(!trim||!strlen(trim)||trim[0]=='#') continue;
        while(top>0 && ind <= st[top].indent) top--;
        CAXObject *parent_obj = st[top].obj;

        if(trim[0]=='-'){
            char *val=trim_spaces(trim+1);
            CAXArray *target_arr = NULL;
            if(st[top].is_arr) target_arr = st[top].arr;
            else { for(int i=top;i>=0;i--) if(st[i].is_arr){ target_arr=st[i].arr; break; } }
            if(!target_arr) continue;
            if(strlen(val)==0){
                CAXObject *item=cax_object_new();
                cax_array_add(target_arr,item);
                if(top+1<MAX_DEPTH){ top++; st[top].indent=ind; st[top].is_arr=0; st[top].obj=item; st[top].arr=NULL; }
            } else {
                char *colon=strchr(val,':');
                if(colon){
                    *colon='\0'; char *k=trim_spaces(val); char *v=trim_spaces(colon+1);
                    CAXObject *item=cax_object_new();
                    if(strlen(v)>0) cax_object_set_string(item,k,strip_quotes(v));
                    else {
                        CAXObject *sub=cax_object_new();
                        cax_object_set_pointer(item,k,sub);
                        cax_array_add(target_arr,item);
                        if(top+1<MAX_DEPTH){ top++; st[top].indent=ind; st[top].is_arr=0; st[top].obj=sub; st[top].arr=NULL; }
                        continue;
                    }
                    cax_array_add(target_arr,item);
                    if(top+1<MAX_DEPTH){ top++; st[top].indent=ind; st[top].is_arr=0; st[top].obj=item; st[top].arr=NULL; }
                } else {
                    CAXObject *item=cax_object_new();
                    cax_object_set_string(item,"value",strip_quotes(val));
                    cax_array_add(target_arr,item);
                }
            }
            continue;
        }
        if(st[top].is_arr) continue;
        char *colon=strchr(trim,':'); if(!colon) continue;
        *colon='\0'; char *key=trim_spaces(trim); char *val=trim_spaces(colon+1);
        if(!strlen(key)) continue;
        if(strlen(val)==0){
            int next_is_arr=0;
            for(int j=idx+1;j<total;j++){
                char b2[4096]; strncpy(b2,lines[j],sizeof(b2)-1);
                char *t2=trim_spaces(b2);
                if(!t2||!strlen(t2)||t2[0]=='#') continue;
                int ind2=get_indent(lines[j]);
                if(ind2<=ind) break;
                if(t2[0]=='-') next_is_arr=1;
                break;
            }
            if(next_is_arr){
                CAXArray *arr=cax_array_new();
                cax_object_set_pointer(parent_obj?parent_obj:root,key,arr);
                if(top+1<MAX_DEPTH){ top++; st[top].indent=ind; st[top].is_arr=1; st[top].obj=NULL; st[top].arr=arr; }
            } else {
                CAXObject *o=cax_object_new();
                cax_object_set_pointer(parent_obj?parent_obj:root,key,o);
                if(top+1<MAX_DEPTH){ top++; st[top].indent=ind; st[top].is_arr=0; st[top].obj=o; st[top].arr=NULL; }
            }
        } else if(val[0]=='['){
            CAXArray *arr=cax_array_new();
            char *p=val+1;
            while(*p){
                while(*p==' '||*p=='\t'||*p==','||*p=='"'||*p=='\''||*p=='[') p++;
                if(*p==']'||!*p) break;
                char *s=p; while(*p&&*p!=','&&*p!=']'&&*p!='"'&&*p!='\'') p++;
                int len=p-s; if(len>0){ char tmp[512]; if(len>511) len=511; memcpy(tmp,s,len); tmp[len]='\0'; char *t=trim_spaces(tmp); t=strip_quotes(t); if(strlen(t)){ CAXObject *it=cax_object_new(); cax_object_set_string(it,"value",t); cax_array_add(arr,it); } }
            }
            cax_object_set_pointer(parent_obj?parent_obj:root,key,arr);
        } else {
            cax_object_set_string(parent_obj?parent_obj:root,key,strip_quotes(val));
        }
    }
    free(copy); return root;
}

void cax_load_yaml_file(const char *filepath, CAXObject *global_ctx){
    char *content=cax_read_file(filepath); if(!content) return;
    CAXObject *parsed=cax_parse_yaml(content); free(content); if(!parsed) return;
    const char *filename=strrchr(filepath,'/'); if(!filename) filename=strrchr(filepath,'\\'); filename=filename?filename+1:filepath;
    char name[256]={0}; strncpy(name,filename,sizeof(name)-1); char *ext=strrchr(name,'.'); if(ext) *ext='\0';
    CAXObject *existing=(CAXObject*)cax_object_get_pointer(global_ctx,name);
    if(existing){
        for(int i=0;i<parsed->count;i++){
            if(parsed->fields[i].type==CAX_TYPE_STRING) cax_object_set_string(existing,parsed->fields[i].key,parsed->fields[i].string_val);
            else cax_object_set_pointer(existing,parsed->fields[i].key,parsed->fields[i].pointer_val);
        }
        cax_object_free(parsed);
    } else {
        cax_object_set_pointer(global_ctx,name,parsed);
    }
    printf(" [DATA] Loaded %s -> {{ %s.* }} (deep)\n", filepath, name);
}