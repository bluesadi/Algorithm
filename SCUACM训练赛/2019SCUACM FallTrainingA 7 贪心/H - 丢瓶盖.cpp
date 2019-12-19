#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;

int A,B;
int p[(int)1e5 + 5];

bool judge(int ans){
    int last = 0,total = 1;
    for(int i = 1;i < A;i ++){
        if(p[i] - p[last] >= ans){
            total ++;
            last = i;
        }
    }
    return total >= B;
}

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    scanf("%d%d",&A,&B);
    for(int i = 0;i < A;i ++){
        scanf("%d",p + i);
    }
    sort(p,p+A);
    int l = 0,r = INF;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(judge(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    printf("%d\n",l);
}
