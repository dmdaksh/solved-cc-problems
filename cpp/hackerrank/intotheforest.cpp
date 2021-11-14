#include <bits/stdc++.h>
using namespace std;


void dfs(int **arr, int *visited, int n, int m, int k){
    visited[k] = 1;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0 && arr[k][i] == 1){
            dfs(arr, visited, n, m, i);
        }
    }
}

int check(int *vis, int n, int *old){
    int ans = 0;
    for(int i = 0; i < n; i++) if(vis[i] == 1 && old[i] == 0) ans++; 
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    int **arr;
    arr = new int*[n];
    for(int i = 0; i < n; i++) arr[i] = new int[n];
    int x, y;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) arr[i][j] = 0;
    for(int i = 0; i < m; i++){
         cin >> x >> y;
        arr[x-1][y-1] = 1;
        arr[y-1][x-1] = 1;
    }
    int mx = INT_MIN, mn = INT_MAX, count = 0, temp = 0;
    int visited[n], old[n];
    for(int i = 0; i < n; i++) visited[i] = 0, old[i] = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            dfs(arr, visited, n, m, i);
            temp = check(visited, n, old);
            count++;
            mx = max(temp, mx);
            mn = min(temp, mn);
            for(int i = 0; i < n; i++) old[i] = visited[i];
        }
    }
    cout << mx << " " << mn << " " << count << endl;
}
