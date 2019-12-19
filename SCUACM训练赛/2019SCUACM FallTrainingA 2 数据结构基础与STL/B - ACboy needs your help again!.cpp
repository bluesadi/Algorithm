#include <iostream>
#include <queue>
#include <stack>

using namespace std; 

int main(){
	//freopen("D:/ACM/cppÔ´ÎÄ¼þ/test.in","r",stdin);
	int total;
	scanf("%d",&total);
	for(int i = 0;i < total;i ++){
		int n;
		char type[5];
		scanf("%d%s",&n,&type);
		bool isQueue = type[2] == 'F';
		stack<int> s;
		queue<int> q;
		for(int j = 0;j < n;j ++){
			char action[5];
			scanf("%s",action);
			if(action[0] == 'I'){
				int num;
				scanf("%d",&num);
				if(isQueue){
					q.push(num);
				}else{
					s.push(num);
				}
			}else{
				if(isQueue){
					if(q.empty()){
						printf("None\n");
					}else{
						printf("%d\n",q.front());
						q.pop();
					}
				}else{
					if(s.empty()){
						printf("None\n");
					}else{
						printf("%d\n",s.top());
						s.pop();
					}
				}
			}
		}
	}
}
