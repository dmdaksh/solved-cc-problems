#include<bits/stdc++.h>
using namespace std;

int *lps;

void KMP(string str, string pat){
    int n = str.size();
    int m = pat.size();
    int i = 0, j = 0, f = 0;
    while(i < n){
        if(str[i] == pat[j]) i++, j++;
        if(j == m){
            f = 1;
            cout << "Found at: " << i-j << endl;;
            j = lps[j-1];
        }
        else if(i < n && str[i] != pat[j]){
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    if(!f) cout << "No match found" << endl;
}

void initLPS(string pat){
    memset(lps, 0, sizeof(lps));
    int l = 0;
    int i = 1;
    while(i < pat.size()){
        if(pat[i] == pat[l]){
            lps[i++] = ++l;
        }else{
            if(l != 0){
                l = lps[l-1];
            }
            else{
                lps[i++] = 0;
            }
        }
    }
}

int main(){
    string str = "abxabcabcaby";
    string pat = "abcaby";
    lps = new int[pat.size()];
    initLPS(pat);
    KMP(str, pat);
}
