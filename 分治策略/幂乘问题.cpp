#include <iostream>
#include <cstring>
#define ll long long

ll pow_(int a,int k){
	int ans = 1;
	for(int i = 0;i < k;i ++){
		ans *= a;
	}
	return ans;
}

ll pow(int a,int k){
	if(k == 1){
		return a;
	}
	int r = pow(a,k / 2);
	if(k & 1){
		return r * r * a;
	}else{
		return r * r;
	}
}

int main(){
	printf("ans1:%lld,ans2:%lld\n",pow_(2,30),pow(2,30));
} 

