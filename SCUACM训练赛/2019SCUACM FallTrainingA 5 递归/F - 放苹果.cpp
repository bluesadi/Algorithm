#include <cstdio>
#include <algorithm>
#include <cstring>

int ans = 0;
int M,N;

void dfs(int alreadySum,int turn,int last){
	if(turn == N){
		if(alreadySum == M){
			ans ++;
		}
		return;
	}
	for(int i = last;i <= M - alreadySum;i ++){
		dfs(alreadySum + i,turn + 1,i);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t --){
		scanf("%d%d",&M,&N);
		ans = 0;
		dfs(0,0,0);
		printf("%d\n",ans);
	}
}
