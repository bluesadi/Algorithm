#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long

ll ans[25] = {0};

ll A(int n,int m){
    ll f = 1;
    for(int i = m - n + 1;i <= m;i ++){
        f *= i;
    }
    return f;
}

ll C(int n,int m){
    return A(n,m) / A(n,n);
}
    
int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    int n;
    while(scanf("%d",&n) != EOF){
        for(int i = 2;i <= n;i ++){
            ans[i] = A(i,i) - 1;
            for(int j = 1;j < i;j ++){
                ans[i] -= C(j,i) * ans[j];
            } 
        }
        printf("%lld\n",ans[n]);
    }
}
