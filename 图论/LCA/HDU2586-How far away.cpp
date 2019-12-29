#define LOCAL
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
#define Pair pair<int,int>

struct Edge{
    int u,v;
    ll w;
};
const int max_n = 40005;
int T,n,m;
vector<Edge> vec[max_n];
vector<int> query[max_n];
int fa[max_n],visit[max_n],finish[max_n];
ll dis[max_n],ans[max_n];
Pair queries[205];

int find(int a){
    return a == fa[a] ? a : fa[a] = find(fa[a]);
}

void dfs(int u){
    visit[u] = 1;
    for(Edge& edge : vec[u]){
        int v = edge.v;
        if(!visit[v]){
            dis[v] = dis[u] + edge.w;
            dfs(v);
            fa[v] = u;
        }
    }
    for(int t : query[u]){
        if(finish[t])
            for(int i = 0;i < m;i ++){
                Pair& pair = queries[i];
                if((pair.first == u && pair.second == t) || (pair.first == t && pair.second == u)) ans[i] = dis[t] + dis[u] - 2 * dis[find(t)];
            }
    }
    finish[u] = 1;
}

int main() {//觉得代码写得很丑，改天看看能不能改进
#ifdef LOCAL
    freopen("D:/ACM/AlgorithmStudy/test.in", "r", stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i ++){
            fa[i] = i;
            vec[i].clear();
            query[i].clear();
        }
        memset(visit,0,sizeof visit);
        memset(dis,0,sizeof dis);
        memset(finish,0,sizeof finish);
        memset(ans,0,sizeof ans);
        for(int i = 0;i < n - 1;i ++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            vec[u].push_back({u,v,w});
            vec[v].push_back({v,u,w});
        }
        for(int i = 0;i < m;i ++){
            int s,t;
            scanf("%d%d",&s,&t);
            query[s].push_back(t);
            query[t].push_back(s);
            queries[i] = make_pair(s,t);
        }
        dfs(1);
        for(int i = 0;i < m;i ++) printf("%d\n",ans[i]);
    }
}