#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

char tmp[10];
int N,cur_firid = 0,cur_secid = 0;
map<string,int> firname_map,secname_map;//name -> id
map<int,string> firstperson;
map<int,vector<int>> sons;
map<int,int> fa;

int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d",&N);
    while(N --){
        string firname,secname,faname;
        cin >> firname >> secname;
        scanf("%s%s",tmp,tmp);
        cin >> faname;
        int firid = firname_map[firname],secid = secname_map[secname],faid = secname_map[faname];
        if(!firid) firname_map[firname] = firid = ++cur_firid;
        if(!secid) secname_map[secname] = secid = ++cur_secid;
        if(!faid) secname_map[faname] = faid = ++cur_secid;
        
    }
}