#include<cstdio>
#include<algorithm>
using std::sort;


int ans(int n){
	if(n == 1){
		return 0;
	}
	if(n % 2 == 0){
		return ans(n / 2) + 1;
	}else{
		return ans(n / 2) + 2; 
	}
}

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	int n;
	scanf("%d",&n);
	while(n --){
		int v;
		scanf("%d",&v);
		printf("%d\n",ans(v));
	}
} 
