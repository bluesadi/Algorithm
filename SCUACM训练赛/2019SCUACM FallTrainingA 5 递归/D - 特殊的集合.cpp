#include <cstdio>
#include <algorithm>
#include <cstring>


int eval(int n){
	if(n == 0){
		return 0;
	}
	if((n & 1) == 1){
		return eval(n - 1) + 1;
	}else{
		return eval(n / 4) + n / 2;
	}
}


int main(){
	int n,ans;
	scanf("%d",&n);
	printf("%d\n",eval(n));
}

