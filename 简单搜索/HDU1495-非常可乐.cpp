#include<cstdio>
#include<cstring>
#include<algorithm>

int ans = 1e5;
int S,N,M;

int visit[101][101][101];

void dfs(int a,int b,int c,int step){
	if((a == b && a > 0 && b > 0 && c == 0) || (a == c && a > 0 && c > 0 && b == 0) || (b == c && b > 0 && c > 0 && a == 0)){
		ans = std::min(ans,step);
		//printf("%d,%d,%d\n",a,b,c);
		return;
	}
	visit[a][b][c] = 1;
	//a->b a->c b->c b->a c->b c->a 6种情况
	if(a + b <= N){//a->b 
		if(!visit[0][a + b][c]){	
			dfs(0,a + b,c,step + 1);
		}
	}else{
		if(!visit[a - N + b][N][c]){
			dfs(a - N + b,N,c,step + 1);
		}
	}
	if(a + c <= M){
		if(!visit[0][b][a + c]){
			dfs(0,b,a + c,step + 1);
		}
	}else{
		if(!visit[a - M + c][b][M]){
			dfs(a - M + c,b,M,step + 1);
		}
	}
	if(b + c <= M){
		if(!visit[a][0][b + c]){
			dfs(a,0,b + c,step + 1);
		}
	}else{
		if(!visit[a][b - M + c][M]){
			dfs(a,b - M + c,M,step + 1);
		}
	}
	if(b + a <= S){
		if(!visit[b + a][0][c]){
			dfs(b + a,0,c,step + 1);
		}
	}else{
		if(!visit[S][a - S + b][c]){
			dfs(a,a - S + b,c,step + 1);
		}
	}
	if(c + b <= N){//c ->b
		if(!visit[a][c + b][0]){
			dfs(a,c + b,0,step + 1);
		}
	}else{
		if(!visit[a][N][b - N + c]){
			dfs(a,N,b - N + c,step + 1);
		}
	}
	if(c + a <= S){
		if(!visit[c + a][b][0]){
			dfs(c + a,b,0,step + 1);
		}
	}else{
		if(!visit[S][b][a - S + c]){
			dfs(S,b,a - S + c,step + 1);
		}
	}
	visit[a][b][c] = 0;
}	

int main(){
	//freopen("D:/ACM/cpp源文件/test.in","r",stdin);
	while(scanf("%d%d%d",&S,&N,&M)){
		if(S == 0) break;
		memset(visit,0,sizeof visit);
		ans = 1e5;
		if((S & 1) == 0){
			
			dfs(S,0,0,0);
		}
		if(ans == (int)1e5){
			printf("NO\n");
		}else{
			printf("%d\n",ans);
		}
	}
} 
