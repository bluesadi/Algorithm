#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Pair{
public:
	char key;
	char value;
public:	
	string replace(string str){
		for(char &c : str){
			if(c == key){
				c = value;
			}
		}
		return str;
	}
};

Pair pairs[20];
vector<string> ans;

bool exists(string &num){
	return find(ans.begin(),ans.end(),num) != ans.end();
}

void dfs(int t,int start,int end,string num){
	if(t == 0){
		if(!exists(num)){
			ans.push_back(num);
		}
	}
	for(int i = start;i <= end;i ++){
		dfs(t - 1,0,end,pairs[i].replace(num));
	}
}

int main(){
	freopen("D:/ACM/cppÔ´ÎÄ¼ş/test.in","r",stdin);
	string num;
	int k;
	cin >> num >> k;
	for(int i = 0;i < k;i ++){
		Pair pair;
		cin >> pair.key >> pair.value;
		pairs[i] = pair;
	}	
	for(int i = 0;i <= k;i ++){
		dfs(i,0,k - 1,num);
	}
	for(string str : ans){
		cout << str << endl;
	}
	//cout << ans.size() << endl;
}
