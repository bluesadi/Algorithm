#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    int n;
    scanf("%d",&n);
    deque<int> horse1,horse2;
    for(int i = 0;i < n;i ++){
        int a;
        scanf("%d",&a);
        horse1.push_back(a);
    }    
    for(int i = 0;i < n;i ++){
        int a;
        scanf("%d",&a);
        horse2.push_back(a);
    }    
    sort(horse1.begin(),horse1.end());
    sort(horse2.begin(),horse2.end());
    int ans = 0;
    while(!horse1.empty()){
        int h1 = horse1.front();
        int h2 = horse2.front();
        if(h1 > h2){
            ans ++;
            horse1.pop_front();
            horse2.pop_front();
        }else{
            horse1.pop_front();
        }
    }
    printf("%d\n",ans);
}
