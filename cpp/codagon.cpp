#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Bob and Subarray

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> temp(32, 0);
    unsigned long long ans = 0;
    for(int i = 0; i < n; i++){
        int x = arr[i];
        for(int j = 0; j < 32; j++){
            if(x & (1l << j)){
                ans += (1l << j) * (i+1);
                temp[j] = i+1;
            }
            else if(temp[j]){
                ans += temp[j] * (1l << j);
            }
        }
    }
    cout << ans << endl;
    
}




// XOR Queries

int solve(int x, int l, int r) {
    int tempX = 0, XY = 0;
    for(int bit = 1<<30; bit; bit >>= 1){
        int tempXY = XY | bit;
        tempX |= x & bit;
        int tempY = tempX^tempXY;
        if((tempY|(bit-1)) >= l && tempY <= r) XY = tempXY;
    }
    return XY;
}


