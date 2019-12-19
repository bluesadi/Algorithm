#include <iostream>
#include <memory.h>

using namespace std; 

int main(){
	//freopen("D:/ACM/cppÔ´ÎÄ¼þ/test.in","r",stdin);
	int n,m;
	while(scanf("%d%d",&n,&m) == 2){
		int arr[2 * n + 1];
		int placed = 0;
		memset(arr,0,sizeof arr);
		int *ptr = arr;
		int i = 0;
		while(placed != n){
			i ++;
			do{
				ptr ++;
				if(ptr == arr + 2 * n + 1){
					ptr = arr + 1;
				}
			}while(*ptr == 1);
			if(i % m == 0){
				*ptr = 1;
				placed ++;
			}
		}
		for(int i = 1;i <= 2 * n;i ++){
			printf("%c",arr[i] == 0 ? 'G' : 'B');
			if(i % 50 == 0 && i != 2 * n){
				printf("\n");
			} 
		}
		printf("\n\n");
	}
}
