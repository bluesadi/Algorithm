#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl;
#define dot << "," <<
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define LL long long

int T,n,m,pa[40050][20],depth[40050];
LL dis[40050][20];
vector<pair<int,int>> edges[40050];

void dfs(int i = 1,int d = 1){
    depth[i] = d;
    for(auto &edge : edges[i]){
        if(depth[edge.first]) continue;
        dfs(edge.first,d + 1);
        pa[edge.first][0] = i;
        dis[edge.first][0] = edge.second;
    }
}

LL lca(int a,int b){
    if(depth[a] < depth[b]) return lca(b,a);
    int maxup = 0;
    LL ans = 0;
    while((1 << (maxup + 1)) <= depth[a]) maxup ++;
    for(int i = maxup;i >= 0;i --){
        if(depth[a] - (1 << i) >= depth[b]) ans += dis[a][i],a = pa[a][i];
    }
    for(int i = maxup;i >= 0;i --){
        if(pa[a][i] != pa[b][i]){
            ans += dis[a][i];
            ans += dis[b][i];
            a = pa[a][i];
            b = pa[b][i];
        }
    }
    if(a != b) ans += dis[a][0] + dis[b][0];
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        for(int i = 0;i < 40050;i++) edges[i].clear();
        memset(pa,0,sizeof pa),memset(dis,0,sizeof dis),memset(depth,0,sizeof depth);
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n - 1;i ++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back({v,w});
            edges[v].push_back({u,w});
        }
        dfs();
        for(int i = 1;(1 << i) <= n;i ++){
            for(int j = 1;j <= n;j ++){
                pa[j][i] = pa[pa[j][i - 1]][i - 1];
                dis[j][i] = dis[j][i - 1] + dis[pa[j][i - 1]][i - 1];
            }
        }
        for(int i = 0;i < m;i ++){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%lld\n",lca(a,b));
        }
    }
}