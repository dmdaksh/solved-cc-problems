#include <bits/stdc++.h>
using namespace std;

#define inf 10e9
typedef pair<int, int>  Pair;

class Graph{
    public:
    struct Node{
        int val, weight;
        Node *next;
        Node(int x, int y): val(x), weight(y), next(NULL){}
    };
    int V, E;
    Node **adjList;
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        adjList = new Node*[V];
    }
    void addEdge(int src, int dest, int weight){
        if(adjList[src] == NULL) adjList[src] = new Node(dest, weight);
        else{
            Node *newNode = new Node(dest, weight);
            newNode->next = adjList[src];
            adjList[src] = newNode;
        }
    }
    void Djikstra(int src){
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        pq.push({0, src});
        vector<int> key(V, INT_MAX);
        vector<bool> relax(V, false);
        key[0] = 0;
        while(!pq.empty()){
            Pair curr = pq.top();
            pq.pop();
            int vertex = curr.second;
            relax[vertex-1] = true;
            Node *edges = adjList[vertex];
            while(edges != NULL){
                int val = edges->val, weight = edges->weight;
                if(!relax[val-1] && key[val-1] > weight+key[vertex-1]){
                    key[val-1] = weight+key[vertex-1];
                    pq.push({key[val-1], val});
                }
                edges = edges->next;
            }
        }
        for(int i = 0; i < V; i++){
            cout << key[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Graph g(6, 7);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 0);
    g.addEdge(3, 5, 4);
    g.addEdge(4, 6, 6);
    g.addEdge(5, 6, 5);
    g.Djikstra(1);
}