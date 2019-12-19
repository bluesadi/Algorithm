#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f3f
#define MAX_N (int)1e6 + 5

inline int read(){
    int x=0,f=1;
    char ch;
    while(ch<'0'||ch>'9')  {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

int n,m,room[MAX_N],sum[MAX_N] = {0},a[MAX_N],num[MAX_N],start[MAX_N],end[MAX_N];

bool judge(int ans){
    memset(a,0,sizeof a);
    for(int i = 1;i <= ans;i ++){
        a[start[i]] += num[i];
        a[end[i] + 1] -= num[i];
    }
    for(int i = 1;i <= n;i ++){
        sum[i] = sum[i - 1] + a[i];
        if(sum[i] > room[i]) return false;
    }
    return true;
} 

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);//printf("debug\n");
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++) room[i] = read();    //不快读也能过
    for(int i = 1;i <= m;i ++){
        num[i] = read();start[i] = read();end[i] = read();
    }
    int l = 1,r = m + 5,ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(judge(mid)){
            l = mid + 1; 
        }else{
            ans = mid;
            r = mid - 1;            
        }
    }
    if(ans == -1){
        printf("0\n");
    }else{
        printf("-1\n");
        printf("%d\n",ans);
    }
} 
