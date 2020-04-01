#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;

double a,b,c;

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    while(~scanf("%lf%lf%lf",&a,&b,&c)){
        printf("%.5lf\n",(a * b + b * (b - 1)) / ((a + b) * (a + b - c - 1)));
    }
}