#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
#include<queue>

using std::vector;
using std::queue;

struct Edge{
	int from;
	int to;
	int w;
	
	bool operator < (const Edge& another) const{
		return w < another.w;
	}
	
}edges[20005];

struct Node{
	vector<Edge> que;
	int ans = 0;
};

int n,m,s,t,k = 0,ans = 0; 
bool finish = false;
int pre[10005];
Node nodes[10005];
int visit[10005] = {0};

int find(int n){
	if(n == pre[n]){
		return n;
	}
	int r = find(pre[n]);
	return pre[n] = r;
}

void merge(int a,int b){
	a = find(a);
	b = find(b);
	pre[a] = b;
}

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i = 1;i <= n;i ++) pre[i] = i;
	for(int i = 1;i <= m;i ++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edges[i] = {u,v,w};
	}
	std::sort(edges + 1,edges + m + 1);
	for(int i = 1;i <= m;i ++){
		Edge &edge = edges[i];
		int from = edge.from,to = edge.to;
		if(find(from) != find(to)){
			merge(from,to);
			if(find(s) == find(t)){
				ans = edge.w;
				break;
			}
			k ++;
		}
		if(k == n - 1) break;
	}
	printf("%d\n",ans);
}
