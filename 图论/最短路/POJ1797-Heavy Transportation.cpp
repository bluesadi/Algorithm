#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T,n,m,w[1005][1005],d[1005],visit[1005],cnt = 1;

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        ms(w,inf),ms(d,0),ms(visit,0);
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= m;i ++){
            int u,v,w1;
            scanf("%d%d%d",&u,&v,&w1);
            w[u][v] = w[v][u] = w1;
        }
        for(int i = 1;i <= n;i ++) if(w[1][i] != inf) d[i] = w[1][i];
        for(int i = 1;i <= n;i ++){
            int min_n = 0,k;
            for(int j = n;j >= 1;j --) if(!visit[j] && d[j] > min_n) min_n = d[k = j];
            visit[k] = 1;
            for(int j = 1;j <= n;j ++) if(w[j][k] != inf) d[j] = max(d[j],min(d[k],w[j][k]));
        }
        printf("Scenario #%d:\n%d\n\n",cnt++,d[n]);
    }
}