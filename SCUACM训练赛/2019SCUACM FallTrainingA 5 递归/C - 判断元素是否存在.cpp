#include <cstdio>
#include <algorithm>
#include <cstring>

int judge[(int)1e5 + 5];

int gen(int n){
	if(n <= 1e5){
		judge[n] = 1;
		gen(2 * n + 1);
		gen(3 * n + 1);
	}
}

int main(){
	int n,x;
	scanf("%d,%d",&n,&x);
	gen(n);
	printf(judge[x] ? "YES" : "NO");
}
