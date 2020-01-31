#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T,N,E,F,W[505],P[505],dp[10005],total;

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        ms(dp,inf);
        scanf("%d%d",&E,&F),total = F - E;
        scanf("%d",&N);
        for(int i = 1;i <= N;i ++) scanf("%d%d",P + i,W + i);
        dp[0] = 0;
        for(int i = 1;i <= N;i ++){
            for(int j = W[i];j <= total;j ++){
                dp[j] = min(dp[j],dp[j - W[i]] + P[i]);
            }
        }
        if(dp[total] != inf) printf("The minimum amount of money in the piggy-bank is %d.\n",dp[total]);
        else printf("This is impossible.\n");
    }
}