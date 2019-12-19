#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int n,k;
int visit[100001] = {0};

class Node{
public:
	int x;
	int step;
	
	Node(int x,int step){
		this->x = x;
		this->step = step;
	}
};

int bfs(){
	queue<Node*> que;
	que.push(new Node(n,0));
	visit[n] = 1;
	while(!que.empty()){
		Node* front = que.front();
		int x = front->x;
		que.pop();
		if(front->x == k){
			return front->step;
		}
		if(x - 1 >= 0 && !visit[x - 1]){
			visit[x - 1] = 1;
			que.push(new Node(x - 1,front->step + 1));
		}
		if(x + 1 <= 100000  && x <= k && !visit[x + 1]){
			visit[x + 1] = 1;
			que.push(new Node(x + 1,front->step + 1));
		}
		if(x * 2 <= 100000 && x <= k && !visit[x * 2]){
			visit[x * 2] = 1;
			que.push(new Node(x * 2,front->step + 1));
		}
	}
	return -1;
}

int main(){
	//freopen("D:/ACM/cppÔ´ÎÄ¼ş/test.in","r",stdin);
	scanf("%d%d",&n,&k);
	memset(visit,0,sizeof visit);
	printf("%d\n",bfs());
} 
