#include<cstdio>
#include<cstring>
#include<cmath>

int pre[30005],num[30005],front[30005];

int find(int i){
	if(pre[i] == i){
		return i;
	}
	int f = find(pre[i]);
	front[i] += front[pre[i]];
	return pre[i] = f;
}

void merge(int i,int j){
	i = find(i),j = find(j);
	pre[i] = j;
	front[i] = num[j];
	num[j] += num[i];
}

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	int T;
	scanf("%d\n",&T);
	for(int i = 0;i < 30005;i ++){
		pre[i] = i;
		num[i] = 1;
		front[i] = 0;
	}
	while(T --){
		char c = getchar();
		int i,j;
		scanf("%d %d\n",&i,&j);
		if(c == 'M'){
			merge(i,j);
		}else{
			//��������д:printf(find(i) == find(j) ? "%d\n" : "-1\n",abs(front[j] - front[i]));
			//ִ��˳��ȷ�� 
			if(find(j) == find(i)){
				printf("%d\n",abs(front[j] - front[i]) - 1);
			}else{
				printf("-1\n");
			}
		}
	}	
} 
