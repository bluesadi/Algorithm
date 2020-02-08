#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int abc[3],n,t;

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",abc,abc+1,abc+2,&n);
        sort(abc,abc + 3);
        if((abc[0] + abc[1] + abc[2] + n) % 3 == 0 && 2 * abc[2] - abc[1] - abc[0] <= n) printf("YES\n");
        else printf("NO\n");
    }
}