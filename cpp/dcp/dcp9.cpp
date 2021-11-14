#include <bits/stdc++.h>
using namespace std;

int largest_sum(vector<int> &arr){
    int mx = max(arr[0], arr[1]);;
    if(arr.size() == 2){
        return mx;
    }
    arr[2] += arr[0];
    for(int i = 3; i < arr.size(); i++){
        arr[i] += mx;
        mx = max(mx, arr[i-1]);
    }
    for(auto i:arr){
        cout << i << " ";
    }   
    cout << endl;
    return max(arr[arr.size()-1], arr[arr.size()-2]);
}

int main(){
    vector<int> arr{2,4,6,2,5};
    cout << largest_sum(arr) << endl;
}