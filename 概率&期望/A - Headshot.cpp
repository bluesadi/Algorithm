#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

char rounds[150];
int n;

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    while(~scanf("%s",rounds)){
        n = strlen(rounds);
        double n01 = 0,n00 = 0,n0 = 0,n1 = 0;
        for(int i = 0;rounds[i];i ++){
            if(rounds[i] == '0'){
                n0++;
                if((rounds[i + 1] ? rounds[i + 1] : rounds[0]) == '0') n00++;
                else n01++;
            }else n1++;
        }
        double p1 = n01 / (n01 + n00),p2 = n1 / (n0 + n1);
        if(abs(p1 - p2) < 1e-6) printf("EQUAL\n");
        else if(p1 > p2) printf("ROTATE\n");
        else printf("SHOOT\n");
    }
}