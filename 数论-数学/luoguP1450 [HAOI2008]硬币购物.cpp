#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long

int c[5],tot,d[5],s; 

int f(int i){
    return (d[i] + 1) * c[i];
}

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    scanf("%d%d%d%d%d",c + 1,c + 2,c + 3,c + 4,&tot);
    while(tot--){
        scanf("%d%d%d%d%d",d + 1,d + 2,d + 3,d + 4,&s);
        ll dp[100005];
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        for(int i = 1;i <= 4;i ++){
            for(int j = c[i];j <= s;j ++){
                dp[j] += dp[j - c[i]]; 
            }
        }
        //> _ <?
        if(s - f(1) >= 0) dp[s] -= dp[s - f(1)];
        if(s - f(2) >= 0) dp[s] -= dp[s - f(2)];
        if(s - f(3) >= 0) dp[s] -= dp[s - f(3)];
        if(s - f(4) >= 0) dp[s] -= dp[s - f(4)];
        if(s - f(1) - f(2) >=  0) dp[s] += dp[s - f(1) - f(2)];
        if(s - f(1) - f(3) >= 0) dp[s] += dp[s - f(1) - f(3)];
        if(s - f(1) - f(4) >= 0) dp[s] += dp[s - f(1) - f(4)];
        if(s - f(2) - f(3) >= 0) dp[s] += dp[s - f(2) - f(3)];
        if(s - f(2) - f(4) >= 0) dp[s] += dp[s - f(2) - f(4)];
        if(s - f(3) - f(4) >= 0) dp[s] += dp[s - f(3) - f(4)];
        if(s - f(1) - f(2) - f(3) >= 0) dp[s] -= dp[s - f(1) - f(2) - f(3)];
        if(s - f(1) - f(2) - f(4) >= 0) dp[s] -= dp[s - f(1) - f(2) - f(4)];
        if(s - f(1) - f(3) - f(4) >= 0) dp[s] -= dp[s - f(1) - f(3) - f(4)]; 
        if(s - f(2) - f(3) - f(4) >= 0) dp[s] -= dp[s - f(2) - f(3) - f(4)];
        if(s - f(1) - f(2) - f(3) - f(4) >= 0) dp[s] += dp[s - f(1) - f(2) - f(3) - f(4)];
        printf("%lld\n",dp[s]);
    }
}
