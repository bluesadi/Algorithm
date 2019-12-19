#include<cstdio>
#include<algorithm>
#include <functional>

using namespace std;

int N,B; 
int h[20005];

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    scanf("%d%d",&N,&B);
    for(int i = 0;i < N;i ++){
        scanf("%d",h + i);
    }
    sort(h,h + N,greater<int>());
    int ans = 0,total = 0;
    for(int i = 0;i < N && total < B;i ++){
        total += h[i];
        ans ++;
    }
    printf("%d\n",ans);
} 
