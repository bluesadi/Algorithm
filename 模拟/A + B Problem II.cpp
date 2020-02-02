#define LOCAL
#define ms(x,v) memset(x,v,sizeof x)
#define debug(x) cout << "debug:" << x << endl
#define inf 1 << 30
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
char num1[1005],num2[1005];

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&T);
    for(int i = 1;i <= T;i ++){
        scanf("%s%s",num1,num2);
        char result[1005] = {0};
        int len1 = strlen(num1),len2 = strlen(num2),len = max(len1,len2);
        bool carry_bit = 0;
        for(int i = 1;i <= len;i ++){
            int v1 = len1 - i >= 0 ? num1[len1 - i] - '0' : 0,v2 = len2 - i >= 0 ? num2[len2 - i] - '0' : 0;
            result[len - i + 1] = (v1 + v2 + carry_bit) % 10 + '0';
            carry_bit = (v1 + v2 + carry_bit) >= 10;
        }
        if(carry_bit) result[0] = 1;
        printf("Case %d:\n%s + %s = %s\n",i,num1,num2,result + (result[0] == '\0'));
        if(i != T) printf("\n");
    }
}