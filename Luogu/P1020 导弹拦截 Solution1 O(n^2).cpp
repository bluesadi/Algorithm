/*
Luogu P1020 导弹拦截
Solution 1 2020/9/11 by bluesadi
时间复杂度为O(n^2)，提交仅能拿到一半的分
Tags:　动态规划，贪心，二分查找
*/
#include <cstdio>
#include <algorithm>
using std::max;
#define MAXN 100005

/*
为了方便，dp数组重复用了2次
dp[i] 先表示以i结尾的最长不上升子串的长度
dp[i] 后表示以i结尾的最长上升子串的长度
*/
int h[MAXN],dp[MAXN],n = 0,ans1 = 1,ans2 = 1;

int main(){
    //读取导弹的高度到h数组中，n表示导弹的个数
    for(n = 0;~scanf("%d",h + n);n ++);
    //求出最长不上升子串的长度 ans1
    for(int i = 0;i < n;i ++){
        dp[i] = 1;
        for(int j = i - 1;j >= 0;j --){
            if(h[j] >= h[i])
                dp[i] = max(dp[i],dp[j] + 1);
        }
        ans1 = max(ans1,dp[i]);
    }
    //求出最长上升子串的长度 ans2
    for(int i = 0;i < n;i ++){
        dp[i] = 1;
        for(int j = i - 1;j >= 0;j --){
            if(h[j] < h[i])
                dp[i] = max(dp[i],dp[j] + 1);
        }
        ans2 = max(ans2,dp[i]);
    }
    printf("%d\n%d",ans1,ans2);
}