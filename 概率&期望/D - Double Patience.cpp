#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
using namespace std;

char piles[10][5],tmp[5][100];
int power[10] = {1,5,25,125,625,3125,15625,78125,390625};
double dp[2000000];

int bit(int k,int v){
    return (v / power[k]) % 5;
}

double dfs(int stat){
    if(!stat) return 1;
    double curp = dp[stat];
    if(curp != -1) return curp;
    else curp = 0;
    int total = 0;
    for(int i = 0;i < 9;i ++){
        for(int j = i + 1;j  < 9;j ++){
            if(bit(i,stat) * bit(j,stat) != 0 && piles[i][bit(i,stat)] == piles[j][bit(j,stat)]){
                total ++;
                curp += dfs(stat - power[i] - power[j]);
            }
        }
    }
    return dp[stat] = total ? curp / total : 0;
}

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    while(~scanf("%s%s%s%s",tmp,tmp + 1,tmp + 2,tmp + 3)){
        fill_n(dp,2000000,-1);
        for(int i = 1;i <= 4;i ++) piles[0][i] = tmp[i - 1][0];
        for(int i = 1;i < 9;i ++){
            scanf("%s%s%s%s",tmp,tmp + 1,tmp + 2,tmp + 3);
            for(int j = 1;j <= 4;j ++) piles[i][j] = tmp[j - 1][0];
        }
        printf("%.6lf\n",dfs(1953124));
    }
}