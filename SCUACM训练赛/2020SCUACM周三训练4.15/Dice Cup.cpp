#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;

int N,M,cnt[50];

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%d",&N,&M);
    fill_n(cnt,50,0);
    for(int i = 1;i <= N;i ++){
        for(int j = 1;j <= M;j ++){
            cnt[i + j]++;
        }
    }
    int maxx = 0;
    for(int i = 2;i <= N + M;i ++) maxx = max(cnt[i],maxx);
    for(int i = 2;i <= N + M;i ++) if(cnt[i] == maxx) printf("%d\n",i);
}