/*
Luogu P1020 导弹拦截
Solution 2 2020/9/11 by bluesadi
时间复杂度为O(n^2)？，提交能拿到满分
Tags:　动态规划，贪心，二分查找
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define MAXN 100005

/*
为了方便，dp数组重复用了2次
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
            /*
            如果第i + 1枚导弹不能接到后面，那么从d[1]开始找
            找到d[k]，使第i + 1枚导弹的高度大于d[k]，并替换之
            以此实现d数组的更新
            */
            for(int j = 1;j <= ans1;j ++){
                if(h[i] > d[j]){
                    d[j] = h[i];
                    break;
                }
            }
        }
    }
    //然后来求最长上升子序列
    for(int i = 1;i < n;i ++){
        if(h[i] > d[ans2]){
            d[++ans2] = h[i];
        }else{
            for(int j = 1;j <= ans2;j ++){
                if(h[i] <= d[j]){
                    d[j] = h[i];
                    break;
                }
            }
        }
    }
    printf("%d\n%d",ans1,ans2);
}