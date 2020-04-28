#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl;
#define dot << "," <<
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define LL long long
#define MAXN 100050
#define Edge pair<int,int>
#define SIT set<int,comp>::iterator

int n,m,depth[MAXN],tin[MAXN],tout[MAXN],pa[MAXN][20],t = 1;
LL dist[MAXN],ans = 0;
vector<Edge> edges[MAXN];

struct comp{
    bool operator() (int x,int y) const{
        return tin[x] < tin[y];
    }
};

set<int,comp> S;

void dfs(int i){
    tin[i] = t++;
    for(int up = 1;up < 20;up ++) pa[i][up] = pa[pa[i][up - 1]][up - 1];
    for(Edge &edge : edges[i]){
        int v = edge.first,w = edge.second;
        if(depth[v]) continue;
        dist[v] = dist[i] + w;
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

SIT leftOf(int x){
    SIT xit = S.find(x);
    if(xit == S.begin()) return --S.end();
    return --xit;
}

SIT rightOf(int x){
    SIT xit = S.find(x);
    if(++xit == S.end()) return S.begin();
    return xit; 
}

LL diff(int u,int v){
    return dist[u] + dist[v] - 2 * dist[lca(u,v)];
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&n);
    depth[1] = 1;
    for(int i = 0;i < n - 1;i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    dfs(1);
    scanf("%d",&m);
    while(m--){
        char t[5];
        int x;
        scanf("%s",t);
        if(t[0] == '+'){
            scanf("%d",&x);
            S.insert(x);
            SIT lit = leftOf(x),rit = rightOf(x);
            ans -= diff(*lit,*rit);
            ans += diff(*lit,x) + diff(*rit,x);
        }else if(t[0] == '-'){
            scanf("%d",&x);
            SIT lit = leftOf(x),rit = rightOf(x);
            ans += diff(*lit,*rit);
            ans -= diff(*lit,x) + diff(*rit,x);
            S.erase(x);
        }else{
            printf("%lld\n",ans / 2);
        }
    }
}