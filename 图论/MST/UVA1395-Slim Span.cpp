#define LOCAL
#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 0x7fffffff

struct Edge{
    int u,v,w;

    bool operator < (Edge& another) const {
        return w < another.w;
    }
};

int n,m;
Edge edges[10000] = {0};
int pa[105];

int find(int a){
    if(pa[a] == a) return a;
    int result = find(pa[a]);
    return pa[a] = result;
}

int main() {
#ifdef LOCAL
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
#endif
    while(scanf("%d%d",&n,&m) == 2) {
        if(n == 0) break;
        int ans = INF;
        for (int i = 0; i < m; i++) scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        std::sort(edges, edges + m);
        for (int i = 0; i < m; i++) {
            for(int j = 0;j <= n;j ++) pa[j] = j;
            int num = 1;
            pa[edges[i].u] = edges[i].v;
            for (int j = i; j < m; j++) {
                int u = edges[j].u,v = edges[j].v;
                if (find(u) != find(v)) {
                    num++;
                    u = find(u),v = find(v);
                    pa[u] = v;
                }
                if (num == n - 1) {
                    ans = std::min(edges[j].w - edges[i].w,ans);
                    break;
                }
            }
        }
        if(ans != INF) printf("%d\n",ans);
        else printf("-1\n");
    }
}
