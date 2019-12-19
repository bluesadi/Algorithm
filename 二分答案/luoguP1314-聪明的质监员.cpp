#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define ll long long

int n,m,w[2000005],v[2000005],lc[2000005],rc[2000005],nSum[2000005];
ll s,ans = 1e12 + 5,vSum[2000005];

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);//printf("debug\n");
    scanf("%d%d%lld",&n,&m,&s);
    for(int i = 1;i <= n;i ++){
        scanf("%d%d",w + i,v + i);
    }
    for(int i = 0;i < m;i ++){
        scanf("%d%d",lc + i,rc + i);
    }
    ll l = 0,r = 1e12 + 5;
    while(l <= r){
        ll mid = (l + r) / 2;
        nSum[1] = w[1] >= mid;
        vSum[1] = w[1] >= mid ? v[1] : 0;
        for(int i = 2;i <= n;i ++){
            nSum[i] = nSum[i - 1] + (w[i] >= mid);
            vSum[i] = w[i] >= mid ? vSum[i - 1] + v[i] : vSum[i - 1];
        }
        ll ySum = 0;
        for(int i = 0;i < m;i ++){
            ySum += (nSum[rc[i]] - nSum[lc[i] - 1]) * (vSum[rc[i]] - vSum[lc[i] - 1]);
        }
        ans = std::min(ans,std::abs(ySum - s));
        if(ans == 0) break;
        if(ySum > s) l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld\n",ans);
} 
