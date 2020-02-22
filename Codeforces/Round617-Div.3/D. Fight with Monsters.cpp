#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define inf 0x3f3f3f3f
#include <algorithm>
using namespace std;
#include <cstring>
#define ms(x,v) memset(x,v,sizeof x)
#include <cstdio>

int n,a,b,k,points = 0,use[200050] = {0};

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%d%d%d",&n,&a,&b,&k);
    for(int i = 0;i < n;i ++){
        int h;
        scanf("%d",&h);
        if(h % (a + b) <= a && h % (a + b)!= 0) points++;
        else{
            int tmp = h % (a + b);
            use[0]++;
            if(tmp == 0) tmp = a + b;
            use[use[0]] = (tmp - 1) / a;
        }
    }
    sort(use + 1,use + use[0] + 1); 
    for(int i = 1;i <= use[0];i ++){
        if((k -= use[i]) >= 0) points++;
        else break;
    }
    printf("%d\n",points);
}