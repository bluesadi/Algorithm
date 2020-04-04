#include <cstdio>

class MinHeap{
private:
    int size,node[200000];
public:
    MinHeap(){
       size = 0;
    }

    MinHeap(int *input,int n){
        for(int i = 0;i < n;i ++)
            insert(input[i]);
    }

    void insert(int v){
        if(!size){
            node[++size] = v;
            return;
        }
        node[++size] = v;
        int k = size,faid = k / 2,fa = node[faid];
        while(v < fa){
            node[k] = fa;
            node[faid] = v;
            k = faid,faid /= 2,fa = node[faid];
            if(!faid) break;
        }
    }

    int top(){
        return node[1];
    }

    int pop(){
        int rtn = node[1],k = 1,v = node[size--];
        node[1] = v;
        while(2 * k <= size){
            if(2 * k + 1 <= size && node[2 * k + 1] < node[2 * k]){
                if(node[2 * k + 1] < node[k]){
                    node[k] = node[2 * k + 1];
                    node[2 * k + 1] = v;
                    k = 2 * k + 1;
                }else break;
            }else{
                if(node[2 * k] < node[k]){
                    node[k] = node[2 * k];
                    node[2 * k] = v;
                    k *= 2;
                }else break;
            }
        }
        return rtn;
    }

    int getSize(){
        return size;
    }

};

int main(){
    int input[200000] = {3,2,4,23,2421,-5,231,-23,4,-1};
    MinHeap heap(input,10);
    while(heap.getSize()) printf("%d\n",heap.pop());
}
