#include <cstdio>
int n,k,m,dp[10005];

int main() {
    while(scanf("%d%d%d",&n,&k,&m) == 3 && n){
        dp[0] = 0;
        for(int i = 1;i < n;i ++) dp[i] = (dp[i - 1] + k) % (i + 1);
        printf("%d\n",((dp[n - 1] + m - k) % n + n) % n + 1);
    }
}