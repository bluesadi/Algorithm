#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long

int T,cnt = 1;
LL A,B;

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&A,&B);
        LL a1 = A,a2 = B,ans = 1;
        if(A == 0 && B == 0) ans = 1;
        else if(A == 0 || B == 0) ans = 2;
        else{
            while(a2){
                LL t = a2;
                ans += a1 / a2;
                a2 = a1 % a2;
                a1 = t;
            }
        }
        printf("Case #%d: %lld\n",cnt++,ans);
    }
}