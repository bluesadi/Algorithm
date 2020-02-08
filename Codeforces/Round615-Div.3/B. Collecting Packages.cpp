#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point{
    int x,y;

    bool operator < (const Point& point){
        if(x == point.x) return y < point.y;
        return x < point.x;
    }
};

int t,n;
Point points[1005];

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;i ++) scanf("%d%d",&points[i].x,&points[i].y);
        sort(points,points + n);
        bool impossible = false;
        char path[2005] = {0};
        int ptr = 0;
        Point last = {0,0};
        for(int i = 0;i < n;i++){
            Point cur = points[i];
            if(last.y > cur.y){
                impossible = true;
                break;
            }
            for(int j = 0;j < cur.x - last.x;j ++) path[ptr++] = 'R';
            for(int j = 0;j < cur.y - last.y;j ++) path[ptr++] = 'U';
            last = cur;
        }
        printf("%s\n",impossible ? "NO" : "YES");
        if(!impossible) printf("%s\n",path);
    }
}