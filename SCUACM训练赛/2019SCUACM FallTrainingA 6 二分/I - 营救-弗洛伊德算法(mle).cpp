#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f

int n,m,s,t; 
int g[10001][10001];


int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	memset(g,0x3f,sizeof g);
	for(int i = 1;i <= m;i ++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u][v] = w;
		g[v][u] = w;
		g[i][i] = 0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j] = std::min(std::max(g[i][k],g[k][j]),g[i][j]);
			}
		}
	}  
	printf("%d\n",g[s][t]);
}
