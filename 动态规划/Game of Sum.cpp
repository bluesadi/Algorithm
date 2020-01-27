#define LOCAL
#include <cstdio>
#include <cstring>
#include <algorithm>

int n,arr[105],dp[105][105],sum[105][105];

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    while(scanf("%d",&n) != 0){
        memset(dp,0,sizeof dp);
        if(!n) break;
        for(int i = 1;i <= n;i ++) scanf("%d",arr + i),sum[i][i] = arr[i];
        for(int i = 1;i <= n;i ++) for(int j = i + 1;j <= n;j ++) sum[i][j] = sum[i][j - 1] + arr[j];
        for(int j = 1;j <= n;j ++){
            for(int i = j;i >= 1;i --){
                int sub = 0;
                for(int k = i;k <= j;k ++){
                    sub = std::min(sub,dp[i][k]);
                }
                for(int k = j;k >= i;k --){
                    sub = std::min(sub,dp[k][j]);
                }
                dp[i][j] = sum[i][j] - sub;
            }
        }
        printf("%d\n",2 * dp[1][n] - sum[1][n]);
    }
}
