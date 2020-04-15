#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long

LL X,Y;

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%lld%lld",&X,&Y);
    LL cur,ans = 0;
    for(int N = 1;N <= 63;N ++){
        LL tmp = 0;
        for(int t = 0;t < N;t ++) tmp |= (1LL << t);
        if(tmp <= Y && tmp >= X) ans++;
        for(int M = 1;M <= 63;M ++){
            cur = 0;
            for(int t = 0;t < N;t ++) cur |= (1LL << t);
            int offset = N;
            for(int k = 0;cur <= Y;k ++){
                if(k % 2){
                    if((offset += N) > 63) break;
                    cur <<= N;
                    for(int t = 0;t < N;t ++) cur |= (1LL << t);
                }else{
                    if((offset += M) > 63) break;
                    cur <<= M;
                }
                if(cur <= Y && cur >= X) ans++;
                if(cur >= Y) break;
            }
        }
    }
    printf("%lld\n",ans);
}