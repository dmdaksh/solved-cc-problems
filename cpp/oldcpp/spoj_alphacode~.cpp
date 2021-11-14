#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    while(cin >> str){
        int dp[5000] = {0};
        dp[0] = 1;
        int curr, pre, ind = 0;
        int l = str.length();  
        while(l--){
            curr = str[ind]-'0';
            if(ind == 0){
                ind++;
                pre = curr;
                continue;
            }              
            if(curr != 0){
                dp[ind] += dp[ind-1];
            }
            int x = pre*10 + curr;
            if(x >= 10 && x <= 26){
                if(ind == 1){
                    dp[ind]++;
                }
                else{
                    dp[ind] += dp[ind-2];
                }
            }
            ind++;
            pre = curr;
        }
        if(str[0]!='0'){
            cout << dp[ind-1] << endl;
        }  
        else{
            cout << 0 << endl;
        }    
    }
}