#include <cstdio>
#include <cstring>
#include <algorithm>
int T,n,k,q;

struct Node{
    int round,order,value;

    bool operator < (Node& another)const {
        if(another.round == round) return order < another.order;
        return round < another.round;
    }

}nodes[3000005];

int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&q);
        for(int i = 0;i < n;i ++){
            if(!(i % k)){
                nodes[i].round = 1;
                nodes[i].order = i / k + 1;
            }else{
                nodes[i].round = nodes[i - i / k - 1].round + 1;
                nodes[i].order = nodes[i - i / k - 1].order;
            }
            nodes[i].value = i + 1;
        }
        std::sort(nodes,nodes + n);
        while(q--){
            int i;
            scanf("%d",&i);
            printf("%d\n",nodes[i - 1].value);
        }
    }
}