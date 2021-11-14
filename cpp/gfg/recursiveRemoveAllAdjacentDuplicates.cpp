#include <bits/stdc++.h>
using namespace std;

char* solve(char *s, int n){
    int k = 0, i;
    for(i = 1; i < n; i++){
        if(s[i-1] != s[i]) s[k++] = s[i-1];
        else while(s[i-1] == s[i]) i++;
    }
    
    s[k++] = s[i-1];
    s[k] = '\0';
    
    if(k != n) solve(s, k);
    else return s;
}

int main() {
	int t;
    cin >> t;
	while(t--){
	    char s[50];
	    cin >> s;
        cout << solve(s, strlen(s)) << endl;
	}
}