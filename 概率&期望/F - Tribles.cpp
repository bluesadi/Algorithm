#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int T,n,k,m,cnt = 1;
double p[1050],f[1050];

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&m);
        for(int i = 0;i < n;i ++) scanf("%lf",p + i);
        fill_n(f,1050,0);
        f[1] = p[0];
        for(int i = 2;i <= m;i ++){
            for(int j = n - 1;j >= 0;j --) f[i] = f[i] * f[i - 1] + p[j];
        }
        printf("Case #%d: %.7lf\n",cnt++,pow(f[m],k));
    }
}