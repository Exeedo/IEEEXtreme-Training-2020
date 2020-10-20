// Problem link: https://csacademy.com/ieeextreme-practice/task/minimum-permutation/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    
    vector<int> A(n), S(m);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> S[i];
    }
    
    sort(S.begin(), S.end());
    
    int idx = 0;
    for(int i = 0; i < n; i++) {
        while((S[idx] < A[i]) && (idx < m)) {
            cout << S[idx] << ' ';
            idx++;
        }
        cout << A[i] << ' ';
    }
    while (idx < m){
        cout << S[idx] << ' ';
        idx++;
    }
    return 0;
}
