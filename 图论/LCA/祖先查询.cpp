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

int n,m,visit[MAXN],tin[MAXN],tout[MAXN],t = 1,root;
vector<int> edges[MAXN];

void dfs(int i){
    tin[i] = t++;
    visit[i] = 1;
    for(int v : edges[i]){
        if(visit[v]) continue;
        dfs(v);
    }
    tout[i] = t++;
}

bool isAncestor(int u,int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0;i < MAXN;i++) edges[i].clear();
    memset(visit,0,sizeof visit);
    for(int i = 0;i < n;i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(y == -1){
            root = x;
            continue;
        }
        edges[x].push_back(y);
        edges[y].push_back(x);
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