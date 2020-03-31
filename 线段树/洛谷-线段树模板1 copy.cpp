#define LOCAL
#define debug(x) cout << "debug:" << x << endl
#include <iostream>
#define ms(x,v) memset(x,v,sizeof x)
#define inf 0x3f3f3f3f
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

int N,M,t,x,y;
LL input[100005],k;

struct Node{
    int l,r;
    LL v,lz;
};

Node tree[200005];

void push_down(int i){
    if(tree[i].lz != 0){
        tree[i * 2].lz += tree[i].lz;
        tree[i * 2 + 1].lz += tree[i].lz;
        int mid = (tree[i].l + tree[i].r) >> 1;
        tree[i * 2].v += (mid - tree[i * 2].l + 1) * tree[i].lz;
        tree[i * 2 + 1].v += (tree[i * 2 + 1].r - mid) * tree[i].lz; 
        tree[i].lz = 0;
    }
}

void build(int i,int l,int r){
    if(l == r){
        tree[i].v = input[l],tree[i].l = l,tree[i].r = r,tree[i].lz = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * i ,l,mid);
    build(2 * i + 1,mid + 1,r);
    tree[i].v = tree[2 * i].v + tree[2 * i + 1].v;
    tree[i].l = l,tree[i].r = r;
}

LL search(int i,int l,int r){
    if(tree[i].l > r || tree[i].r < l) return 0;
    if(tree[i].l >= l && tree[i].r <= r) return tree[i].v;
    push_down(i);
    LL s = 0;
    if(tree[i * 2].r >= l) s += search(i * 2,l,r);
    if(tree[i * 2 + 1].l <= r) s += search(i * 2 + 1,l,r);
    return s;
}

void add(int i,int l,int r,LL v){
    if(tree[i].r <= r && tree[i].l >= l){
        tree[i].v += v * (tree[i].r - tree[i].l + 1);
        tree[i].lz += v;
        return;
    }
    push_down(i);
    if(tree[i * 2].r >= l) add(i * 2,l,r,v);
    if(tree[i * 2 + 1].l <= r) add(i * 2 + 1,l,r,v);
    tree[i].v = tree[i * 2].v + tree[i * 2 + 1].v;
}


int main(){
#ifdef LOCAL
    freopen("D:/ACM/Algorithm/test.in","r",stdin);
#endif
    scanf("%d%d",&N,&M);
    for(int i = 1;i <= N;i ++) scanf("%lld",input + i);
    build(1,1,N);
    while(M--){
        scanf("%d",&t);
        if(t == 1){
            scanf("%d%d%lld",&x,&y,&k);
            add(1,x,y,k);
        }else if(t == 2){
            scanf("%d%d",&x,&y);
            printf("%lld\n",search(1,x,y));
        }
    }
}