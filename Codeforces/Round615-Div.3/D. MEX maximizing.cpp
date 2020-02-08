#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int q,x,visit[400050],mini[400050];

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%d",&q,&x);
    ms(visit,0);
    for(int i = 0;i < q;i ++) mini[i] = i;
    int ans = 0;
    for(int i = 0;i < q;i ++){
        int a;
        scanf("%d",&a);
        a %= x;
        if(a < q && mini[a] < q){
            visit[mini[a]] = 1;
            while(visit[ans]) ans++;
            mini[a] += x;
        }
        printf("%d\n",ans);
    }
}