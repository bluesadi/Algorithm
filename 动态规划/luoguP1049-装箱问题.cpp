#include <cstdio>
#include <cstring>
#include <algorithm>

int main(){
	int V,n,vn[30 + 5] = {0},dp[20000 +5] = {0};
	scanf("%d%d",&V,&n);
	for(int i = 0;i < n;i ++){
		scanf("%d",vn + i);
	}
	for(int i = 0;i < n;i ++){//ֻ��ǰi+1����Ʒ��װ 
		for(int j = V; j >= vn[i]; j--){
			dp[j] = std::max(dp[j],dp[j-vn[i]]+vn[i]);//������õ�i+1����Ʒ��װ����ȻΪdp[j]������õ�i+1����Ʒ��װ����Ϊ dp[j-vn[i]]+vn[i]��dp[j-vn[i]]����i-1����Ʒ�� 
 		}
	}
	printf("%d\n",V - dp[V]);
}	
