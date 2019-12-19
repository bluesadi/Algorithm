#include <cstdio>
#include <cstring>

int pre[(int)1e5 + 5];
int sum[(int)1e5 + 5] = {0};
int num[(int)1e5 + 5];

int find(int a){
	if(pre[a] == -1){
		return a;
	}
	int result = find(pre[a]);
	sum[a] += sum[pre[a]];
	return pre[a] = result;
}

void Union(int a,int b){
	a = find(a),b = find(b);
	pre[a] = b;
	sum[a] = num[b];
	num[b] += num[a];
}


int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	int P;
	scanf("%d\n",&P);
	memset(pre,-1,sizeof pre);
	for(int i = 1;i <= P;i ++) num[i] = 1;
	while(P --){
		char c = getchar();
		if(c == 'M'){
			int a,b;
			scanf("%d %d\n",&a,&b);
			Union(a,b); 
		}else{
			int a;
			scanf("%d\n",&a);
			find(a);
			printf("%d\n",sum[a]);
		}
	}
} 
