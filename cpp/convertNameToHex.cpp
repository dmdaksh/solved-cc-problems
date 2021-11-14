#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, string> um;

string toHex(int c){
    string ans = " ";
    for(int i = 0; i < 2; i++){
        ans = um[c&15] + ans;
        c >>= 4;
    }
    return ans;
}

string convert2Hex(string s){
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        ans += toHex(s[i]);
    }
    return ans;
}

int main(){
    string name = "daksh";
    for(int i = 0; i < 10; i++) um[i] = to_string(i);
    um[10] = "a";
    um[11] = "b";
    um[12] = "c";
    um[13] = "d";
    um[14] = "e";
    um[15] = "f";
    cout << convert2Hex(name) << endl;
}
