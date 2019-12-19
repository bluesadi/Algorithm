#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using std::vector;

int T,N;
ll A,B;
vector<int> primes;
vector<int> vec;

void pre(int N){
	//求出全部质因子 
	primes.clear();
	for(int i = 2;i * i <= N;i ++){
		if(N % i == 0){
			primes.push_back(i);
			while(N % i == 0) N /= i;
		}
	}
	if(N > 1) primes.push_back(N);
	//这一段处理很重要 
	//????
    int vec_size;
    vec.clear();
    for(int i = 0; i < primes.size(); i ++){
	    vec_size = vec.size();
	    for(int j = 0; j < vec_size; j ++){
	        vec.push_back(vec[j] * primes[i]);
	    }
	    vec.push_back(primes[i]);
    }
}

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    scanf("%d",&T);
    for(int i = 1;i <= T;i ++){
		scanf("%lld%lld%d",&A,&B,&N);
		pre(N);
		ll a = A - 1,b = B;
		int flag = 1;
		for(int &p : vec){
			a -= flag * (A - 1) / p;
			b -= flag * B / p;
			flag = -flag;
		}	 
		printf("Case #%d: %lld\n",i,b - a);
	}
}
