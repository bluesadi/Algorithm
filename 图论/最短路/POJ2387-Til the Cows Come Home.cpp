#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int d[1005],N,T,w[1005][1005],visit[1005];

int main(){
    scanf("%d%d",&T,&N);
    ms(d,inf),ms(w,inf),ms(visit,0);
    for(int i = 0;i < T;i ++){
        int u,v,w1;
        scanf("%d%d%d",&u,&v,&w1);
        w[u][v] = w[v][u] = min(w1,w[v][u]);
    }
    d[N] = 0;
    for(int i = 1;i <= N;i ++){
        int x = inf,k;
        for(int j = 1;j <= N;j ++) if(!visit[j] && d[j] < x) x = d[k = j];
        visit[k] = 1;
        for(int j = 1;j <= N;j ++) d[j] = min(d[j],w[k][j] + d[k]);
    }
    printf("%d",d[1]); 
}