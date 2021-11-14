#include <bits/stdc++.h>
using namespace std;
#define INTERVAL 1000

unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}

int main(){
    int n;
    unsigned long long r;
    vector<int> res(INTERVAL, -1);
    int i = 0;
    while(cin >> n){
        if(i < INTERVAL){
            res[i] = n;
        }
        else{
            r = llrand() % i;
            if(r < INTERVAL){
                res[r] = n;
            }
        }
        i++;
    }
}