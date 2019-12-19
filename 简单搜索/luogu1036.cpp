#include <iostream>
#include <cmath>

int numbers[25];

bool isPrime(int num){
	int q = (int)sqrt(num);
	for(int i = 2;i <= q;i ++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}

int dfs(int k,int start,int end,int alreadySum){
	if(k == 0){
		return isPrime(alreadySum);
	}
	int sum = 0;
	for(int i = start;i <= end;i ++){
		sum += dfs(k - 1,i + 1,end,alreadySum + numbers[i]); 
	}
	return sum; 
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 0;i < n;i ++){
		scanf("%d",numbers + i);
	}
	printf("%d",dfs(k,0,n - 1,0));
} 
