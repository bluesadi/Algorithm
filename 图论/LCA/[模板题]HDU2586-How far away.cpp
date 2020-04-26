#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl;
#define dot << "," <<
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 40050

int T,n,m,pa[MAXN][20],depth[MAXN],dist[MAXN];
vector<pair<int,int>> edges[MAXN];

void dfs(int i){
    for(int up = 1;up < 20;up ++) pa[i][up] = pa[pa[i][up - 1]][up - 1];
    for(auto &edge : edges[i]){
        if(depth[edge.first]) continue;
        pa[edge.first][0] = i;
        depth[edge.first] = depth[i] + 1;
        dist[edge.first] = dist[i] + edge.second;
        dfs(edge.first);
    }
}

int lca(int u,int v){
    if(depth[u] < depth[v]) return lca(v,u);
    int distu = dist[u],distv = dist[v];
    for(int i = 19;i >= 0;i --) if(depth[u] - (1 << i) >= depth[v]) u = pa[u][i];
    for(int i = 19;i >= 0;i --){
        if(pa[u][i] != pa[v][i]){
            u = pa[u][i];
            v = pa[v][i];
        }
    }
    if(u != v) return distu + distv - 2 * dist[pa[u][0]];
    return distu + distv - 2 * dist[u];
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        for(int i = 0;i < MAXN;i++) edges[i].clear();
        memset(pa,0,sizeof pa),memset(dist,0,sizeof dist),memset(depth,0,sizeof depth);
        depth[1] = 1;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n - 1;i ++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back({v,w});
            edges[v].push_back({u,w});
        }
        dfs(1);
        for(int i = 0;i < m;i ++){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",lca(a,b));
        }
    }
}