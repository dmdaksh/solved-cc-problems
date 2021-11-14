#include <bits/stdc++.h>

using namespace std;


// Solution 1 O(n) time, O(1) space

// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     int prod[n] = {1}, temp = 1;
//     for(int i = 0; i < n; i++){
//         prod[i] = temp;
//         temp *= arr[i];
//     }
//     temp = 1;
//     for(int i = n-1; i >=0; i--){
//         prod[i] *= temp;
//         temp *= arr[i];
//     }
//     for(int i = 0; i < n; i++){
//         cout << prod[i] << " ";
//     }
//     cout << endl;
// }

// Solution 2 O(n) time, O(1) space

int main(){
    long double sum = 0;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += log10(arr[i]);
    }
    for(int i = 0; i < n; i++){
        cout << pow(10.0, sum-log10(arr[i])) << " "; 
    }
    cout << endl;

}