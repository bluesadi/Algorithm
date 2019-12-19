#include<cstdio>
#include<algorithm>
using std::sort;

int binarySearch(int *arr,int begin,int end,int tar){
	if(begin >= end){
		return 0; 
	} 
	int mid = (begin + end) / 2;
	if(arr[mid] == tar){
		int sum = 1;
		for(int i = 1;arr[mid + i] == tar && mid + i < end;i ++){
			sum ++;
		}
		for(int i = 1;arr[mid - i] == tar && mid + i >= begin;i ++){
			sum ++;
		}
		return sum;
	}else if(arr[mid] > tar){
		return binarySearch(arr,begin,mid,tar);
	}else{
		return binarySearch(arr,mid + 1,end,tar);
	}
}

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	int arr[n + 5];
	for(int i = 0;i < n;i ++){
		scanf("%d",arr + i);
	}
	sort(arr,arr + n);
	while(m --){
		int x;
		scanf("%d",&x);
		printf("%d\n",binarySearch(arr,0,n,x));
	}
} 
