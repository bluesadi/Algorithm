#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#define dot << "," <<
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define Edge pair<int,int>
#define MAXN 40050

int n,m,pa[MAXN][20],dist[MAXN],depth[MAXN],tin[MAXN],tout[MAXN],t = 1;
vector<Edge> edges[MAXN];

void dfs(int i){
    tin[i] = t++;
    for(int up = 1;up < 20;up ++) pa[i][up] = pa[pa[i][up - 1]][up - 1];
    for(Edge &edge : edges[i]){
        int v = edge.first,w = edge.second;
        if(depth[v]) continue;
        depth[v] = depth[i] + 1;
        dist[v] = dist[i] + w;
        pa[v][0] = i;
        dfs(v);
    }
    tout[i] = t++;
}

bool isAncestor(int u,int v){
    if(!u) return true;
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u,int v){
    if(depth[u] > depth[v]) return lca(v,u);
    if(isAncestor(u,v)) return dist[v] - dist[u];
    int distu = dist[u],distv = dist[v];
    for(int up = 19;up >= 0;up--) if(!isAncestor(pa[u][up],v)) u = pa[u][up];
    return distu + distv - 2 * dist[pa[u][0]];
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i = 0;i < MAXN;i++) edges[i].clear();
    memset(pa,0,sizeof pa),memset(dist,0,sizeof dist),memset(depth,0,sizeof depth);
    depth[1] = 1;
    for(int i = 0;i < n - 1;i ++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        edges[x].push_back(make_pair(y,w));
        edges[y].push_back(make_pair(x,w));
    }
    dfs(1);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",lca(u,v));
    }
}