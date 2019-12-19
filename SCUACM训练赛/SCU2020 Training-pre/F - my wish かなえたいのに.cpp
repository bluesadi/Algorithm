#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

struct Node{
	int index;
	ll a,b,c; 
	
	bool operator < (Node& node) const{
		ll l = (a + b) * node.c,r = (node.a + node.b) * c;
		if(l == r){
			return index < node.index;
		}else{
			return l < r;
		}
	}
	
}; 

int n;
Node nodes[(int)1e3 +5] = {0};

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    while(scanf("%d",&n) != EOF){
		for(int i = 1;i <= n;i ++){
			ll a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			nodes[i - 1] = {i,a,b,c};
		}
		sort(nodes,nodes + n);
		for(int i = 0;i < n;i ++){
			printf("%d",nodes[i].index);
			printf(i == n - 1 ? "\n" : " ");
		}
	}
} 
