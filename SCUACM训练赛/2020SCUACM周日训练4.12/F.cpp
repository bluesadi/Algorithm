#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define LL long long

int T,cnt = 1;
char str[100050];
LL point,ans;

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        vector<LL> vec;
        point = ans = 0;
        LL curn = 1;
        char curc = str[0];
        for(int i = 1;str[i];i++){
            if(str[i] == curc) curn ++;
            else curc = str[i],vec.push_back(curn),point += curn * curn,curn = 1;
        }
        vec.push_back(curn);
        point += curn * curn;
        ans = point;
        int size = vec.size();
        for(int i = 0;i < size - 1;i++){
            LL l1 = vec[i],l2 = vec[i + 1];
            if(l2 > 1 || i + 2 >= size) ans = max(ans,point - l1 * l1 - l2 * l2 + (l1 + 1) * (l1 + 1) + (l2 - 1) * (l2 - 1));
            else{
                LL l3 = vec[i + 2];
                ans = max(ans,point - l1 * l1 - l2 * l2 - l3 * l3 + (l1 + l2 + l3) * (l1 + l2 + l3));
            }
            if(l1 > 1 || i == 0) ans = max(ans,point - l1 * l1 - l2 * l2 + (l1 - 1) * (l1 - 1) + (l2 + 1) * (l2 + 1));
            else{
                LL l3 = vec[i - 1];
                ans = max(ans,point - l1 * l1 - l2 * l2 - l3 * l3 + (l1 + l2 + l3) * (l1 + l2 + l3));
            }
        }
        printf("Case #%d: %lld\n",cnt++,ans);
    }
}