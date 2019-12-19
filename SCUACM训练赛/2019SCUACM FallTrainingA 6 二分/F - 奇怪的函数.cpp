#include<cstdio>
#include<cmath>

int n;

int binarySearch(int min,int max){
	int mid = (max + min) / 2;
	if(min == max){
		return mid;
	}
	if(mid * log10(mid) >= n - 1 && (mid - 1)* log10(mid - 1) < n - 1){
		return mid;
	}else if(mid * log10(mid) >= n - 1){
		binarySearch(min,mid);
	}else{
		binarySearch(mid,max);	
	}
}

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	scanf("%d",&n);
	int x = 1;
	int min = sqrt(n),max = pow(10,min);
	printf("%d\n",binarySearch(min,max));
} 
