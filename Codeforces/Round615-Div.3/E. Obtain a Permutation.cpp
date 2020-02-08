#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    int matrix[n + 1][m + 1],same[n + 1];
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i = 1;i <= m;i ++){
        ms(same,0);
        for(int j = 1;j <= n;j ++){
            int ele = matrix[j][i];
            if((ele - i) % m == 0 && ele <= n * m){
                int row = (ele - i) / m + 1;
                if(row <= j) same[j - row] ++;
                else same[n - (row - j)] ++;
            }
        }
        int tmp = inf;
        for(int i = 0;i < n;i ++) tmp = min(tmp,i + n - same[i]);
        ans += tmp;
    }
    printf("%d\n",ans);
}