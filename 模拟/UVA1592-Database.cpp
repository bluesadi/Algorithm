#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#include <algorithm>
#define inf 0x3f3f3f3f
#define ms(x,v) memset(x,v,sizeof x)
using namespace std;
#include <cstring>
#include <cstdio>
#include <map>
#include <sstream>

int n,m,r1,r2,c1,c2,ok,id;
map<string,int> database;
int table[12][10005];

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    while(scanf("%d%d",&n,&m) == 2){
        getchar();
        id = 0,ok = 0;
        string line;
        for(int i = 1;i <= n;i ++){
            getline(cin,line);
            stringstream ss(line);
            for(int j = 1;j <= m;j ++){
                string ele;
                getline(ss,ele,',');
                if(database.find(ele) == database.end()){
                    database[ele] = ++id;
                    table[j][i] = id;
                }else table[j][i] = database[ele];
            }
        }
        for(int i = 1;i <= m && !ok;i ++){
            for(int j = i + 1;j <= m && !ok;j ++){
                c1 = i,c2 = j;
                map<pair<int,int>,int> mapp;
                for(int k = 1;k <= n;k ++){
                    if(mapp.find({table[i][k],table[j][k]}) == mapp.end()) mapp[{table[i][k],table[j][k]}] = k;
                    else{
                        r1 = mapp[{table[i][k],table[j][k]}];
                        r2 = k;
                        ok = true;
                        break;
                    }
                }
            }
        }
        if(ok) printf("NO\n%d %d\n%d %d\n",r1,r2,c1,c2);
        else printf("YES\n");
    }
}