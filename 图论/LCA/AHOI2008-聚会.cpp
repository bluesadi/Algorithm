#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl;
#define dot << "," <<
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define MAXN 500050

struct Edge{
    int v,next;
}edges[2 * MAXN];

int n,m,depth[MAXN],pa[MAXN][20],tin[MAXN],tout[MAXN],dist[MAXN],t = 1,cnt = 0,head[MAXN];

void addEdge(int u,int v){
    edges[++cnt].v = v;
    edges[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int i){
    tin[i] = t++;
    for(int up = 1;up < 20;up ++) pa[i][up] = pa[pa[i][up - 1]][up - 1];
    for(int k = head[i];k;k = edges[k].next){
        int v = edges[k].v;
        if(depth[v]) continue;
        dist[v] = dist[i] + 1;
        depth[v] = depth[i] + 1;
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
    if(isAncestor(u,v)) return u;
    for(int up = 19;up >= 0;up --) if(!isAncestor(pa[u][up],v)) u = pa[u][up];
    return pa[u][0];
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    depth[1] = 1;
    for(int i = 0;i < n - 1;i ++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1);
    while(m--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int l1 = lca(x,y),l2 = lca(y,z),l3 = lca(x,z);
        int l = l1 ^ l2 ^ l3;
        printf("%d %d\n",l,dist[x] + dist[y] + dist[z] - dist[l1] - dist[l2] - dist[l3]);
    }
}