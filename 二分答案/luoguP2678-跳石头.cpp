#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f3f

int L,N,M,ans = INF; 
int stones[50005] = {0};

bool judge(int ans){
    int remove = 0,last = 0;
    for(int i = 1;i <= N;i ++){
        if(stones[i] - stones[last] < ans){
            remove ++;
        }else{
            last = i;
        }
    }
    if(L - stones[last] < ans) remove ++;
    return remove <= M;
}

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    scanf("%d%d%d",&L,&N,&M);
    for(int i = 1;i <= N;i ++){
        scanf("%d",stones + i); 
    }
    int l = 0,r = INF;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(judge(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    printf("%d\n",ans);
} 
