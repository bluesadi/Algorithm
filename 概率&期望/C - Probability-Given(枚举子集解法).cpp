#include <cstdio>
#include <algorithm>
using namespace std;

int N,r,cnt = 1;
double p[25],ans[25],pr = 0;

int main(){
    while(~scanf("%d%d",&N,&r)){
        if(!N) break;
        pr = 0;
        fill_n(ans,N,0);
        for(int i = 0;i < N;i ++) scanf("%lf",p + i);
        for(int s = 0;s < (1 << N);s ++){
            int k = 0,sc = s;
            while(sc){
                k++;
                sc = sc & (sc - 1);
            }
            if(k != r) continue;
            double p1 = 1;
            for(int i = 0;i < N;i ++) p1 *= (s & (1 << i)) ? p[i] : (1 - p[i]);
            pr += p1;
            for(int i = 0;i < N;i ++) if(s & (1 << i)) ans[i] += p1;
        }
        printf("Case %d:\n",cnt++);
        for(int i = 0;i < N;i ++) printf("%.6lf\n",ans[i] / pr);
    }
}