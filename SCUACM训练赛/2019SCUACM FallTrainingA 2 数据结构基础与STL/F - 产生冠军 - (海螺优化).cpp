#define LOCAL 
#include <iostream>
#include <memory.h>
#include <set>
#include <algorithm>;

using namespace std; 


int main(){
	#ifdef LOCAL
		freopen("D:/ACM/cppÔ´ÎÄ¼þ/test.in","r",stdin);
	#endif
	int n;
	while(scanf("%d",&n),n != 0){
		set<string> total;
		set<string> losers;
		for(int i = 0;i < n;i ++){
			string winner,loser;
			cin >> winner >> loser;
			total.insert(winner);
			total.insert(loser);
			losers.insert(loser);
		}
		cout << (total.size() - losers.size() == 1 ? "Yes\n" : "No\n");
	}
	
}
	
