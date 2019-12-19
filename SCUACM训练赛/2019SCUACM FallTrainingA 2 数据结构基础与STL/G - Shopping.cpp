#define LOCAL
#include <iostream>
#include <memory.h>
#include <map>
#include <algorithm>;

using namespace std; 
	
int main(){
	#ifdef LOCAL
		freopen("D:/ACM/cppÔ´ÎÄ¼þ/test.in","r",stdin);
	#endif
	int n;
	while(cin >> n){
		map<string,int> priceMap;
		for(int i = 0;i < n;i ++){
			string shop;
			cin >> shop;
			priceMap[shop] = 0;
		}
		int m;
		cin >> m;
		while(m --){
			for(int i = 0;i < n;i ++){
				int price;
				string shop;
				cin >> price >> shop;
				priceMap[shop] += price;
			}
			int rank = 1;
			int mPrice = priceMap["memory"];
			for(auto it = priceMap.begin();it != priceMap.end();it ++){
				if(it->second > mPrice){
					rank ++;
				}
			}
			cout << rank << endl;
		} 
	}
}
