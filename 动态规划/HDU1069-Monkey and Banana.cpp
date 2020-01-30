#define LOCAL
#define ms(x,v) memset(x,v,sizeof x)
#define inf 1 << 30
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node{
    int l,w,h;

    bool operator < (Node& another) const{
        return l > another.l;
    }

}nodes[200];

int N,dp[200],cases;

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    while(scanf("%d",&N) != EOF){
        if(!N) break;
        ms(dp,0);
        for(int i = 0;i < N;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            nodes[6 * i] = {x,y,z},nodes[6 * i + 1] = {x,z,y};
            nodes[6 * i + 2] = {y,x,z},nodes[6 * i + 3] = {y,z,x};
            nodes[6 * i + 4] = {z,x,y},nodes[6 * i + 5] = {z,y,x};
        }
        sort(nodes,nodes + (N *= 6));
        int ans = -inf;
        //dp[i]以第i个方块结尾的最大高度
        dp[0] = nodes[0].h;
        for(int i = 1;i < N;i ++){
            for(int j = 0;j < i;j ++){
                dp[i] = max(dp[i],(nodes[j].l > nodes[i].l && nodes[j].w > nodes[i].w) ? dp[j] + nodes[i].h : nodes[i].h);
            }
            ans = max(dp[i],ans);
        }
        printf("Case %d: maximum height = %d\n",++cases,ans);
    }
}