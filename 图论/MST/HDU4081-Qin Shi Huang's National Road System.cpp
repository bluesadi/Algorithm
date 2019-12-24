#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

struct Edge{
    int u,v;
    double w;
    bool operator < (Edge& another) const {
        return w < another.w;
    }
};

const int max_n = 1005;
int t,n,x[max_n],y[max_n],p[max_n];
int pa[max_n];
double dis[max_n][max_n],map[max_n][max_n];
int visit[max_n];

void dfs(int a){
    visit[a] = true;
    for(int i = 0;i < n;i ++){
        if (map[a][i] > 0 && !visit[i]) {
            for(int j = 0;j < n;j ++) if(visit[j]){
                    dis[i][j] = dis[j][i] = max(dis[a][j],map[a][i]);
                }
            dfs(i);
        }
    }
}

int find(int a){
    return pa[a] == a ? a : pa[a] = find(pa[a]);
}

double mst(int cnt,vector<Edge>& edges,vector<Edge>& used){
    if(cnt <= 1) return 0;
    double ans = 0;
    int size = edges.size();
    for(int i = 0;i < size;i ++){
        int u = edges[i].u,v = edges[i].v;
        if((u = find(u)) != (v = find(v))){
            map[edges[i].u][edges[i].v] = map[edges[i].v][edges[i].u] = edges[i].w;
            pa[u] = v;
            ans += edges[i].w;
            used.push_back(edges[i]);
            if(-- cnt == 1) break;
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
#endif
    scanf("%d",&t);
    while(t --){
        memset(map,0,sizeof map);
        memset(dis,0,sizeof dis);
        memset(visit,0,sizeof visit);
        scanf("%d",&n);
        for(int i = 0;i < n;i ++) scanf("%d%d%d", x + i,y + i,p + i);
        vector<Edge> edges,need;
        for(int i = 0;i < n;i ++)
            for(int j = i + 1;j < n;j ++){
                double c = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                edges.push_back({i,j,c});
            }
        sort(edges.begin(),edges.end());
        for(int i = 0;i < n;i ++) pa[i] = i;
        double cost = mst(n,edges,need),ans = 0;
        int size = edges.size();
        dfs(0);
        for(int i = 0;i < size;i ++){
            for(int j = 0;j < n;j ++) pa[j] = j;
            int u = edges[i].u,v = edges[i].v;
            pa[u] = v;
            vector<Edge> empty;
            ans = max(ans,(p[edges[i].u] + p[edges[i].v]) / (cost - dis[u][v]));
        }
        printf("%.2lf\n",ans);
    }
}