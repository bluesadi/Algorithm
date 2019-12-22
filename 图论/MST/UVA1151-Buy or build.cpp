#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct Edge{
    int u,v,w;
    bool operator < (Edge& another) const {
        return w < another.w;
    }
};

const int max_n = 1005;
int t,n,q;
int cost[10],x[max_n],y[max_n];
vector<int> subn[10];
int pa[max_n];

int find(int a){
    /*if(pa[a] == a) return a;
    int result = find(pa[a]);
    return pa[a] = result;*/
    //简化版
    return pa[a] == a ? a : pa[a] = find(pa[a]);
}

int mst(int cnt,vector<Edge>& edges,vector<Edge>& used){
    if(cnt <= 1) return 0;
    int ans = 0,size = edges.size();
    for(int i = 0;i < size;i ++){
        int u = edges[i].u,v = edges[i].v;
        if((u = find(u)) != (v = find(v))){
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
        scanf("%d%d",&n,&q);
        for(int i = 0;i < q;i ++){
            int num;
            scanf("%d%d",&num,cost + i);
            subn[i].clear();
            for(int j = 0;j < num;j ++){
                int c;
                scanf("%d",&c);
                subn[i].push_back(c - 1);
            }
        }
        for(int i = 0;i < n;i ++) scanf("%d%d",x + i,y + i);
        vector<Edge> edges,need;
        for(int i = 0;i < n;i ++)
            for(int j = i + 1;j < n;j ++){
                edges.push_back({i,j,(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])});
            }
        for(int i = 0;i < n;i ++) pa[i] = i;
        sort(edges.begin(),edges.end());
        int ans = mst(n,edges,need);
        for(int b = 0;b < (1 << q);b ++){
            for(int i = 0;i < n;i ++) pa[i] = i;
            int c = 0,num = n;
            for(int i = 0;i < q;i ++) if(b & (1 << i)){
                    c += cost[i];
                    int size = subn[i].size();
                    for(int j = 1;j < size;j ++){
                        int u = find(subn[i][0]),v = find(subn[i][j]);
                        if(u != v){
                            pa[v] = u;
                            num --;
                        }
                    }
                }
            vector<Edge> empty;
            ans = min(ans,c + mst(num,need,empty));
        }
        printf("%d\n",ans);
        if(t) printf("\n");
    }
}