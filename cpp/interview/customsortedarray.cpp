#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void solve(int *a, int n){
    int odd = 0, even = n-1;
    while(odd < even){
        while((a[odd]%2) == 0 && odd < n) odd++;
        while((a[even]%2) != 0 && even >= 0) even--;
        if(odd < even){
            swap(a[odd], a[even]);
            odd++, even--;
            ans++;
        }
    }
    for(int i = 0; i < n; i++) cout << a[i] << " " ;
    cout << endl;
    cout << ans << endl;
}

int main(){
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    solve(a, n);
}