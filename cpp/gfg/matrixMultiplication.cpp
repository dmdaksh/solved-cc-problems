#include <bits/stdc++.h>
using namespace std;

#define FOR(i, k, n) for(int i = k; i < n; i++)

int main(){
	vector<int> dim{5, 4, 6, 2, 7};
	int n = dim.size();
	int dp[n][n], index[n][n];

	memset(dp, 0, sizeof(dp));
	memset(index, 0, sizeof(index));
	
	FOR(len, 2, n){
		FOR(i, 1, n-len+1){
			int j = i+len-1;
			dp[i][j] = INT_MAX;
			FOR(k ,i, j){
				if(dp[i][j] > dp[i][k]+dp[k+1][j]+(dim[i-1]*dim[k]*dim[j])){
					dp[i][j] = dp[i][k]+dp[k+1][j]+(dim[i-1]*dim[k]*dim[j]);
					index[i][j] = k;
				}
			}
		}
	}
	FOR(i, 0,  n){
		FOR(j, 0, n) cout << dp[i][j] << " \t	";
		cout << endl;
	} 
	cout << endl << endl;
	FOR(i, 0,  n){
		FOR(j, 0, n) cout << index[i][j] << " \t	";
		cout << endl;
	} 
	cout << dp[1][n-1] << endl;
}