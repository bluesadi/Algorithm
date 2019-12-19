#include<cstdio>
#define ll long long
using namespace std;

ll papers[(int)1e5 + 5];
int n;

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    while(scanf("%d",&n) != EOF){
		for(int i = 0;i <= n;i ++){
			scanf("%lld",papers + i);
		}
		papers[n + 1] = 0;
		for(int i = n;i >= 0;i --){
			papers[i] += papers[i + 1];
		}
		int ans = 0;
		for(int i = n;i >= 0;i --){
			if(papers[i] >= i){
				ans = i;
				break;
			}
		} 
		printf("%d\n",ans);
	}
} 
