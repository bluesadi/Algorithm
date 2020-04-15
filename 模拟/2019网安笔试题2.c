#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    srand(time(NULL));
    int *arr = (int*)malloc((n + 5) * sizeof(int)),*visit = (int*)malloc((n + 5) * sizeof(int));
    double sum = 0;
    for(int i = 0;i < n;i ++){
        sum += arr[i] = rand() % n;
        visit[arr[i]] = 1;
    }
    printf("平均数:%lf\n",sum / n);
    for(int i = 0;i < n;i ++){
        if(visit[i]) printf("%d ",i);
    }
}