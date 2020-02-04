#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Edge{
    int v,w;
};

struct Node{
    int x,dis;
    bool operator < (const Node& node) const {
        return dis > node.dis;
    }
};

int ans[1005],N,T,visit[1005];
vector<Edge> edges[1005];

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%d",&T,&N);
    ms(visit,0);
    for(int i = 0;i < T;i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges[u].push_back({v,w}),edges[v].push_back({u,w});
    }
    priority_queue<Node> que;
    que.push({N,0});
    while(!que.empty()){
        Node first = que.top();que.pop();
        if(visit[first.x]) continue;
        visit[first.x] = 1;
        ans[first.x] = first.dis;
        for(vector<Edge>::iterator it = edges[first.x].begin();it != edges[first.x].end();it++) 
            que.push({it->v,it->w + first.dis});
    }
    printf("%d\n",ans[1]);
}