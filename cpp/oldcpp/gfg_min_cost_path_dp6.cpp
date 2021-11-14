// O(mn)

#include <bits/stdc++.h>
using namespace std;
#define min(x, y, z) x<y?(x<z?x:z):(y<z?y:z)
#define N 3
int cost[N][N];
int dp[N][N];
int solve(int m, int n){
    if(m < 0 || n < 0){
        return INT_MAX;
    }
    else if(dp[m][n] != 0){
        return dp[m][n];
    } 
    else if(m == 0 && n == 0){
        return cost[m][n];
    }
    else{
        int mn = min(solve(m-1, n-1), solve(m-1, n), solve(m, n-1));
        return dp[m][n] = cost[m][n] + mn;
    }
}

int main(){
    for (size_t i = 0; i < N; i++){
        for (size_t j = 0; j < N; j++){
            cin >> cost[i][j];
        }
        
    }
    int m, n;
    cin >> m >> n;
    cout << solve(m, n) << endl;
}