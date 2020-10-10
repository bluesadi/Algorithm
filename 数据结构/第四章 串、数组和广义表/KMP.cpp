/*
KMP算法
可能还是没讲清楚，想明白之后再补充
2020/10/10 by bluesadi
*/
#include <cstdio>
#define MAXN 1000000

/*
next[i]表示，模式串下标为i的字符之前子串的最长公共前后缀长度。
next[0] = -1
如abab，next[1] = 0, next[2] = 0, next[3] = 1
*/
int next[MAXN];

void GetNext(const char *P){
    next[0] = -1;
    int j = 0,k = -1;
    /*
    类似一个递归的思想：
    如果若next[j - 1] = k，P[j] == P[k]，则next[j] = k + 1
    如果P[j] != P[k]，则令k = next[k]得到一个更小的公共前后缀，再继续上一步
    一直回溯到k == -1时，说明没有公共前后缀，则next[j] = 0
    */
    while(P[j]){
        if(k == -1 || P[j] == P[k]){
            j++,k++;
            next[j] = k;
        }else k = next[k];
    }
}

int KMP(const char *S, const char *P){
    GetNext(P);
    int i = 0,j = 0;
    /*
    若P匹配到尽头，则说明匹配成功
    S匹配到尽头而P没有匹配到尽头，则说明匹配失败
    */
    while(S[i] && P[j]){
        //j = -1则说明P[0] != S[i]，应让i++然后继续匹配
        if(j == -1 || S[i] == P[j]) i++,j++;
        //失配的话则滑动模式串
        else j = next[j];
    }
    //匹配成功返回第一个字符的下标
    if(!P[j]) return i - j;
    return -1;
}
int main(){
    printf("%d",KMP("abcd","bc"));
}