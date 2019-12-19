#include <bits/stdc++.h>
using namespace std;

int n,t;

char codes[15][10];

int exists(int j){
    char *code = codes[j];
    for(int i = 0;i < n;i ++){
        if(!strcmp(code,codes[i]) && i != j) return true;
    }
    return false;
}

int main(){
    //freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    scanf("%d",&t);
    while(t --){
        int ans = 0;
        int judged[15] = {0};
        scanf("%d",&n);
        for(int i = 0;i < n;i ++){
            scanf("%s",codes + i);
        }
        for(int i = 0;i < n;i ++){
            for(int j = i + 1;j < n;j ++){
                if(judged[j]) continue;
                if(!strcmp(codes[i],codes[j])){
                    judged[j] = 1;
                    ans++;
                    for(int k = '0';k <= '9' && exists(j);k ++){
                        codes[j][0] = k;
                    }
                }
            }
        }
        printf("%d\n",ans);
        for(int i = 0;i < n;i ++){
            printf("%s\n",codes[i]);
        }
    } 
} 
