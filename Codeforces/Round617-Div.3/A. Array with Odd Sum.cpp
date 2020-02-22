#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define inf 0x3f3f3f3f
#include <algorithm>
using namespace std;
#include <cstring>
#define ms(x,v) memset(x,v,sizeof x)
#include <cstdio>

int t,n;

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bool odd = 0,even = 0;
        for(int i = 0;i < n;i++){
            int tmp;
            scanf("%d",&tmp);
            if(tmp % 2) odd = 1;
            else even = 1;
        }
        if(n % 2) printf(odd ? "YES\n" : "NO\n");
        else printf(odd && even ? "YES\n" : "NO\n");
    }
}