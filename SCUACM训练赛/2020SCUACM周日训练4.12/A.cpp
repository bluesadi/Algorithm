#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;

int T,cnt = 1;
double cx,cy,r,ax,ay,vx,vy,bx,by,dx,dy;

bool judge(){
    double d = abs(vy * cx - vx * cy + vx * ay - vy * ax) * 1.0 / sqrt(vy * vy + vx * vx);
    if(d < r){
        return vx * (cx - ax) + vy * (cy - ay) > 0;
    }
    return false;
}

void evalxy(){
    if(vx){
        double A = 1 + vy * vy / (vx * vx),B = 2 * (ay - vy * ax / vx - cy - cx),C = cx * cx + pow(ay - vy * ax / vx - cy,2) - r * r;
        double delta = sqrt(B * B - 4 * A * C);
        double x1 = (-B + delta) / (2 * A),x2 = (-B - delta) / (2 * A);
        double y1 = vy * x1 / vx + ay - vy * ax / vx,y2 = vy * x2 / vx + ay - vy * ax / vx;
        if((x1 - ax) * (x1 - ax) + (y1 - ay) * (y1 - ay) < (x2 - ax) * (x2 - ax) + (y2 - ay) * (y2 - ay)) dx = x1,dy = y1;
        else dx = x2,dy = y2;
    }else{
        dx = ax;
        double y1 = cy + sqrt(r * r - (ax - cx) * (ax - cx)),y2 = cy - sqrt(r * r - (ax - cx) * (ax - cx));
        if(abs(y1 - ay) < abs(y2 - ay)) dy = y1;
        else dy = y2;
    }
    
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&cx,&cy,&r,&ax,&ay,&vx,&vy,&bx,&by);
        bool ans;
        if(judge()){
            evalxy();
            double l1 = sqrt((ax - dx) * (ax - dx) + (ay - dy) * (ay - dy)),l2 = sqrt((bx - dx) * (bx - dx) + (by - dy) * (by - dy));
            ans = abs(((dx - cx) * (ax - dx) + (dy - cy) * (ay - dy)) / l1 - ((dx - cx) * (bx - dx) + (dy - cy) * (by - dy)) / l2) < 1e-3;
        }else{
            ans = (vy * (bx - ax) == vx * (by - ay)) && ((bx - ax) * vx + (by - ay) * vy > 0);
        }
        printf("Case #%d: %s\n",cnt++,ans ? "Yes" : "No");
    }
}