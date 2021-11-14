#include <bits/stdc++.h>
using namespace std;

void rev(int *a, int l, int h){
    while(l < h){
        swap(a[l], a[h]);
        l++;
        h--;
    }
}

int main() {
    int n, k;
    cin >> n;
    int *a;
    a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    k %= n;
    rev(a, 0, n-1);
    rev(a, 0, k-1);
    rev(a, k, n-1);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}