#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long

int T,ex,ey,cnt = 1;

LL gcd(LL a,LL b){
    return b ? gcd(b,a % b) : a;
}

LL lcm(LL a,LL b){
    return a * b / gcd(a,b);
}

int dfs(int ex,int ey){
    int rtn = 1;
    if(ey > ex){
        int x = ex,y,z;
        for(int z = x;(y = ey - z) > 0;z += x){
            if(z == lcm(x,y)) rtn += dfs(x,y);
        }
    }else if(ey < ex){
        int x,y = ey,z;
        for(int z = y;(x = ex - z) > 0;z += y){
            if(z == lcm(x,y)) rtn += dfs(x,y);
        }
    }
    return rtn;
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&ex,&ey);
        printf("Case #%d: %d\n",cnt++,dfs(ex,ey));
    }
}