#include <bits/stdc++.h>
using namespace std;

int t, n;
unordered_map<int, string> numpad;

void solve(int *arr, int l, string ans){
    if(l == n){
        cout << ans << " ";
        return;
    }
    for(int key = 0; key < numpad[arr[l]].size(); key++){
        ans.push_back(numpad[arr[l]][key]);
        solve(arr, l+1, ans);
        ans.pop_back();
    }
}

int main() {
    numpad[2] = "abc";
    numpad[3] = "def";
    numpad[4] = "ghi";
    numpad[5] = "jkl";
    numpad[6] = "mno";
    numpad[7] = "pqrs";
    numpad[8] = "tuv";
    numpad[9] = "wxyz";
	cin >> t;
	while(t--){
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++) cin >> arr[i];

	    solve(arr, 0, "");
	    cout << endl;
	}
}