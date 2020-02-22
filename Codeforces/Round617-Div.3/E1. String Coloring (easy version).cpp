#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define inf 0x3f3f3f3f
#include <algorithm>
using namespace std;
#include <cstring>
#define ms(x,v) memset(x,v,sizeof x)
#include <cstdio>

int n;
char str[205],ans[205] = {0};

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%s",&n,str);
    char c1 = 'a',c2 = 'a';
    for(int i = 0;i < n;i ++){
        if(str[i] >= c1){
            c1 = str[i];
            ans[i] = '0';
        }else if(str[i] >= c2){
            c2 = str[i];
            ans[i] = '1';
        }else{
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n%s\n",ans);
}