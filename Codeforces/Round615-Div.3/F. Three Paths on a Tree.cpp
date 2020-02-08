#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


int n,a,b,c,visit[200050],u,v,lena = 0,d = 0,disa[200050],disb[200050];
vector<int> ver[200050];

void dfsa(int i,int len){
    visit[i] = 1;
    if(len > lena) a = i,lena = len;
    for(int v : ver[i]){
        if(!visit[v]) dfsa(v,len + 1);
    }
}

void dfsb(int i,int len){
    visit[i] = 1;
    if(len > d) b = i,d = len;
    for(int v : ver[i]){
        if(!visit[v]) dfsb(v,len + 1);
    }
}

void dfsdisa(int i,int len){
    visit[i] = 1;
    disa[i] = len;
    for(int v : ver[i]){
        if(!visit[v]) dfsdisa(v,len + 1);
    }
}

void dfsdisb(int i,int len){
    visit[i] = 1;
    disb[i] = len;
    for(int v : ver[i]){
        if(!visit[v]) dfsdisb(v,len + 1);
    }
}

void findD(){
    ms(visit,0);
    dfsa(1,0);
    ms(visit,0);
    dfsb(a,0);
}

void findDis(){
    ms(visit,0);
    dfsdisa(a,0);
    ms(visit,0);
    dfsdisb(b,0);
}

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d%d",&u,&v);
        ver[u].push_back(v),ver[v].push_back(u);
    }
    findD();
    findDis();
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(i != a && i != b){
            int tmp = (disa[i] + disb[i] + d) / 2;
            if(tmp > ans){
                ans = tmp;
                c = i;
            }
        }
    }
    printf("%d\n%d %d %d\n",ans,a,b,c);
}