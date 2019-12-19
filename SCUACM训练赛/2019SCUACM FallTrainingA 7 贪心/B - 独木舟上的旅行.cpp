#include<cstdio>
#include<algorithm>
#include <deque>

using namespace std;

int s,w,n;

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    scanf("%d",&s);
    while(s --){
        scanf("%d%d",&w,&n);
        deque<int> que;
        for(int i = 0;i < n;i ++){
            int a;
            scanf("%d",&a);
            que.push_back(a);
        }
        sort(que.begin(),que.end());
        int ans = 0;
        while(!que.empty()){
            if(que.size() == 1){
                ans ++;
                break;
            }
            int first = que.front();
            int back = que.back();
            if(first + back <= w){
                que.pop_front();
                que.pop_back();
                ans ++;
            }else{
                que.pop_back();
                ans ++;
            }
        } 
        printf("%d\n",ans);
    }
} 
