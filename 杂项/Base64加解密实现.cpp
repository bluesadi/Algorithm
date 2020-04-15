#include <cstdio>
#include <cstring>

char base[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int indexOf(char c){
    if(c >= 'A' && c <= 'Z') return c - 'A';
    else if(c >= 'a' && c <= 'z') return c - 'a' + 26;
    else if(c >= '0' && c <= '9') return c - '0' + 52;
    else if(c == '+') return 62;
    else if(c == '/') return 63;
    else return -1; 
}

void base64_encode(char *dest,const char *source,int src_len){
    char buf[3];
    int ptr = 0;
    for(int i = 0;i < src_len / 3;i ++){
        buf[0] = source[i * 3],buf[1] = source[i * 3 + 1],buf[2] = source[i * 3 + 2];
        dest[ptr++] = base[buf[0] >> 2];
        dest[ptr++] = base[(buf[1] >> 4 | buf[0] << 4) & 0x3f];
        dest[ptr++] = base[(buf[1] << 2 | buf[2] >> 6) & 0x3f];
        dest[ptr++] = base[buf[2] & 0x3f];
    }
    if(src_len % 3 == 1){
        buf[0] = source[src_len - 1];
        dest[ptr++] = base[buf[0] >> 2];
        dest[ptr++] = base[buf[0] << 4 & 0x3f];
        dest[ptr++] = '=';
        dest[ptr++] = '=';
    }else if(src_len % 3 == 2){
        buf[0] = source[src_len - 2],buf[1] = source[src_len - 2];
        dest[ptr++] = base[buf[0] >> 2];
        dest[ptr++] = base[(buf[1] >> 4 | buf[0] << 4) & 0x3f];
        dest[ptr++] = base[buf[1] << 2 & 0x3f];
        dest[ptr++] = '=';
    }
    dest[ptr] = 0;
}

void base64_decode(char *dest,const char *source,int src_len){
    char buf[4];
    int ptr = 0;
    for(int i = 0;i < src_len / 4;i ++){
        for(int j = 0;j < 4;j ++) buf[j] = indexOf(source[4 * i + j]);
        dest[ptr++] = buf[0] << 2 | buf[1] >> 4;
        if(buf[2] != -1) dest[ptr++] = buf[1] << 4 | buf[2] >> 2;
        if(buf[2] != -1 && buf[3] != -1) dest[ptr++] = buf[2] << 6 | buf[3];
    }
    dest[ptr] = 0;
}

int main(){
    char dest[1000],dest2[1000],source[1000] = "ABCDESDS666D6";
    base64_encode(dest,source,strlen(source));
    base64_decode(dest2,dest,strlen(dest));
    printf("加密:%s\n解密:%s",dest,dest2);
}