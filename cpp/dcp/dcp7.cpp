#include <bits/stdc++.h>
using namespace std;

bool isValid(int n, int m = -1){
    if(n >= 1 && n <= 9 && m == -1) return true;
    else if(n >= 0 && n <= 9 && m == 1) return true;
    else if(n >= 0 && n <= 6 && m == 2) return true;
    else return false;
}


int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 1; i < n; i++){
        if(isValid(s[i] - '0')) dp[i+1] += dp[i];
        if(isValid(s[i] - '0', s[i-1] - '0')) dp[i+1] += dp[i-1];
    }
    cout << dp[n] << endl;
}