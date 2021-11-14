#include <bits/stdc++.h>
using namespace std;

// // O(n^2)
// int lis(int arr[], int n){
//     int lis[n];
//     lis[0] = 1;
//     for(int i = 1; i < n; i++){
//         lis[i] = 1;
//         for(int j = 0; j < i; j++){
//             if(arr[i]>arr[j] && lis[i] < lis[j]+1){
//                 lis[i] = lis[j] + 1;
//             }
//         }
//     }
//     return *max_element(lis, lis+n);
// }


// int main(){
//     int arr[] = {18, 19, 20, 4, 5, 6 , 10, 50, 60, 70, 80, 90};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout << lis(arr, n) << endl;
// }

// O(Nlog(N))
int bin(vector<int>&lis, int l, int h, int k){
    while(l+1<h){
        int m = (l+h)/2;
        if(lis[m] >= k){
            h = m;
        }else{
            l = m;
        }
    }
    return h;
}

int subset(vector<int>& arr){
    vector<int> lis(arr.size(), 0);
    int length = 1;
    lis[0] = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
        if(lis[0] > arr[i]){
            lis[0] = arr[i];
        }       
        else if(lis[length-1] < arr[i]){
            lis[length++] = arr[i];
        } 
        else{
            lis[bin(lis, -1, length-1, arr[i])]  = arr[i];
        }
    }
    for(int i = 0; i < lis.size(); i++){
        cout << lis[i] << " ";
    }
    cout << endl;
    return length;   
}

int main(){
    vector<int> arr{2, 5, 3, 7, 11, 8, 10, 13, 6 };
    cout << subset(arr) << endl;
}

