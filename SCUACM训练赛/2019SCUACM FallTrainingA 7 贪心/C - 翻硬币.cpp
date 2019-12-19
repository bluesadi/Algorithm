#include<cstdio>
#include<algorithm>
#include <cstring>

using namespace std;

char str1[1005],str2[1005];

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    scanf("%s%s",str1,str2);
    int len = strlen(str1),ans = 0;
    for(int i = 0;i < len - 1;i ++){
        if(str1[i] != str2[i]){
            str1[i] = str1[i] == 'o' ? '*' : 'o';
            str1[i + 1] = str1[i + 1] == 'o' ? '*' : 'o';
            ans ++;
        }
    }
    if(!strcmp(str1,str2)){
        printf("%d\n",ans);
    }else{
        printf("No Answer.");
    } 
} 
