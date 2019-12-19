#include<cstdio>
#include<algorithm>
#include <cstring>
#include<vector>
#define ll long long

using namespace std;

int n,k;
ll s;

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    scanf("%d%d%lld",&n,&k,&s);
    int cur = 1;
    vector<int> trace; 
    if(k > s){
        printf("NO\n");
        return 0;
    }
    while(k){
        if(s <= 0) break;
        k --;
        if(n - cur >= cur - 1){
            int step = s - (n - cur) >= k ? n - cur : s - k;
            cur += step;
            s -= step;
        }else{
            int step = s - (cur - 1) >= k ? cur - 1 : s - k;
            cur -= step;
            s -= step;
        }
        trace.push_back(cur);
    }   
    if(s == 0 && k == 0){
        printf("YES\n");
        for(int i = 0;i < trace.size();i ++){
            printf("%d",trace[i]);
            printf(i != trace.size() - 1 ? " " : "\n");
        }
    }else{
        printf("NO\n");
    }
}
