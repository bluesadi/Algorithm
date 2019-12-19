#include <cstdio>
#include <cstring>
#include <algorithm>

int main(){
	int V,n,vn[30 + 5] = {0},dp[20000 +5] = {0};
	scanf("%d%d",&V,&n);
	for(int i = 0;i < n;i ++){
		scanf("%d",vn + i);
	}
	for(int i = 0;i < n;i ++){//只用前i+1种物品来装 
		for(int j = V; j >= vn[i]; j--){
			dp[j] = std::max(dp[j],dp[j-vn[i]]+vn[i]);//如果不用第i+1种物品来装，仍然为dp[j]，如果用第i+1种物品来装，就为 dp[j-vn[i]]+vn[i]，dp[j-vn[i]]是用i-1种物品填 
 		}
	}
	printf("%d\n",V - dp[V]);
}	
