#include <cstdio>

int gcd1(int a,int b){
    if(b > a){
        int t = a;
        a = b;
        b = t;
    }
    return b ? gcd1(b,a - b) : a;
}

int gcd2(int a,int b){
    return b ? gcd2(b,a % b) : a;
}

int main(){
    printf("%d",gcd1(26,13));
}