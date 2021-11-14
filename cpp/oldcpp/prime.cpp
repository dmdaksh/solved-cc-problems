#include <bits/stdc++.h>
using namespace std;

//O(NlogN) for printing prime upto N
// vector<bool> prime;
// void find_prime(){
//     for(int i = 2; i < prime.size(); i++){
//         if(prime[i] == true){
//             for(int j = i*2; j < prime.size(); j*=2){
//                 prime[j] = false;
//             }
//         }
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     prime.assign(n, true);
//     find_prime();
//     for (size_t i = 2; i < prime.size(); i++){
//         if(prime[i] == true){
//             cout << i << " ";
//         }
//     }
//     cout << endl;
// }

// O(N) for finding a number is prime or not
// int main(){
//     int n;
//     cin >> n;
//     for (size_t i = 2; i*i <= n; i++){
//         if(!(n%i)){
//             cout << "Composite Number" << endl;
//             return 0;
//         }
//     }
//     cout << "Prime Number" << endl;
//     return 0;    
// }