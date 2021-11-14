#include <bits/stdc++.h>
using namespace std;

void solve(int **a, int n, int target){
    for(int i = 1; i < pow(2, n); i++){
        int num = 0, den = 0;
        for(int j = 0; j < n; j++){
            if((i&(1<<j)) != 0){
                num += a[j][0];
                den += a[j][1];
            }
            if(den != 0 && (num/den) == target){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, target;
        cin >> n >> target;
        int **a = new int*[n];
        for(int i = 0; i < n; i++){
            a[i] = new int[2];
            cin >> a[i][0] >> a[i][1];
        }
        solve(a, n, target);
    }
}