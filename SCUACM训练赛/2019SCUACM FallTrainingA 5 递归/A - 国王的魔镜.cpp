#include <cstdio>
#include <algorithm>
#include <cstring>

int judge(char *str){
	int len = strlen(str);
	if((len & 1) == 0){
		for(int i = 0;i < len / 2;i ++){
			if(str[i] != str[len - i - 1]){
				return len;
			}
		}
		return judge(str + len / 2);
	}
	return len;
}

int main(){
	char str[100000 + 5];
	scanf("%s",str);
	printf("%d\n",judge(str));
}
