#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
    struct node{
        int val;
        node *next;
        node():val(-1), next(NULL){}
        node(int x):val(x), next(NULL){}
    };
    node **network;
    int len = 10;
    graph(){
        network = new node*[10];
    }
    graph(int x){
        len = x;
        network = new node*[x];
    }
    void addNode(int x, int y){
        if(network[x] == NULL){
            network[x] = new node(y);
            return;
        }
        node *newNode = new node(y);
        newNode->next = network[x];
        network[x] = newNode;
    }
    void dfs(int starting = 0, int x = -1){
        stack<node*> st;
        st.push(network[starting]);
        vector<int> visited(len, 0);
        visited[starting] = 1;
        cout << starting << " ";
        while(!st.empty()){
            node *child = st.top();
            while(child != NULL && visited[child->val] == 1) child = child->next;
            if(child == NULL) st.pop();
            else{
                visited[child->val] = 1;
                cout << child->val << " ";
                if(x == child->val){
                    cout << endl;
                    return;
                }
                st.push(network[child->val]);
            }
        }
        cout << endl;
    }
    void bfs(int starting = 0, int x = -1){
        queue<node*> q;
        q.push(network[starting]);
        vector<int> visited(len, 0);
        visited[starting] = 1;
        cout << starting << " ";
        while(!q.empty()){
            node *child = q.front();
            while(child != NULL && visited[child->val] == 1) child = child->next;
            if(child == NULL) q.pop();
            else{
                visited[child->val] = 1;
                cout << child->val << " ";
                if(x == child->val){
                    cout << endl;
                    return;
                }
                q.push(network[child->val]);
            }
        }
        cout << endl;
    }
    void printGraph(){
        for(int i = 0; i < len; i++){
            node *newNode = network[i];
            cout << i << "-> ";
            while(newNode != NULL){
                if(newNode->next == NULL) cout << newNode->val << " ";
                else cout << newNode->val << "-> ";
                newNode = newNode->next;
            }
            cout << endl;
        }
    }
};


int main(){
    graph g(4);
    g.addNode(0,1);
    g.addNode(0,2);
    g.addNode(1,3);
    g.addNode(2,3);
    g.addNode(3,0);
    g.printGraph();
    g.dfs();
    g.bfs();
}