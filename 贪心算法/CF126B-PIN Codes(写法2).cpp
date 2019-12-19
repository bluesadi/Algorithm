#include<iostream>
#include<algorithm>
#include <cstring>
 
using namespace std;
 
int n,t;
char codes[15][5];
 
int exists(int j){
	char *code = codes[j];
	for(int i = 0;i < n;i ++){
		if(!strcmp(code,codes[i]) && i != j) return true;
	}
	return false;
}
 
int main(){
	//freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	scanf("%d",&t);
	while(t --){
		int ans = 0;
		scanf("%d",&n);
		for(int i = 0;i < n;i ++){
			scanf("%s",codes + i);
		}
		for(int i = 0;i < n;i ++){
			if(exists(i)){
				ans ++;
				for(int j = '0';j <= '9' && exists(i);j ++){
					codes[i][0] = j;
				}
			}
		}
		printf("%d\n",ans);
		for(int i = 0;i < n;i ++){
			printf("%s\n",codes[i]);
		}
	} 
} 
