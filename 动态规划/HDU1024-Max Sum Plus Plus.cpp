#define LOCAL
#define ms(x,v) memset(x,v,sizeof x)
#define inf 1 << 30
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,arr[(int)1e6 + 5],dp[(int)1e6 + 5],last_dp[(int)1e6 + 5];

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    while(scanf("%d%d",&m,&n) != EOF){
        ms(dp,0),ms(last_dp,0);
        for(int i = 1;i <= n;i ++) scanf("%d",arr + i);
        //dp[j] = max{dp[j - 1] + arr[j],last_dp[k] + arr[j]}(i - 1 <= k < j)
        int kmax,ans = -inf;
        for(int i = 1;i <= m;i ++){
            kmax = -inf;
            for(int j = i;j <= n;j ++){
                dp[j] = max(dp[j - 1] + arr[j],kmax + arr[j]);
                kmax = max(kmax,last_dp[j]);
                if(i == m) ans = max(ans,dp[j]);
            }
            for(int j = i;j <= n;j ++) last_dp[j] = dp[j];
        }
        //直观版
        /*
        int kmax;
        for(int i = 1;i <= m;i ++){
            kmax = -inf;
            for(int j = i;j <= n;j ++){
                dp[j] = max(dp[j - 1] + arr[j],last_dp[j - 1] + arr[j]);
                last_dp[j - 1] = kmax;
                kmax = max(kmax,dp[j]);
            }
        }
        */
        //简化版
        printf("%d\n",ans);
    }
}