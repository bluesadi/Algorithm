/*
Luogu P1020 导弹拦截
Solution 3 2020/9/12 by bluesadi
时间复杂度为O(nlogn)？，提交能拿到满分
Tags:　动态规划，贪心，二分查找
*/
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
#define MAXN 100005

/*
为了方便，d数组重复用了2次
d[i] 先表示长度为i的最长不上升子串最优结尾导弹的高度
d[i] 后表示长度为i的最长上升子串最优结尾导弹的高度
*/
int h[MAXN],d[MAXN],n = 0,ans1 = 1,ans2 = 1;

int main(){
    for(n = 0;~scanf("%d",h + n);n ++);
    d[1] = h[0];
    //首先还是求最长不上升子序列
    for(int i = 1;i < n;i ++){
        if(h[i] <= d[ans1]){
            d[++ans1] = h[i];
        }else{
            *upper_bound(d + 1,d + ans1 + 1,h[i],greater<int>()) = h[i];
        }
    }
    //然后来求最长上升子序列
    for(int i = 1;i < n;i ++){
        if(h[i] > d[ans2]){
            d[++ans2] = h[i];
        }else{
            *lower_bound(d + 1,d + ans2 + 1,h[i]) = h[i];
        }
    }
    printf("%d\n%d",ans1,ans2);
}