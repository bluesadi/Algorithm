#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;

int T,n,cnt = 1;

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        bool success = true;
        for(int i = 0;i < n;i ++){
            int tmp;
            scanf("%d",&tmp);
            if(tmp % 3) success = false;
        }
        printf("Case #%d: %s\n",cnt++,success ? "Yes" : "No");
    }
}