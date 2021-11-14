#include<bits/stdc++.h>
using namespace std;


int main(){
    long long divisor, dividend;
    cin >> dividend >> divisor;
    long long quotient = 0, temp = 0;
    int sign = ((divisor<0) ^ (dividend<0)) ? -1: 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    for(int i = 31; i >= 0; i--){
        if(temp + (divisor << i) <= dividend){
            temp +=  divisor << i;
            quotient |= 1LL << i;   
        }
    }
    cout << sign * quotient << endl;
}