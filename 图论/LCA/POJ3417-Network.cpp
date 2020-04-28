#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl;
#define dot << "," <<
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define MAXN 100050

int n,m,depth[MAXN],pa[MAXN][20],tin[MAXN],tout[MAXN],t = 1,cover[MAXN],visit[MAXN],ans = 0,head[MAXN],cnt = 0;

struct Edge{
    int v,next;
}edges[2 * MAXN];

void addEdge(int x,int y){
    edges[++cnt].v = y;
    edges[cnt].next = head[x];
    head[x] = cnt;
}

void pre_dfs(int i){
    tin[i] = t++;
    for(int up = 1;up < 20;up ++) pa[i][up] = pa[pa[i][up - 1]][up - 1];
    for(int k = head[i];k;k = edges[k].next){
        int v = edges[k].v;
        if(depth[v]) continue;
        pa[v][0] = i;
        depth[v] = depth[i] + 1;
        pre_dfs(v);
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
    for(int up = 19;up >= 0;up--) if(!isAncestor(pa[u][up],v)) u = pa[u][up];
    return pa[u][0];
}

void dfs(int i){
    visit[i] = 1;
    for(int k = head[i];k;k = edges[k].next){
        int v = edges[k].v;
        if(visit[v]) continue;
        dfs(v);
        cover[i] += cover[v];
    }
    if(cover[i] == 0) ans += m;
    else if(cover[i] == 1) ans++;
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    depth[1] = 1;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n - 1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    pre_dfs(1);
    for(int i = 0;i < m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        cover[u]++,cover[v]++,cover[lca(u,v)] -= 2;
    }
    visit[1] = 1;
    for(int k = head[1];k;k = edges[k].next){
        int v = edges[k].v;
        dfs(v);
    }
    printf("%d\n",ans);
}