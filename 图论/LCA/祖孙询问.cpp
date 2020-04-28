#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#define dot << "," <<
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 40050

int n,m,visit[MAXN],tin[MAXN],tout[MAXN],t = 1,root,head[MAXN],cnt = 0;

struct Edge{
    int v,next;
}edges[2 * MAXN];

void addEdge(int x,int y){
    edges[++cnt].v = y;
    edges[cnt].next = head[x];
    head[x] = cnt;
}

void dfs(int i){
    tin[i] = t++;
    visit[i] = 1;
    for(int k = head[i];k;k = edges[k].next){
        int v = edges[k].v;
        if(visit[v]) continue;
        dfs(v);
    }
    tout[i] = t++;
}

bool isAncestor(int u,int v){
    if(!u) return true;
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&n);
    memset(visit,0,sizeof visit);
    for(int i = 0;i < n;i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(y == -1){
            root = x;
            continue;
        }
        addEdge(x,y);
        addEdge(y,x);
    }
    dfs(root);
    scanf("%d",&m);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        if(isAncestor(u,v)) printf("1\n");
        else if(isAncestor(v,u)) printf("2\n");
        else printf("0\n");
    }
}