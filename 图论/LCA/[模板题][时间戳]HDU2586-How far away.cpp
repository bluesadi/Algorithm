#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define LL long long
#define Edge pair<int,int>
#define MAXN 40050

int T,n,m,depth[MAXN],dist[MAXN],pa[MAXN][20],tin[MAXN],tout[MAXN],t;
vector<Edge> edges[MAXN];

void dfs(int i){
    tin[i] = t++;
    for(Edge &edge : edges[i]){
        if(depth[edge.first]) continue;
        dist[edge.first] = edge.second + dist[i];
        depth[edge.first] = depth[i] + 1;
        pa[edge.first][0] = i;
        dfs(edge.first);
    }
    tout[i] = t++;
}

bool isAncestor(int pa,int v){
    return tin[pa] <= tin[v] && tout[pa] >= tout[v];
}

int lca(int u,int v){
    if(u < v) return lca(v,u);
    if(isAncestor(v,u)) return dist[u] - dist[v];
    int maxup = 20,distu = dist[u],distv = dist[v];
    for(int i = maxup;i >= 0;i --){
        if(!isAncestor(pa[u][i],v)) u = pa[u][i];
    }
    return distu + distv - 2 * dist[pa[u][0]];
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        for(int i = 0;i < MAXN;i ++) edges[i].clear();
        memset(depth,0,sizeof depth);
        dist[1] = 0,depth[1] = 1,t = 1;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n - 1;i ++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back(make_pair(v,w));
            edges[v].push_back(make_pair(u,w));
        }
        dfs(1);
        for(int up = 1;up <= 20;up ++){
            for(int i = 1;i <= n;i ++){
                pa[i][up] = pa[pa[i][up - 1]][up - 1];
            }
        }
        for(int i = 0;i < m;i ++){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",lca(a,b));
        }
    }
}