#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{ int v,w; };

struct Node{
    int x,dist;
    bool operator < (const Node& other) const{
        return dist < other.dist;
    }
};

class MinHeap{
private:
    int size;
    Node node[5000000];
public:
    MinHeap(){
       size = 0;
    }

    void insert(Node v){
        if(!size){
            node[++size] = v;
            return;
        }
        node[++size] = v;
        int k = size,faid = k / 2;
        Node fa = node[faid];
        while(v < fa){
            node[k] = fa;
            node[faid] = v;
            k = faid,faid /= 2,fa = node[faid];
            if(!faid) break;
        }
    }

    Node top(){
        return node[1];
    }

    Node pop(){
        Node rtn = node[1],v = node[size--];
        int k = 1;
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

int n,m,s,ans[10050],visit[10050];
vector<Edge> edges[10050];

void dijkstra(){
    MinHeap heap;
    heap.insert({s,0});
    while(heap.getSize()){
        Node node = heap.pop();
        if(visit[node.x]) continue;
        visit[node.x] = 1;
        ans[node.x] = node.dist;
        for(Edge& edge : edges[node.x]) heap.insert({edge.v,edge.w + node.dist});
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 0;i < m;i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges[u].push_back({v,w});
    }
    fill_n(visit,n + 50,0);
    fill_n(ans,n + 50,(1u << 31) - 1);
    dijkstra();
    for(int i = 1;i <= n;i ++) printf(i == n ? "%d\n" : "%d ",ans[i]);
}