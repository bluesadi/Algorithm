#define LOCAL
#define ms(x,v) memset(x,v,sizeof x)
#define debug(x) cout << "debug:" << x << endl
#define inf 0x3f3f3f3f
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node{
    char name[105];
    int deadline,cost;
}nodes[20];

int T,N,dp[(1 << 15) + 5],path[(1 << 15) + 5];

void printPath(int end){
    if(path[end] != -1){
        printPath(path[end]);
        int k = 0;
        for(int i = 0;i < N;i ++){
            if(((end & (1 << i)) > 0) && ((path[end] & (1 << i)) == 0)) k = i;
        }
        printf("%s\n",nodes[k].name);
    }
}

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        ms(dp,inf),ms(path,-1);
        scanf("%d",&N);
        for(int i = 0;i < N;i ++) scanf("%s%d%d",nodes[i].name,&nodes[i].deadline,&nodes[i].cost);
        int total = 1 << N;
        dp[0] = 0;
        for(int i = 0;i < total;i ++){
            for(int j = 0;j < N;j ++){
                if((i & (1 << j)) == 0){
                    int used_time = 0;
                    for(int k = 0;k < N;k ++){
                        if(i & (1 << k)) used_time += nodes[k].cost;
                    }
                    int cost = dp[i] + max(used_time + nodes[j].cost - nodes[j].deadline,0);
                    if(cost < dp[i | (1 << j)]){
                        dp[i | (1 << j)] = cost;
                        path[i | (1 << j)] = i;
                    }
                }
            }
        }
        printf("%d\n",dp[total - 1]);
        printPath(total - 1);
    }
}