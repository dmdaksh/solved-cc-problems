#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    queue<string> q;
    set<string> unique;
    q.push(s);
    unique.insert(s);
    int ans = 0;
    while(!q.empty() && unique.size() < k){
        string str = q.front();
        q.pop();
        for(int i = 0; i < str.size(); i++){
            string temp = str;
            temp.erase(i, 1);
            if(!unique.count(temp) && unique.size()+1 <= k){
                unique.insert(temp);
                q.push(temp);
                ans += n - temp.size();
            }
        }
    }
    if(unique.size() < k) cout << -1 << endl;
    else cout << ans << endl;
}