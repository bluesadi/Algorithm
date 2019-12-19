#include<cstdio>

void swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}

int gcd(int a,int b){
	if(a < b) swap(a,b);
	return a % b == 0 ? b : gcd(b,a % b);
}

int gcd_(int a,int b){
	if(a < b) swap(a,b);
	return a == b ? b : gcd(b,a - b); 
}

int lcm(int a,int b){
	return a * b / gcd(a,b);
}

int main(){
	printf("%d",gcd_(245,15));
}
