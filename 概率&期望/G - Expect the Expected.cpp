#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;

int T,n,cnt = 1;
double p,failp;

void dfs(int k,int win,double curp){
    if(k > n){
        failp += curp;
        return;
    }
    if(k && (1.0 * win / k > p || abs(1.0 * win / k - p) < 1e-6)) return;
    dfs(k + 1,win + 1,curp * p);
    dfs(k + 1,win,curp * (1 - p));
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        failp = 0;
        double a,b;
        scanf("%lf/%lf %d",&a,&b,&n);
        p = a / b;
        dfs(0,0,1);
        int E = 1.0 / failp;
        printf("Case #%d: %d\n",cnt++,E);
    }
}