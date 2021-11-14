#include <bits/stdc++.h>
using namespace std;

// Lowest commong subsequence

int main(){
    string str1;
    string str2;
    cin >> str1 >> str2;

    int m = str1.length(), n = str2.length();
    int lcs[m+1][n+1];

    for(int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                lcs[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1]){
                lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else{
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    cout << lcs[m][n] << endl;
}