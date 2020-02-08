#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t,n;

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bool found = false;
        for(int a = 2;a * (a + 1) * (a + 2) <= n;a++){
            for(int b = a + 1;a * b * (b + 1) <= n;b++){
                if(n % (a * b) == 0){
                    int c = n / (a * b);
                    printf("YES\n%d %d %d\n",a,b,c);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(!found) printf("NO\n");
    }
}