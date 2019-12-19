#include<cstdio>
#include<cstring>
#include<algorithm>

int grid[30][30][30];
int visit[30][30][30];
int l,r,c;
int s_l,s_r,s_c;
int e_l,e_r,e_c;
int ans = (int)1e5;

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

void move(int cur_l,int cur_r,int cur_c,int m){
	if(cur_l == e_l && cur_r == e_r && cur_c == e_c){
		ans = std::min(ans,m);
		return;
	}
	visit[cur_l][cur_r][cur_c] = 1;
	if(isOk(cur_l + 1,cur_r,cur_c)){
		move(cur_l + 1,cur_r,cur_c,m + 1);
	}
	if(isOk(cur_l - 1,cur_r,cur_c)){
		move(cur_l - 1,cur_r,cur_c,m + 1);
	}
	if(isOk(cur_l,cur_r + 1,cur_c)){
		move(cur_l,cur_r + 1,cur_c,m + 1);
	}
	if(isOk(cur_l,cur_r - 1,cur_c)){
		move(cur_l,cur_r - 1,cur_c,m + 1);
	}
	if(isOk(cur_l,cur_r,cur_c + 1)){
		move(cur_l,cur_r,cur_c + 1,m + 1);
	}
	if(isOk(cur_l,cur_r,cur_c - 1)){
		move(cur_l,cur_r,cur_c - 1,m + 1);
	}
	visit[cur_l][cur_r][cur_c] = 0;//这一个不能去掉 
}

int main(){
	freopen("D:/ACM/cpp源文件/test.in","r",stdin);
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
		move(s_l,s_r,s_c,0);
		if(ans == (int)1e5){
			printf("Trapped!\n");
		}else{
			printf("Escaped in %d minute(s).\n",ans);
		}
	}
} 
