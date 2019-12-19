#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long

double p,q;
int ans = (int)1e9;

bool binarySearch(int min,int max){
	int mid = (max + min) / 2;
	if(min >= max){
		if((int)(mid * p / 100) < (int)(mid * q / 100)){
			ans = std::min(ans,mid);
			return  true;
		}else{
			return false;
		}
	}
	//printf("debug%d,%d\n",min,max);
	if((int)(mid * p / 100) < (int)(mid * q / 100)){
		ans = std::min(ans,mid);
		binarySearch(min,mid - 1);
		return true;
	}else{
		if(!binarySearch(min,mid - 1)){
			return binarySearch(mid + 1,max);
		}
	}
}

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	scanf("%lf%lf",&p,&q);
	int max = 200 / (q - p),min = 1;
	binarySearch(min,max);
	printf("%d\n",ans);
}
