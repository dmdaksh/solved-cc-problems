#include <bits/stdc++.h>

using namespace std;

map<unsigned long, unsigned long> dp;

unsigned long solve(unsigned long n){
    if(n <= 4){
        return n;
    }

    if(dp[n] != 0){
        return dp[n];
    }
    unsigned long a = solve(n/2)+solve(n/3)+solve(n/4);
    return dp[n] = max(a, n);
}

int main(){
    unsigned long n;
    while(cin >> n){
        cout << solve(n) << endl;
    }    
}
