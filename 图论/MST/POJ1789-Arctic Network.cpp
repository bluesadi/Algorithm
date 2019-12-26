#define LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Edge{
    int u, v;
    double w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};

int N,S,P,x[505],y[505],pa[505];
vector<Edge> edges;

int find(int a){
    return pa[a] == a ? a : pa[a] = find(pa[a]);
}

double mst(int cnt){
    for(int i = 0;i < P;i ++) pa[i] = i;
    if(cnt <= 1) return 0;
    int size = edges.size();
    for(int i = 0;i < size;i ++){
        int u = edges[i].u, v = edges[i].v;
        if ((u = find(u)) != (v = find(v))) {
            pa[u] = v;
            if(--cnt == 1) return edges[i].w;
        }
    }
    return 0;
}

int main() {
#ifdef LOCAL
    freopen("D:/ACM/AlgorithmStudy/test.in", "r", stdin);
#endif
    scanf("%d",&N);
    while(N--){
        edges.clear();
        scanf("%d%d",&S,&P);
        for(int i = 0;i < P;i ++){
            scanf("%d%d",x + i,y + i);
        }
        for(int i = 0;i < P;i ++){
            for(int j = i + 1;j < P;j ++){
                edges.push_back({i,j,sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))});
            }
        }
        sort(edges.begin(),edges.end());
        printf("%.2f\n",mst(P - S + 1));
    }
}