#include <cstdio>

int exgcd(int a,int b,int &s,int &t){
    if(b == 0){
        s = 1,t = 0;
        return a;
    }
    int d = exgcd(b,a % b,s,t);
    int temp = s;
    s = t;
    t = temp - a / b * t;
    return d;
}

int main(){
    int a = 1613,b = 3589,s,t;
    int d = exgcd(a,b,s,t);
    printf("%d %d %d",d,s,t);
}