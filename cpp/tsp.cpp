#include<bits/stdc++.h>
using namespace std;
typedef unordered_map<string, vector<string>> um;
vector<vector<int>> dist { { 0, 10, 15, 20 }, 
                       { 10, 0, 35, 25 }, 
                       { 15, 35, 0, 30 }, 
                       { 20, 25, 30, 0 } };
const int n = dist.size();
const int VISITED_ALL = (1<<n) - 1;
int **dp;

int tsp(int mask, int pos) {  
    if(mask == VISITED_ALL) return dist[pos][0];
    if(dp[pos][mask] != -1) return dp[pos][mask];

    int ans = INT_MAX;
    
    for(int city = 0; city < n; city++){
        if((mask & (1 << city)) == 0){
            int newAns = dist[pos][city] + tsp(mask|(1<<city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[pos][mask] = ans;
}

int main(){
    dp = new int*[n];
    for(int i = 0; i < n; i++){
        dp[i] = new int[VISITED_ALL];
        for(int j = 0; j < VISITED_ALL; j++) dp[i][j] = -1;
    }
    cout << tsp(1, 0) << endl;

}


// O(n!) graph solution of tsp

// #include <bits/stdc++.h>
// using namespace std;


// int solve(int **cost, int *vis, int n, int k){
// 	vis[k] = 1;
// 	int Min = INT_MAX;
// 	for(int i = 0; i < n; i++){
// 		if(vis[i] == 0){
// 			Min = min(Min, cost[k][i] + solve(cost, vis, n, i));
// 			vis[i] = 0;
// 		}
// 	}
// 	if(Min != INT_MAX) return Min;
// 	else return cost[k][0];
// }

// int main(){
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		int n;
// 		cin >> n;
// 		int **cost = new int*[n];
// 		for(int i = 0; i < n; i++){
// 			cost[i] = new int[n];
// 			for(int j = 0; j < n; j++){
// 				cin >> cost[i][j];
// 			}
// 		}

// 		int *vis = new int[n];
// 		memset(vis, 0, n*sizeof(int));
// 		cout << solve(cost, vis, n, 0) << endl;
// 	}
// }
