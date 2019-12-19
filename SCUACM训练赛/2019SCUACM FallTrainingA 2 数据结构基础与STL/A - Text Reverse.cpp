#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std; 

int main(){
	//freopen("D:/ACM/cppÔ´ÎÄ¼þ/test.in","r",stdin);
	int n;
	cin >> n;
	stack<char> s;
	string temp;
	getline(cin,temp);
	for(int i = 0;i < n;i ++){
		string str;
		getline(cin,str);
		for(int j = 0;j < str.size();j ++){
			char c = str[j];
			if(c != ' '){
				s.push(c);
			}else{
				while(!s.empty()){
					cout << s.top();
					s.pop();
				}
				cout << " ";
			}
		}
		while(!s.empty()){
			cout << s.top();
			s.pop();
		}
		cout << endl;
	} 
} 
