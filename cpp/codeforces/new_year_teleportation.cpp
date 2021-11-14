#include <iostream>

using namespace std;

int main(){
    int n = 3, t = 2;
    cin >> n >> t;

    int a[n];
    for (int i = 0; i < n-1; i ++){
        cin  >> a[i];
    }

    int cell = 1;
    while (cell < t){
        cell = a[cell-1] + cell; 
    }

    if (cell == t) cout << "YES" << endl;
    else cout << "NO" << endl;
}

