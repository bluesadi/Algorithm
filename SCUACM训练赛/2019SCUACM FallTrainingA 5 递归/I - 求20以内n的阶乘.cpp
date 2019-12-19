#include <cstdio>
#include <algorithm>
#include <cstring>

int main(){
	int n;
	scanf("%d",&n);
	long long f = 1;
	for(int i = 2;i <= n;i ++){
		f *= i;
	}
	printf("%lld\n",f);
}
