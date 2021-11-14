#include <bits/stdc++.h>
using namespace std;

struct subset{
    int parent, rank;
};

int Find(subset *subsets, int i){
    if(subsets[i].parent != i) subsets[i].parent = Find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(subset *subsets, int x, int y){
    int xroot = Find(subsets, x);
    int yroot = Find(subsets, y);
    if(subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;

    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

class Graph{
    public:
    struct Edge{
        int src, dest, weight; 
    };
    int V, E;
    Edge *edge;
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        this->edge = new Edge[E];
    }
    static bool Comp(Edge e1, Edge e2){
        return e1.weight < e2.weight;
    }   
    void KruskalMST(){
        Edge result[V];
        int e = 0, i = 0;
        sort(this->edge, this->edge+this->E, Comp);
        subset *subsets = new subset[V];
        for(int v = 0; v < V; v++){
            subsets[v].parent = v;
            subsets[v].rank = 0;            
        }
        while(e < V-1 && i < E){
            Edge nextEdge = edge[i++];
            int x = Find(subsets, nextEdge.src);
            int y = Find(subsets, nextEdge.dest);
            if(x != y){
                result[e++] = nextEdge;
                Union(subsets, x, y);
            }
        }
        for(int i = 0; i < e; i++) cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
    }


};



int main(){
    Graph *graph = new Graph(4, 5);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    graph->KruskalMST();
}
