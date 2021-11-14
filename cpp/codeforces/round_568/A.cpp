#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    vector<int> temp;
    cin >> a >> b >> c >> d;
    temp.push_back(a), temp.push_back(b), temp.push_back(c);
    sort(temp.begin(), temp.end());
    a = temp[0], b = temp[1], c = temp[2];
    cout << a << b << c << d << endl;
    int count = 0;
    while(c-b < d || b-a < d){
        if(b-a >= d){
            if(c-b < d){
                c++;
                count++;
            }
        }
        else if(b-a < d){
            if(c-b >= d){
                if(a <= 1){
                    b++;
                    count++;
                }
                else if(a > 1){
                    a--;
                    count++;
                }
            }
            else if(c-b < d){
                if(a <= 1){
                    c++;
                    count++;
                }
                else if(a > 1){
                    c++;
                    count++;
                    a--;
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}