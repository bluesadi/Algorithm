#include<cstdio>
#include<algorithm>
using std::sort;


int binarySearch(int *arr,int begin,int end,int tar){
	if(begin >= end){
		return -1; 
	} 
	int mid = (begin + end) / 2;
	if(arr[mid] == tar){
		return mid;
	}else if(arr[mid] > tar){
		return binarySearch(arr,begin,mid,tar);
	}else{
		return binarySearch(arr,mid + 1,end,tar);
	}
}

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	int n;
	scanf("%d",&n);
	int arr[n + 5];
	for(int i = 0;i < n;i ++){
		scanf("%d",arr + i);
	}
	sort(arr,arr + n);
	int sum;
	scanf("%d",&sum);
	for(int i = 0;i < n;i ++){
		int first = arr[i];
		int second = sum - first;
		if(binarySearch(arr,0,n,second) != -1){
			printf("%d %d\n",first,second);
			return 0;
		}
	}
	printf("No\n");
} 
