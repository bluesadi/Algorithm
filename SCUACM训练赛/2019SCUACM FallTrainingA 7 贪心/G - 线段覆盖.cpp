#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;

struct Line{
    int a,b;
    
    bool operator < (Line &another) const{
        return b < another.b;
    }
};

Line lines[(int)1e6 + 5] = {0};

int main(){
    freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++){
        scanf("%d%d",&(lines[i].a),&(lines[i].b));
    }
    sort(lines,lines + n);
    int last = -1,ans = n;
    for(int i = 0;i < n;i ++){
        if(lines[i].a < last){
            ans --;
        }else{
            last = lines[i].b;
        }
    }
    printf("%d\n",ans);
}
