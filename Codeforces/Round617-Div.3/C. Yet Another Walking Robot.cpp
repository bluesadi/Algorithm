#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define inf 0x3f3f3f3f
#include <algorithm>
using namespace std;
#include <cstring>
#define ms(x,v) memset(x,v,sizeof x)
#include <cstdio>

struct Point{
    int x,y,step;

    bool operator < (const Point& point){
        if(x == point.x){
            if(y == point.y) return step < point.step;
            return y <= point.y;
        }
        return x < point.x;
    }
}points[200050];

int t,n;

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        int x = 0,y = 0;
        scanf("%d",&n);
        points[0] = {0,0,0};
        getchar();
        for(int i = 1;i <= n;i ++){
            char c = getchar();
            if(c == 'L') x--;
            else if(c == 'R') x++;
            else if(c == 'U') y++;
            else y--;
            points[i] = {x,y,i};
        }
        sort(points,points + n + 1);
        int len = inf,l = -1,r = -1;
        for(int i = 1;i <= n;i ++){
            Point prev = points[i - 1],next = points[i];
            if(prev.x == next.x && prev.y == next.y && abs(next.step - prev.step) < len)
                l = min(prev.step,next.step) + 1,r = max(prev.step,next.step),len = abs(next.step - prev.step);
        }
        if(len == inf) printf("-1\n");
        else printf("%d %d\n",l,r);
    }
}