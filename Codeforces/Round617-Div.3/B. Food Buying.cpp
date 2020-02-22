#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t,s;

int eval(int money){
    if(money < 10) return money;
    return eval(money / 10 + money % 10) + money - money % 10;
}

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&s);
        printf("%d\n",eval(s));
    }
}