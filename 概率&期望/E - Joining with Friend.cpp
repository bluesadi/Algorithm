#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;

int T,t1,t2,s1,s2,w,cnt = 1;

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&t1,&t2,&s1,&s2,&w);
        double ans;
        int y1 = t1 - w,y2 = t1 + w,y3 = t2 - w,y4 = t2 + w;
        if(y1 >= s2 || y4 <= s1) ans = 0;
        else{
            double S = (t2 - t1) * (s2 - s1),S1,S2;
            S1 = (max(s2 - y4,0) + max(s2 - y2,0)) * (t2 - t1 - max(y4 - s2,0)) * 0.5 - 0.5 * max(s1 - y2,0) * (s1 - y2);
            S2 = (max(y1 - s1,0) + max(y3 - s1,0)) * (t2 - t1 - max(s1 - y1,0)) * 0.5 - 0.5 * max(y3 - s2,0) * (y3 - s2);
            ans = (S - S1 - S2) / S;
        }
        printf("Case #%d: %.8lf\n",cnt++,ans);
    }
}