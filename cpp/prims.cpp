#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;

class Graph{
    public:
    struct Node{
        int val, weight;
        Node *next;
        Node(): val(-1), weight(-1), next(NULL){}
        Node(int x, int y): val(x), weight(y), next(NULL){}
    };
    int E, V;
    Node **adjList;
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        adjList = new Node*[V];
    }
    void addEdge(int src, int dest, int weight){
        if(adjList[src] == NULL){
            adjList[src] = new Node(dest, weight);
            return;
        }
        Node *newNode = new Node(dest, weight);
        newNode->next = adjList[src];
        adjList[src] = newNode;
    }
    void Prims(){
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);
        pq.push(make_pair(0, 0));
        key[0] = 0;
        int i = 0;
        while(!pq.empty()){
            cout << i++ << endl;
            int vertex = pq.top().second;
            Node *edges = adjList[vertex];
            pq.pop();
            inMST[vertex] = true;
            cout << "vertex: " << vertex << endl;
            while(edges != NULL){
                int v = edges->val;
                int weight = edges->weight;
                if(inMST[v] == false && key[v] > weight){
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = vertex;
                    cout << "key: " << key[v] << " " << v << endl;
                }
                edges = edges->next;
            }
        }
        for(int i = 1; i < V; i++){
            cout << parent[i] << " " << i << endl;
        }
    }
    void printGraph(){
        for(int i = 0; i < V; i++){
            Node *newNode = adjList[i];
            cout << i << " --> ";
            if(newNode == NULL) cout << "NULL";
            while(newNode != NULL){
                if(newNode->next == NULL) cout << newNode->val << " " << newNode->weight << " ";
                else cout << newNode->val << " " << newNode->weight << " -> ";
                newNode = newNode->next;
            }
            cout << endl;
        }
    }

};

int main(){
    Graph graph(4, 5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 0, 10);
    graph.addEdge(0, 3, 5);
    graph.addEdge(3, 0, 5);
    graph.addEdge(0, 2, 6);
    graph.addEdge(2, 0, 6);
    graph.addEdge(1, 3, 15);
    graph.addEdge(3, 1, 15);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 2, 4);
    graph.Prims();
    graph.printGraph();

}