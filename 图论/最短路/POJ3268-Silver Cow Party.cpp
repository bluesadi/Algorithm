#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge{
    int v,w;
};

struct Node{
    int x,d;
    bool operator < (const Node& node) const{
        return d > node.d;
    }
};

int N,M,X,visit[1005],s[1005][1005];
vector<Edge> vec[1005];

int main(){
    ms(s,inf),scanf("%d%d%d",&N,&M,&X);
    for(int i = 1;i <= M;i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        vec[u].push_back({v,w});
    }
    for(int i = 1;i <= N;i ++){
        ms(visit,0);
        priority_queue<Node> que;
        que.push({i,0});
        s[i][i] = 0;
        while(!que.empty()){
            int x = que.top().x,d = que.top().d;que.pop();
            if(visit[x]) continue;
            visit[x] = 1;
            //这一段可以稍微改进提升效率
            s[i][x] = d;
            for(vector<Edge>::iterator it = vec[x].begin();it != vec[x].end();it++) que.push({it->v,it->w + d});
        }
    }
    int ans = 0;
    for(int i = 1;i <= N;i++){
        ans = max(ans,s[i][X] + s[X][i]);
    }
    printf("%d\n",ans);
}