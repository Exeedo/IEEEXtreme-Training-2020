// Problem link: https://csacademy.com/ieeextreme-practice/task/lexical-addition/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

// A = [1 2 3 4]
// B = [1 2 5 1]
// (A < B) : A is lexicographically smaller than B

int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long len = (n + b - 1)/b; // equivalent to ceil(n/b);
    long long sum = len * a;
    if(sum > n){
        cout << "NO";
        return 0;
    }
    
    long long diff = b - a;
    long long sub = n - sum;
    long long numberOfBs = sub / diff;
    long long res = sub % diff;
    
    vector<long long> ans(len); // <<== definition of the vector moved here
    
    for(int i = 0; i < len; i++){
        ans[i] = a;
    }
    for(int i = 0; i < numberOfBs; i++){
        ans[i] = b;
    }
    if(numberOfBs < len) {
        ans[numberOfBs] += res;
    }
    reverse(ans.begin(),ans.end());
    
    cout << "YES" << endl;
    for(int i = 0; i < len; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
