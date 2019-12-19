#include <iostream>
#include <cstring>

void prints(int *arr,int n,char s){
	for(int i = 0;i < n;i ++){
		printf("%d",arr[i]);
		printf("%c",i == n - 1 ? '\n' : ',');
	}
}

void mergeSort(int *arr,int n){
	if(n <= 1){
		return;
	}
	int mid = n / 2;
	mergeSort(arr,mid);
	mergeSort(arr + mid,n - mid);
	int ptr1 = 0,ptr2 = mid,index = 0;
	int copy[n];
	memcpy(copy,arr,sizeof(int) * n);
	while(ptr1 < mid && ptr2 < n){
		if(copy[ptr1] > copy[ptr2]){
			arr[index] = copy[ptr2];
			ptr2 ++;
			if(ptr2 >= n){
				while(ptr1 < mid){
					index ++;
					arr[index] = copy[ptr1];
					ptr1 ++;
				}
			}
		}else{
			arr[index] = copy[ptr1];
			ptr1 ++;
			if(ptr1 >= mid){
				while(ptr2 < mid){
					index ++;
					arr[index] = copy[ptr2];
					ptr2 ++;
				}
			}
		}
		index++;
	}
} 

int main(){
	int testArray[15] = {1,4,5,3,230,417,213,41,13,6,8,124,1241,-6,-54};
	mergeSort(testArray,15);
	prints(testArray,15,',');
} 

