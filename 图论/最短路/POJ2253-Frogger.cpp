#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#define ms(x,v) memset(x,v,sizeof x)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int x[205],y[205],n,cnt = 1;
double ans[205][205];

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    while(scanf("%d",&n) != EOF && n){
        for(int i = 1;i <= n;i ++) scanf("%d%d",x + i,y + i);
        for(int s = 1;s <= n;s ++) 
            for(int e = s;e <= n;e ++) 
                ans[s][e] = ans[e][s] = sqrt(pow((x[s] - x[e]),2) + pow((y[s] - y[e]),2));
        for(int k = 1;k <= n;k ++)
            for(int i = 1;i <= n;i ++)
                for(int j = 1;j <= n;j ++)
                    ans[i][j] = min(ans[i][j],max(ans[i][k],ans[k][j]));
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",cnt++,ans[1][2]);
    }
}