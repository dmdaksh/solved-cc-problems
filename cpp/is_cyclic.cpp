#include<bits/stdc++.h>
using namespace std;

class Graph{
    int *parent;
    void initialize(){
        for(int i = 0; i < V; i++)
            parent[i] = i;
    }
    int root(int x){
        while(parent[x] != x) x = parent[x];
        return x;
    }
    void Union(int x, int y){
        int xroot = root(x);
        int yroot = root(y);
        if(xroot != yroot) parent[yroot] = xroot;
    }
    public:
    int V, E;
    vector<int> *adjList;
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        adjList = new vector<int>[V];
        parent = new int[V];
        initialize();
    }
    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
    }

    bool isCyclic(){
        for(int i = 0; i < V; i++){
            for(auto j:adjList[i]){
                int x = root(i);
                int y = root(j);
                if(x != y) Union(x, y);
                else return true;
            }
        }
        return false;
    }
    void printGraph(){
        for(int i = 0; i < V; i++){
            cout << i << " -> ";
            for(auto j:adjList[i]){
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph graph(4, 3);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    // graph.addEdge(1, 3);
    // graph.addEdge(2, 3);
    if(graph.isCyclic()) cout << "Yes" << endl;
    else cout << "No" << endl;
}














// map<char, string> m;

// int main(){
//     m['a'] = "e";
//     m['e'] = "i";
//     m['i'] = "aeou";
//     m['o'] = "eu";
//     m['u'] = "o";

// }