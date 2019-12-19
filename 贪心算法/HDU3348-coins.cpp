#include<cstdio>
#include<algorithm>
#include<queue>

int coins[5] = {1,5,10,50,100};
int nums[5];
int max(int price){
	int ans = 0,sum = 0;
	std::queue<int> que;
	for(int i = 4;i >= 0;i--){
		for(int j = 0;j < nums[i];j ++){
			que.push(coins[i]);
		}
	}
	while(!que.empty()){
		int v = que.front();
		que.pop();
		if(v <= price - sum){
			sum += v;
			ans ++;
		}
		if(sum == price) break;
	}
	return sum == price ? ans : -1;	
}

int main(){
	//freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	int T,price;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d %d %d",&price,nums,nums + 1,nums + 2,nums + 3,nums + 4);
		int total = 0,n = 0;
		for(int i = 0;i < 5;i ++){
			n += nums[i];
			total += nums[i] * coins[i];
		}		
		int temp = max(total - price);
		printf("%d %d\n",max(price),temp == -1 ? -1 : n - temp);
	}
} 
