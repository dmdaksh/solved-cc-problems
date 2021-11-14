#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    stack<string> st;
    int len = 0, maxLen = 0, level = 0, tempLevel = 0;
    while(str.size() != 0){
        int ind = str.find_first_of('\\');

        len += ind;
        if(!st.empty()) len++;
        
        if(maxLen < len){
            maxLen = len;
        }
        
        st.push(str.substr(0, ind));
        
        str = str.substr(ind+2);
        
        tempLevel = 0;
        while(str[0] == '\\' && str[1] == 't'){
            tempLevel++;
            str = str.substr(2);
        }
        if(level == tempLevel){
            st.pop();
        }
        else if(level > tempLevel){
            for(int i = 0; i <= level-tempLevel; i++){
                len -= st.top().size();
                st.pop();
                if(!st.empty()) len--;
            }
            level = tempLevel;
        }
        else{
            level = tempLevel;
        }
    }
    cout << maxLen << endl;
}