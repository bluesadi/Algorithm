#include <cstdio>
#include <algorithm>
#include <cstring>

int visit[10] = {0};
char ans[10];

void dfs(char *str,int k){
	int len = strlen(str);
	if(len == k){
		printf("%s\n",ans);
		return;
	}
	for(int i = 0;i < len;i ++){
		if(!visit[i]){
			ans[k] = str[i];
			visit[i] = 1;
			dfs(str,k + 1);
			visit[i] = 0;
		}
	}
}

int main(){
	char str[10];
	scanf("%s",str);
	dfs(str,0);
}

