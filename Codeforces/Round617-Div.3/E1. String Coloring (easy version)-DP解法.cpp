#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define inf 0x3f3f3f3f
#include <algorithm>
using namespace std;
#include <cstring>
#define ms(x,v) memset(x,v,sizeof x)
#include <cstdio>

int n,dp[205]['z' + 5]['z' + 5];
char str[205],ans[205] = {0};
pair<pair<int,int>,int> p[205]['z' + 5]['z' + 5];

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%s",&n,str + 1);
    dp[0]['a']['a'] = 1;
    for(int len = 1;len <= n;len ++){
        char c = str[len];
        for(int c1 = 'a';c1 <= 'z';c1 ++){
            for(int c2 = 'a';c2 <= 'z';c2 ++){
                if(!dp[len - 1][c1][c2]) continue;
                if(c >= c1){
                    dp[len][c][c2] = 1;
                    p[len][c][c2] = make_pair(make_pair(c1,c2),'0');
                }
                if(c >= c2){
                    dp[len][c1][c] = 1;
                    p[len][c1][c] = make_pair(make_pair(c1,c2),'1');
                }
            }
        }
    }
    char c1 = 0,c2 = 0;
    for(int i = 'a';i <= 'z';i ++){
        for(int j = 'a';j <= 'z';j ++){
            if(dp[n][i][j]) c1 = i,c2 = j;
        }
    }
    if(c1){
        int ptr = n - 1;
        for(int i = n;i > 0;i --){
            int prevc1 = p[i][c1][c2].first.first,prevc2 = p[i][c1][c2].first.second;
            char s = p[i][c1][c2].second;
            ans[ptr--] = s;
            c1 = prevc1,c2 = prevc2;
        }
        printf("YES\n%s",ans);
    }else printf("NO\n");
}