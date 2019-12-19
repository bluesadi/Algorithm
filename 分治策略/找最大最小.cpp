#include <iostream>
#include <cmath>
using namespace std;

struct Pair{
	int max_;
	int min_;
};

Pair findMaxMin(int *arr,int n){
	if(n == 1){
		Pair pair = {arr[0],arr[0]};
		return pair;
	}
	int mid = n / 2;
	Pair left = findMaxMin(arr,mid);
	Pair right = findMaxMin(arr + mid,n - mid);
	int max_ = max(left.max_,right.max_);
	int min_ = min(left.min_,right.min_);
	Pair pair = {max_,min_};
	return pair;
}

int main(){
	int testArray[15] = {1,4,5,3,230,417,213,41,13,6,8,124,1241,-6,-54};
	Pair pair = findMaxMin(testArray,15);
	printf("max:%d\nmin:%d",pair.max_,pair.min_);
}
