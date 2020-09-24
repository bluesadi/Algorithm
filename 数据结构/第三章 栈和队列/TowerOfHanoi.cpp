#include <cstdio>

void Hanoi(char from,char to,char sup,int n){
    if(!n) return;
    Hanoi(from,sup,to,n - 1);
    printf("mov disk from %c to %c.\n",from,to);
    Hanoi(sup,to,from,n - 1);
}

int main(){
    Hanoi('A','C','B',3);
}