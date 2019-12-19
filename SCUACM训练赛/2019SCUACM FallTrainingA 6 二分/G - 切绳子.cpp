#include<cstdio>
#include<cmath>
#define ll long long

int n,m,arr[10005];

int binarySearch(int min,int max){
	int mid = (max + min) / 2;
	if(min == max){
		return mid;
	}
	int sum1 = 0,sum2 = 0;
	for(int i = 0;i < n;i ++){
		sum1 += arr[i] / mid;
		sum2 += arr[i] / (mid + 1);
	}
	if(sum1 == m && sum2 < m){
		return mid;
	}else if(sum1 >= m){
		binarySearch(mid,max);
	}else{
		binarySearch(min,mid);
	}
}

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	scanf("%d%d\n",&n,&m);
	long long sum = 0;
	for(int i = 0;i < n;i ++){
		double a;
		scanf("%lf",&a);
		arr[i] = a * 100 + 0.00001;
		sum += arr[i];
	} 
	int max = sum / m + 1,min = 0;
	printf("%.2f\n",binarySearch(min,max) / 100.0);
} 
