#include<bits/stdc++.h>
using namespace std;

unordered_map<char, string> m;

bool matchPatterns(string str, int i, string pat, int j){
    if(i == str.size() && j == pat.size()) return true;
    if(i == str.size() || j == pat.size()) return false;

    char c = pat[j];
    if(m.find(c) != m.end()){
        string s = m[c];
        int l = s.size();
        string substring = str.substr(i, l);
        if(substring.compare(s)) return false;
        return matchPatterns(str, i+l, pat, j+1);
    }

    int n = str.size();
    for(int l = 1; l < n-i; l++){
        m[c] = str.substr(i, l);
        if(matchPatterns(str, i+l, pat, j+1)) return true;
        m.erase(c);
    }
    return false;
}


int main(){
    string str = "Hello World Hello";
    string pat = "aba";
    if(matchPatterns(str, 0, pat, 0)){
        for(auto it:m){
            cout << it.first << " -> " << it.second << endl;
        }
    }
    else cout << "No Solutions Exist" << endl;
}
