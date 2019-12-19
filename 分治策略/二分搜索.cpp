#include <iostream>

int binarySearch(int *arr,int begin,int end,int target){
	int mid = (begin + end) / 2;
	if(arr[mid] == target){
		return mid;
	}else{
		if(end - begin == 1){
			return -1;
		}
	}
	if(arr[mid] > target){
		return binarySearch(arr,0,mid,target);
	}else {
		return binarySearch(arr,mid,end,target); 
	}
}

int main(){
	int test[13] = {1,3,5,6,9,21,213,1314,3133,4444,31133,414114,131313};
	printf("find1:%d\n",binarySearch(test,0,13,1314));
	printf("find2:%d\n",binarySearch(test,0,13,1313));
} 
