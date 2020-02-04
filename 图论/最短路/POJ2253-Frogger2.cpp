#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,x[205],y[205],visit[205],cnt = 1;
double w[205][205],d[205];

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    while(scanf("%d",&n) != EOF && n){
        ms(visit,0);
        for(int i = 1;i <= n;i ++) d[i] = 1e6;
        for(int i = 1;i <= n;i ++) scanf("%d%d",x + i,y + i);
        for(int s = 1;s <= n;s ++) 
            for(int e = s;e <= n;e ++) 
                w[s][e] = w[e][s] = sqrt(pow((x[s] - x[e]),2) + pow((y[s] - y[e]),2));
        d[1] = 0;
        for(int i = 1;i <= n;i ++){
            double min_w = 1e6;int k;
            for(int j = 1;j <= n;j ++) if(!visit[j] && d[j] < min_w) min_w = d[k = j]; 
            visit[k] = 1;
            for(int j = 1;j <= n;j ++) d[j] = min(d[j],max(d[k],w[j][k]));
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",cnt++,d[2]);
    }
}