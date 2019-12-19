#include <cstdio>
#include <cstring>
#define ll long long

int main(){
	int n;
	scanf("%d",&n);
	ll ans[n + 1];
	memset(ans,0,sizeof ans);
	ans[0] = 1;
	ans[1] = 1;
	for(int i = 2;i <= n;i ++){
		for(int j = 0;j <= i - 1;j ++){
			ans[i] += ans[j] * ans[i - j - 1];
		}
	}
	printf("%lld\n",ans[n]);
} 
