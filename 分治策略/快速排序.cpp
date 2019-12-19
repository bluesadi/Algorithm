#include <iostream>
#include <cstring>

void prints(int *arr,int n,char s){
	for(int i = 0;i < n;i ++){
		printf("%d",arr[i]);
		printf("%c",i == n - 1 ? '\n' : ',');
	}
}

void quickSort(int *arr,int n){
	if(n <= 1){
		return;
	}
	int first = arr[0];
	int ptr1 = 1,ptr2 = n - 1;
	while(true){
		while(ptr2 != ptr1 && arr[ptr2] > first){
			ptr2 --;
		}
		while(ptr1 != ptr2 && arr[ptr1] < first){
			ptr1 ++;
		}
		if(ptr1 != ptr2){
			int t = arr[ptr1];
			arr[ptr1] = arr[ptr2];
			arr[ptr2] = t;
		}else{
			arr[0] = arr[ptr1];
			arr[ptr1] = first;
			quickSort(arr,ptr1);
			quickSort(arr + ptr1 + 1,n - ptr1 - 1); 
			return;
		}
	}
} 

int main(){
	int testArray[15] = {1,4,5,3,230,417,213,41,13,6,8,124,1241,-6,-54};
	quickSort(testArray,15);
	prints(testArray,15,',');
} 

