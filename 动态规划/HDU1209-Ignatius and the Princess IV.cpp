#define LOCAL
#define ms(x,v) memset(x,v,sizeof x)
#define inf 1 << 30
#include <cstdio>
#include <cstring>
#include <algorithm>

int N,a[(int)5e6 + 5],ans;

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    while(scanf("%d",&N) != EOF){
        ms(a,0);
        for(int i = 0;i < N;i ++){
            int tmp;
            scanf("%d",&tmp);
            if(++a[tmp] >= (N + 1) / 2) ans = tmp;
        }
        printf("%d\n",ans);
    }
}