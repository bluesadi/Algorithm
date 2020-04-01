#include <cstdio>
#include <algorithm>
using namespace std;

int N,r,sel[25],cnt = 1;
double p[25],ans[25],pr;

void dfs(int i,int choose,double curp){
    if(i == N){
        if(choose == r){
            for(int i = 0;i < N;i ++) if(sel[i]) ans[i] += curp;
            pr += curp;
        }
        return;
    }
    sel[i] = 1;
    dfs(i + 1,choose + 1,curp * p[i]);
    sel[i] = 0;
    dfs(i + 1,choose,curp * (1 - p[i]));
}

int main(){
    while(~scanf("%d%d",&N,&r)){
        if(!N) break;
        pr = 0;
        fill_n(ans,N,0);
        for(int i = 0;i < N;i ++) scanf("%lf",p + i);
        dfs(0,0,1);
        printf("Case %d:\n",cnt++);
        for(int i = 0;i < N;i ++)printf("%.6lf\n",ans[i] / pr);
    }
}