#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    queue<int> q;
    
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < k; i++){
        if(q.empty()){
            q.push(i);
        }
        else{
            if(arr[i] > arr[q.front()]){
                while(!q.empty()) q.pop();
                q.push(i);
            }
            else{
                q.push(i);
            }
        }
    }

    for(int i = k; i < n; i++){
        cout << arr[q.front()] << " ";
        
        if(i-q.front() >= k) q.pop();

        if(q.empty()){
            q.push(i);
        }
        else{
            if(arr[i] > arr[q.front()]){
                while(!q.empty()) q.pop();
                q.push(i);
            }
            else{
                q.push(i);
            }
        }
    }
    cout << arr[q.front()] << endl;
}