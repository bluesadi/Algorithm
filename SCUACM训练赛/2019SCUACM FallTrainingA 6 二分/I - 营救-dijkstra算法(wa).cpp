#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
#include<queue>

using std::vector;
using std::priority_queue;
using std::queue;

struct Edge{
	int to;
	int w;
	
	bool operator < (const Edge& another) const{
		return w > another.w;
	}
	
};

struct Node{
	priority_queue<Edge> que;
};

int n,m,s,t; 
int visit[10005] = {0};
int ans[10005];
Node table[10005];

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	memset(ans,0x3f,sizeof ans);
	for(int i = 1;i <= n;i ++) table[i] = Node();
	ans[s] = 0;
	for(int i = 1;i <= m;i ++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		table[u].que.push({v,w});
		table[v].que.push({u,w});
	}
	queue<int> que;
	que.push(s),visit[s] = 1;
	while(!que.empty()){
		int v = que.front();
		que.pop();
		visit[v] = 1;
		priority_queue<Edge> &edges = table[v].que;
		while(!edges.empty()){
			Edge edge = edges.top();
			edges.pop();
			if(!visit[edge.to]){	//printf("debug:%d,%d\n",v,edge.to);
				ans[edge.to] = std::min(std::max(ans[v],edge.w),ans[edge.to]);
				que.push(edge.to);
			}
		}
	}
	printf("%d\n",ans[t]);
}
