#include <bits/stdc++.h>
using namespace std;

uint8_t EVEN = 0b10101010;
uint8_t ODD = 0b01010101;

int main(){
    int n;
    cin >> n;
    cout << ((n&EVEN) >> 1 | (n&ODD) << 1) << endl; 
}