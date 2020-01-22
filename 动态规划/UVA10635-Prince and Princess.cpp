#include <cstdio>
#include <cstring>

int t,n,p,q,s1[250 * 250 + 5],s2[250 * 250 + 5],map[250 * 250 + 5],dp[250 * 250 + 5],cases = 0;

int main() {
    scanf("%d",&t);
    while(t--){
        memset(map,-1,sizeof map),memset(dp,0,sizeof dp);
        scanf("%d%d%d",&n,&p,&q),p++,q++;
        for(int i = 0;i < p;i ++) scanf("%d",s1 + i),map[s1[i]] = i;
        int cnt = 0;
        for(int i = 0;i < q;i ++){
            int tmp;
            scanf("%d",&tmp);
            if(map[tmp] != -1) s2[++cnt] = map[tmp];
        }
        dp[1] = s2[1];
        int len = 1;
        for(int i = 2;i <= cnt;i ++){
            int low = 1, high = len,mid;
            while (low <= high) {
                mid = (low + high) / 2;
                if (s2[i] > dp[mid]) low = mid + 1;
                else high = mid - 1;
            }
            if(low > len) len++;
            dp[low] = s2[i];
        }
        printf("Case %d: %d\n",++cases,len);
    }
}