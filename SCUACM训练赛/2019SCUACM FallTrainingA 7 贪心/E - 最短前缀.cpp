#include<cstdio>
#include<algorithm>
#include <cstring>
using namespace std;

char prefix[1005][25];
char raw[1005][25]; 

void strcpy(char *dest,char *source,int len){
    for(int i = 0;i < len;i ++){
        dest[i] = source[i]; 
    }
    dest[len] = '\0';
}

bool strcon(char *s1,char *s2){
    for(int i = 0;s1[i] != '\0' && s2[i] != '\0';i ++){
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    int i = 0;
    while(scanf("%s",raw + i) != EOF){
        int len = strlen(raw[i]);
        memset(prefix[i],0,sizeof prefix[i]);
        char *cur = prefix[i];
        cur[0] = raw[i][0];
        for(int j = 0;j < i;j ++){
            char *pre = prefix[j];
            while(strcon(pre,cur)){
                if(!strcmp(cur,raw[i])){
                    while(strcon(pre,cur) && strlen(pre) <= strlen(cur) && strcmp(pre,raw[j])) strcpy(pre,raw[j],strlen(pre) + 1);
                    break;
                }
                if(!strcmp(pre,raw[j])){
                    while(strcon(pre,cur) && strlen(cur) <= strlen(pre) && strcmp(cur,raw[i])) strcpy(cur,raw[i],strlen(cur) + 1);
                    break;
                }
                int pre_len = strlen(pre),cur_len = strlen(cur);
                if(pre_len == cur_len){
                    strcpy(cur,raw[i],strlen(cur) + 1);
                    strcpy(pre,raw[j],strlen(pre) + 1);
                }else if(pre_len > cur_len){
                    strcpy(cur,raw[i],strlen(cur) + 1);
                }else{
                    strcpy(pre,raw[j],strlen(pre) + 1);
                }
            }
        }
        i ++;
    }
    for(int j = 0;j < i;j ++){
        printf("%s %s\n",raw[j],prefix[j]);
    }
}
