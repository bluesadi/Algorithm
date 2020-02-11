#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char header[1000005],ans[1000005];

int getKeyLen(){
    int key_len = 0,key_read = 0;
    while(key_read != 3){
        char c = getchar();
        if(c == '0' || c == '1')
            key_len += (4 >> (key_read++)) * (c - '0');
    }
    return key_len;
}

char map(char* key){
    int len = strlen(key),offset = (1 << len) - len - 1,v = 0;
    for(int i = len - 1;i >= 0;i --)
        v += (1 << i) * (key[len - i - 1] - '0');
    return header[offset + v];
}

bool checkKey(char* key){
    for(int i = 0;key[i];i++) if(key[i] == '0') return true;
    return false;
}

void readKey(char *key,int len){
    for(int i = 0;i < len;i ++)
        while((key[i] = getchar()) != '0' && key[i] != '1');
    key[len] = '\0';
}

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    while(gets(header) != NULL){
        int key_len = getKeyLen(),ptr = 0;
        char key[200];
        while(true){
            readKey(key,key_len);
            if(!checkKey(key)){
                key_len = getKeyLen();
                if(key_len == 0) break;
                continue;
            }
            ans[ptr++] = map(key);
        }
        ans[ptr] = '\0';
        printf("%s\n",ans);
        getchar();
    }
}