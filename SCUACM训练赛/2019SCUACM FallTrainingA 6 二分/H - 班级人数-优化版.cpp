#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f

double p,q;
int ans = INF;

void binarySearch(int l,int r){
	if(l > r) return;
	int mid = (l + r) / 2;
	if((int)(mid * p / 100) < (int)(mid * q / 100)){
		ans = std::min(mid,ans);
		binarySearch(l,mid - 1);
	}else{
		binarySearch(l,mid - 1);
		binarySearch(mid + 1,r); 
	} 
}

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	scanf("%lf%lf",&p,&q);
	binarySearch(1,INF);
	printf("%d\n",ans);
}
