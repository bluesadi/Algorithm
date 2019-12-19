#include<cstdio>
#include<algorithm>

int main(){
    //freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t --){
        int n,x,a,b;
        scanf("%d%d%d%d",&n,&x,&a,&b);
        if(a > b){
            int t = b;
            b = a;
            a = t;		
        }
        int max_move = a - 1 + n - b;
        printf("%d\n",b - a + std::min(max_move,x)); 
    } 
} 
