#include <cstdio>

int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}

int main(){
    int a = 282,b = 202;
    printf("%d",gcd(a,b));
}