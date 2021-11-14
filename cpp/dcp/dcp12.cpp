#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int num_steps(int n){
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = num_steps(n-1)+num_steps(n-2);
}

int main(){
    int n;
    while(cin >> n){
        if(n == -1) break;
        dp.assign(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        cout << num_steps(n) << endl << endl;
    }
}