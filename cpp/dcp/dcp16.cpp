#include <bits/stdc++.h>
using namespace std;

int ind = 0;
vector<int> a;

void record(int num){
    if(ind == a.size()) ind = 0;
    a[ind++] = num;
}

int get_last(int i){
    int temp = (ind-i+a.size())%a.size();
    return a[temp];
}

int main(){
    int n = 10;
    a.resize(n);
    
    record(0);
    record(1);
    record(2);
    record(3);
    record(4);
    record(5);
    record(6);
    record(7);
    
    cout << get_last(1) << endl;
    
    record(8);
    record(9);
    record(10);
    
    cout << get_last(3) << endl;
    
    record(11);
    record(14);
    record(15);
    
    cout << get_last(2) << endl;
    
    record(16);
    record(17);
    record(18);
    record(19);
    
    cout << get_last(9) << endl;
}
