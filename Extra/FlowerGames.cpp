// Problem link: https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/flower-games/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

unsigned long long calculate(unsigned long long x){
    unsigned long long lo = 0, hi = 64, mid, p = 0;
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        if((1ull << mid) <= x) {
            p = 1ull << mid; // 2 ^ mid
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    x -= p;
    x *= 2;
    return x+1;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        unsigned long long n;
        cin >> n;
        cout << calculate(n) << endl;
    }
    return 0;
}
