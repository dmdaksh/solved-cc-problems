#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> *&adjList, int *vis, int n, int v, int parent, int godfather){
    vis[v] = 1;
    for(auto i:adjList[v]){
        if(!vis[i]){
            if(dfs(adjList, vis, n, i, v, godfather))
                return true;
        }
        else if(i != parent){
            if(godfather == i) return true;
        }
    }
    return false;
}

int solve(vector<int> *&adjList, set<int> &friends, int n, int k){
    int vis[n];
    for(int v = 0; v < n; v++){
        if(adjList[v].size() < k) continue;
        else{
            if(!friends.count(v)){
                memset(vis, 0, sizeof(vis));
                if(dfs(adjList, vis, n, v, -1, v)){
                    friends.insert(v);
                }
            }
        }
    }
    return friends.size();
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> *adjList = new vector<int>[n];
    int x, y;
    set<int> friends;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        adjList[x-1].push_back(y-1);
        adjList[y-1].push_back(x-1);
    }
    cout << solve(adjList, friends, n, k) << endl;

}