#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long

LL n;
int d,ansk = 2,ansx = 0;

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%lld%d",&n,&d);
    for(int k = 2;k < 1e8;k ++){
        int cur = 0;
        LL copy = n;
        while(copy){
            if(copy % k == d) cur++;
            else break;
            copy /= k;
        }
        if(cur > ansx) ansx = cur,ansk = k;
    }
    printf("%d %d\n",ansk,ansx);
}