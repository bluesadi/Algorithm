#define LOCAL
#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};

int t,n,m;
Edge edges[10000] = {0};
int pa[105];
vector<int> used;

int find(int a){
    return pa[a] == a ? a : pa[a] = find(pa[a]);
}

int mst(int cnt,int exclude){
    for(int i = 1;i <= n;i ++) pa[i] = i;
    if(cnt <= 1) return 0;
    int ans = 0;
    for(int i = 0;i < m;i ++){
        if(exclude == i) continue;
        int u = edges[i].u, v = edges[i].v;
        if ((u = find(u)) != (v = find(v))) {
            pa[u] = v;
            ans += edges[i].w;
            if(exclude == -1) used.push_back(i);
            if(--cnt == 1) break;
        }
    }
    return cnt <= 1 ? ans : 0;
}

int main(){
#ifdef LOCAL
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
#endif
    scanf("%d",&t);
    while(t --) {
        used.clear();
        scanf("%d%d", &n, &m);
        for(int i = 0;i < m;i ++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            edges[i] = {a,b,c};
        }
        sort(edges,edges + m);
        int first = mst(n,-1),second = 0x7fffffff;
        for(int i : used){
            int ans = mst(n,i);
            if(ans != 0) second = min(ans,second);
        }
        printf("%d %d\n",first,second);
    }
}