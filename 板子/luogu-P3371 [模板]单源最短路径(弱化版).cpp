#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Edge{ int v,w; };

struct Node{
    int x,dist;
    bool operator < (const Node& other) const{
        return dist > other.dist;
    }
};

int n,m,s,ans[10050],visit[10050];
vector<Edge> edges[10050];

void dijkstra(){
    priority_queue<Node> que;
    que.push({s,0});
    while(!que.empty()){
        Node node = que.top();que.pop();
        if(visit[node.x]) continue;
        visit[node.x] = 1;
        ans[node.x] = node.dist;
        for(Edge& edge : edges[node.x]) que.push({edge.v,edge.w + node.dist});
    }
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 0;i < m;i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges[u].push_back({v,w});
    }
    fill_n(visit,n + 50,0);
    fill_n(ans,n + 50,(1u << 31) - 1);
    dijkstra();
    for(int i = 1;i <= n;i ++) printf(i == n ? "%d\n" : "%d ",ans[i]);
}