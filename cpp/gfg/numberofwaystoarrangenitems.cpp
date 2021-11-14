#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[k];
    for(int i = 0; i < k; i++) cin >> arr[i];
    
    int C[n+1][n+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || i == j){
                C[i][j] = 1;
            }
            else{
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    int dp[k];
    int count = 0;
    dp[0] = 1;
    for(int i = 0; i < k; i++){
        dp[i+1] = dp[i] * C[count+arr[i]-1][arr[i]-1];
        count += arr[i];
    }
    cout << dp[k] << endl;
    
}
