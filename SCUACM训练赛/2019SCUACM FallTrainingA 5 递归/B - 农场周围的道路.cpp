#include <cstdio>
#include <algorithm>
#include <cstring>

int N,K;
int ans = 0;

void judge(int n){
	if(((n - K) & 1) == 0 && (n - K) / 2 > 0){
		judge((n - K) / 2);
		judge((n + K) / 2);
	}else{
		ans ++;
	}
}

int main(){
	scanf("%d%d",&N,&K);
	judge(N);
	printf("%d\n",ans);
}
