#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;

class Graph{
    public:
    struct Node{
        int val, weight;
        Node *next;
        Node(int x, int y):val(x), weight(y), next(NULL){}
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
    void Djikstra(int src, int dest){
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        vector<int> key(V, INT_MAX);
        vector<bool> relax(V, false);
        key[src] = 0;
        pq.push({key[src], src});
        while(!pq.empty()){
            Pair curr = pq.top();
            pq.pop();
            int vertex = curr.second;
            relax[vertex] = true;
            Node *edges = adjList[vertex];
            while(edges != NULL){
                int val = edges->val, weight = edges->weight;
                if(!relax[val] && key[val] > key[vertex]+weight){
                    key[val] = key[vertex]+weight;
                    pq.push({key[val], val});
                }
                edges = edges->next;
            }
        }
        cout << key[dest] << endl;
    }
};


int main() {
    int n, m, p, q, t;
    cin >> n >> m >> p >> q >> t;
    int x, y;
    Graph graph(n, m);
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        if(x == y) continue;
        graph.addEdge(x-1, y-1, t);
        graph.addEdge(y-1, x-1, t);
    }
    graph.Djikstra(p-1, q-1);

}
