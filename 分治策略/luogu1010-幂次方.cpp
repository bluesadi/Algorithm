#include <iostream>

int highBit(int n){
	int sum = 0,bit = 0;
	while(sum != n){
		if(n & 1 << bit){
			sum += 1 << bit;
		}
		bit ++;
	}
	return bit;
}

int lowBit(int n){
	int bit = 0;
	while(!(n & 1 << bit)){
		bit++;
	}
	return bit;
}

void ans(int n){
	if(n == 2){
		printf("2");
	}else if(n == 1){
		printf("2(0)");
	}else if(n == 0){
		printf("0");
	}else{
		int lowbit = lowBit(n);
		for(int bit = highBit(n);bit >= lowbit;bit --){
			if(n & (1 << bit)){
				if(bit == 1){
					printf("2");
				}else{
					printf("2(");
					ans(bit);
					printf(")");
				}
				if(bit != lowbit){
					printf("+");
				}
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	ans(n);
} 
