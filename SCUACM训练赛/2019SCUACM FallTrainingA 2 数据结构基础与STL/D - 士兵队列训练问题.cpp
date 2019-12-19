#include <iostream>
#include <memory.h>
#include <vector>

using namespace std; 

int main(){
	//freopen("D:/ACM/cppÔ´ÎÄ¼þ/test.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i ++){
		int num;
		scanf("%d",&num);
		vector<int> vec;
		for(int i = 0;i < num;i ++){
			vec.push_back(i + 1);
		}
		int flag = 1;
		while(vec.size() > 3){
			for(int j = 1;j <= vec.size();j ++){
				if(j % ((flag % 2) == 1 ? 2 : 3) == 0){
					vec[j - 1] = 0;
				}
			}
			for(int j = 0;j < vec.size();j ++){
				if(vec[j] == 0){
					vec.erase(vec.begin() + j);
				}
			}
			flag ++;
		}
		if(vec.size() == 3){
			printf("%d %d %d\n",vec[0],vec[1],vec[2]);
		}else if(vec.size() == 2){
			printf("%d %d\n",vec[0],vec[1]);
		}else{
			printf("%d\n",vec[0]);
		}
	}

}
