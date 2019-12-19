#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long

ll a,b,c,d;

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d) != EOF){
    	ll x[4],y[4];
    	x[0] = b - a + 1;
        x[1] = b / 2 - (a - 1) / 2;
        x[2] = b / 1009-(a-1) / 1009;
        x[3] = b / 2018 - (a - 1) / 2018;
        x[2] -= x[3];
        x[1] -= x[3];
        x[0] -= x[3] + x[2] + x[1];
        y[0] = d - c + 1;
        y[1] = d / 2 - (c - 1) / 2;
        y[2] = d / 1009-(c-1) / 1009;
        y[3] = d / 2018 - (c - 1) / 2018;
        y[2] -= y[3];
        y[1] -= y[3];
        y[0] -= y[3] + y[2] + y[1];
		ll ans=0;
		ans = x[0] * y[3] + x[1] * y[2] + x[1] * y[3] + x[2] * y[1] + x[2] * y[2] + x[2] * y[3] + x[3] * y[0] + x[3] * y[1] + x[3] * y[2] + x[3] * y[3];
        printf("%lld\n",ans); 
	}
}
