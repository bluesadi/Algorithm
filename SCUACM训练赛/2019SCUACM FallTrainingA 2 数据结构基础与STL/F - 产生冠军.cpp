#include <iostream>
#include <memory.h>
#include <set>
#include <algorithm>;

using namespace std; 


int main(){
	#ifdef LOCAL
		freopen("D:/ACM/cppÔ´ÎÄ¼ş/test.in","r",stdin);
	#endif
	int n;
	while(scanf("%d",&n),n != 0){
		set<string> winners;
		set<string> losers;
		for(int i = 0;i < n;i ++){
			string winner,loser;
			cin >> winner >> loser;
			winners.insert(winner);
			losers.insert(loser);
		}
		for(string loser : losers){
			auto ptr = winners.find(loser);
			if(ptr != winners.end()){
				winners.erase(ptr);
			}
		}
		cout << (winners.size() == 1 ? "Yes\n" : "No\n");
	}    
	    
}
