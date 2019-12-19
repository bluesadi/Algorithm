#include<cstdio>
#include<cstring>

int visit[10][10];
int grid[10][10];
int ans = 0;
int n,k;

bool isOk(int r,int c){
	for(int i = 0;i < r;i ++){
		if(visit[i][c]){
			return false;
		}
	}
	return true;
}

void find(int row,int left){//�ӵڼ����� 
	for(int i = 0;i < n;i ++){
		if(grid[row][i] == 1 && isOk(row,i)){
			if(left == 1){
				ans ++;
			}else{
				visit[row][i] = 1;//�ؼ�,��������������������ص� ����һ��·�ߵ��� 
				for(int j = row + 1;j < n && n - j >= left - 1;j ++){
					find(j,left - 1);
				}
				visit[row][i] = 0;
			}
		}
	}
}

int main(){//�˻ʺ����� 
	//freopen("D:/ACM/cppԴ�ļ�/test.in","r",stdin);
	while(scanf("%d%d",&n,&k)){
		if(n == -1 && k == -1) break;
		memset(visit,0,sizeof visit);
		ans = 0;
		memset(grid,0,sizeof grid);//��ʼ�� 
		for(int i = 0;i < n;i ++){
			char row[10];
			scanf("%s",row);
			for(int j = 0;j < n;j ++){
				grid[i][j] = row[j] == '#' ? 1 : 0;
			}
		}
		for(int i = 0;i < n;i ++){
			find(i,k);
		}		
		printf("%d\n",ans);
	}
} 
