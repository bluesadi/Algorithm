#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f

int t,k,s;
char line[15];

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    scanf("%d",&t);
    while(t --){
        scanf("%s%d",line,&k);
        s = strlen(line) - k;
        int pos = 0,ans = 0;
        while(s > 0){
            int min = line[pos],min_pos = pos;
            for(int i = pos;line[i] != '\0' && i - pos <= k;i ++){
                if(line[i] < min){
                    min = line[i];
                    min_pos = i;
                } 
            }
            ans += (min - '0') * std::pow(10,s - 1);
            k -= min_pos - pos;
            pos = min_pos + 1; 
            s--;
        }
        printf("%d\n",ans);
    }
}
