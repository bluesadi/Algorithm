#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue> 
#include<cmath>

using namespace std;
int prime[10001];
int visit[10001];
int step[10001];
int start,last;

void init(){
	for(int i = 1000;i <= 10000;i ++){
		int q = sqrt(i) + 1;
		for(int j = 2;j <= q;j ++){
			if(i % j == 0){
				prime[i] = 1;
			}			
		}
	}
}

int bfs(){
	queue<int> que;
	que.push(start);
	visit[start] = 1;
	step[start] = 0;
	while(!que.empty()){
		int v = que.front();
		//printf("debug:%d\n",v);
		que.pop();
		if(v == last){
			return step[v];
		}
		int b1 = v / 1000,b2 = v % 1000 / 100,b3 = v % 100 / 10,b4 = v % 10;
		for(int i = 1;i <= 4;i ++){
			for(int j = 0;j <= 9;j ++){
				int num;
				if(i == 1) num = j * 1000 + b2 * 100 + b3 * 10 + b4;
				else if(i == 2) num = b1 * 1000 + j * 100 + b3 * 10 + b4;
				else if(i == 3) num = b1 * 1000 + b2 * 100 + j * 10 + b4;
				else if(i == 4) num = b1 * 1000 + b2 * 100 + b3 * 10 + j;
				if(!visit[num] && !prime[num] && num > 1000){
					que.push(num);
					visit[num] = 1;
					step[num] = step[v] + 1; 
				}
			}
		}
	} 
	return -1;
}

int main(){
	//freopen("D:/ACM/AlgorithmStudy/¼òµ¥ËÑË÷/test.txt","r",stdin);
	init();
	int n;
	scanf("%d",&n);
	while(n --){
		memset(visit,0,sizeof visit);
		memset(step,-1,sizeof step);
		scanf("%d%d",&start,&last);
		int ans = bfs();
		if(ans == -1) printf("Impossible\n");
		else printf("%d\n",ans);
	}
} 
