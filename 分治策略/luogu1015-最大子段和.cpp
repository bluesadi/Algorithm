#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	int sum = 0,maxSum = -(int)1e5; 
	scanf("%d",&n);
	while(n --){
		int a;
		scanf("%d",&a);
		sum = max(0,sum);
		sum+= a;
		maxSum = max(maxSum,sum);
	}
	printf("%d\n",maxSum);
} 
