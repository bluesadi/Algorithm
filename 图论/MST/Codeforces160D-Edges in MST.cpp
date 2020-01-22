#define LOCAL
#include<bits/stdc++.h>
#define Pair pair<int, int>
#define MP(x, y) make_pair(x, y)
using namespace std;

struct Edge{
    int u, v, w, f, id;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};

const int max_n = 1e5 + 10;
int n,m;
vector<Pair> v[max_n];
int dfn[max_n], low[max_n], tot, fa[max_n], ans[max_n];
Edge edges[max_n];

void tarjan(int x, int f){//这里的f表示边的编号
    dfn[x] = low[x] = ++tot;
    for(int i = 0, to, id; i < v[x].size(); i++) {
        if((id = v[x][i].second) == f) continue;
        to = v[x][i].first;
        if(!dfn[to]) {
            tarjan(to, id), low[x] = min(low[x], low[to]);
            if(low[to] > dfn[x]) edges[id].f = 2;
        }
        else low[x] = min(low[x], dfn[to]);
    }
}

int find(int x){
    return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

int main(){
#ifdef LOCAL
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edges[i] = {x, y, z, 0, i};
    }
    sort(edges + 1, edges + m + 1);
    int nxt;
    for(int i = 1; i <= m; i = nxt + 1) {
        nxt = i + 1;
        for(; edges[i].w == edges[nxt].w; nxt++); nxt--;
        for(int j = i; j <= nxt; j++) {
            int x = find(edges[j].u), y = find(edges[j].v);
            if(x == y) continue;
            v[x].push_back(MP(y, j));
            v[y].push_back(MP(x, j));
            edges[j].f = 1;//maybe
        }
        for(int j = i; j <= nxt; j++) {
            int x = find(edges[j].u), y = find(edges[j].v);
            if(x == y || dfn[x]) continue;
            tarjan(x, -1);
        }
        for(int j = i; j <= nxt; j++) {
            int x = find(edges[j].u), y = find(edges[j].v);
            if(x == y) continue;
            v[x].clear(); v[y].clear();
            dfn[x] = 0; dfn[y] = 0;
            fa[x] = y;
        }
    }
    for(int i = 1; i <= m; i++) ans[edges[i].id] = edges[i].f;
    for(int i = 1; i <= m; i++) {
        if(ans[i] == 0) puts("none");
        else if(ans[i] == 1) puts("at least one");
        else puts("any");
    }
    return 0;
}