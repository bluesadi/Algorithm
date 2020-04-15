#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int T,pos[200],ans,cnt = 1;
char str[1050];

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        fill_n(pos,200,-1);
        ans = 2000;
        for(int i = 0;str[i];i++){
            if(pos[str[i]] == -1) pos[str[i]] = i;
            else ans = min(ans,i - pos[str[i]]),pos[str[i]] = i;
        }
        printf("Case #%d: %d\n",cnt++,ans == 2000 ? -1 : ans);
    }
}