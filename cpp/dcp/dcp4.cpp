#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{-5};
    int l = arr.size();
    make_heap(arr.begin(), arr.end(), greater<int>());
    int top = arr.front();
    auto itr = arr.end();
    while(top <= 0 && itr<arr.begin()){
        pop_heap(arr.begin(), itr, greater<int>());
        top = arr.front();   
        itr--; 
    }
    
    top = 0;
    while(top+1 == arr.front() && itr<=arr.begin()){
        top = arr.front();
        pop_heap(arr.begin(), itr, greater<int>());
        itr--;   
    }
    if(itr == arr.begin()){
        cout << arr.front()+1 << endl;
    }
    else{
        cout << top+1 << endl;
    }
}