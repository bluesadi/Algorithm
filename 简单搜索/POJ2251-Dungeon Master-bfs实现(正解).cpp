#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int grid[30][30][30];
int visit[30][30][30];
int l,r,c;
int s_l,s_r,s_c;
int e_l,e_r,e_c;
int ans = (int)1e5;

class Node{
public:
	int cur_l,cur_r,cur_c,step;
	
	Node(int cur_l,int cur_r,int cur_c,int step){
		this->cur_l = cur_l;
		this->cur_r = cur_r;
		this->cur_c = cur_c;
		this->step = step;
	}	
};

bool isOk(int cur_l,int cur_r,int cur_c){
	if(visit[cur_l][cur_r][cur_c]){
		return false;
	}else if(cur_l >= l || cur_r >= r || cur_c >= c || cur_l < 0 || cur_r < 0 || cur_c < 0){
		return false;
	}else if(grid[cur_l][cur_r][cur_c] == 0){
		return false;
	}
	return true;
}

bool pushNode(queue<Node*> &que,Node* node){
	if(isOk(node->cur_l,node->cur_r,node->cur_c)){
		if(node->cur_l == e_l && node->cur_r == e_r && node->cur_c == e_c){
			ans = node->step;
			return true;
		}else{
			que.push(node); 
			visit[node->cur_l][node->cur_r][node->cur_c] = 1;
		}
	}
	return false;
}

void bfs(){
	queue<Node*> que;
	que.push(new Node(s_l,s_r,s_c,0));
	visit[s_l][s_r][s_c] = 1; 
	while(!que.empty()){
		Node &v = *que.front();
		que.pop();
		if(pushNode(que,new Node(v.cur_l + 1,v.cur_r,v.cur_c,v.step + 1))) return;
		if(pushNode(que,new Node(v.cur_l - 1,v.cur_r,v.cur_c,v.step + 1))) return;
		if(pushNode(que,new Node(v.cur_l,v.cur_r + 1,v.cur_c,v.step + 1))) return;
		if(pushNode(que,new Node(v.cur_l,v.cur_r - 1,v.cur_c,v.step + 1))) return;
		if(pushNode(que,new Node(v.cur_l,v.cur_r,v.cur_c + 1,v.step + 1))) return;
		if(pushNode(que,new Node(v.cur_l,v.cur_r,v.cur_c - 1,v.step + 1))) return;
	}
}

int main(){
	//freopen("D:/ACM/cppÔ´ÎÄ¼þ/test.in","r",stdin);
	while(scanf("%d%d%d",&l,&r,&c)){
		memset(grid,0,sizeof grid);
		memset(visit,0,sizeof visit);
		ans = (int)1e5;
		if(l == 0) break;
		for(int i = 0;i < l;i ++){
			for(int j = 0;j < r;j ++){
				char row[35];
				scanf("%s",row);
				for(int k = 0;k < c;k ++){
					if(row[k] == 'S'){
						s_l = i;s_r = j;s_c = k;
						grid[i][j][k] = 2;
					}else if(row[k] == 'E'){
						e_l = i;e_r = j;e_c = k;
						grid[i][j][k] = -1;
					}else{
						grid[i][j][k] = row[k] == '.' ? 1 : 0;
					}
				}
			}
		}
		bfs();
		if(ans == (int)1e5){
			printf("Trapped!\n");
		}else{
			printf("Escaped in %d minute(s).\n",ans);
		}
	}
} 
