#include <cstdio>
#include <cstring>

int fa[3 * 50005] = {0};
int N,K,ans = 0;

int find(int n){
	if(fa[n] == n){
		return n;
	}
	int result = find(fa[n]);
	return fa[n] = result;
}

void unionn(int a,int b){
	if(a == b) return;
	a = find(a),b = find(b);
	fa[a] = b;	
}

bool eat(int X,int Y){
	return find(X) == find(N + Y);
}

int main(){
	freopen("D:/ACM/AlgorithmStudy/test.in","r",stdin);
	scanf("%d%d",&N,&K);
	for(int i = 1;i <= 3 * N;i ++) fa[i] = i;
	for(int i = 0;i < K;i ++){
		int a,X,Y;
		scanf("%d%d%d",&a,&X,&Y);
		if(X > N || Y > N){
			ans ++;
			continue;	
		}
		if(X == Y){
			if(a == 2) ans ++;
			continue;
		}
		if(a == 1){
			if(!eat(X,Y) && !eat(Y,X)){
				unionn(X,Y),unionn(X + N,Y + N),unionn(X + 2 * N,Y + 2 * N);
			}else{
				ans ++;				
			}
		}else{
			if(find(X) != find(Y) && !eat(Y,X)){
				unionn(X,N + Y),unionn(X + N,Y + 2 * N),unionn(X + 2 * N,Y);
			}else{
				ans ++;
			}
		}
	}
	printf("%d\n",ans);
} 
