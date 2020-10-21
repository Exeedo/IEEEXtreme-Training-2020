// Problem link: https://csacademy.com/ieeextreme-practice/task/googolplex/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

long long pwr(long long x, long long q, long long m){
    if(q == 0)
        return 1;
    long long p = pwr(x, q/2, m);
    p = (p*p) % m;
    if(q%2 == 1)
        p = (p*x) %m;
    return p;
}

int main() {
    int n;
    cin >> n;
    while(n--){
        long long X, Y, mod;
        cin >> X >> Y;
        mod = pwr(10, Y, 1e18); // calculate 10^Y
        X %= mod;
        long long K = pwr(X, 1e10, mod); // calculate X^[4*10^(Y-1) or any multiple of it]
        long long answer = K;
        
        for(int t = 1; t < 86400;t++){
            K = (K * X) % mod;
            answer = min(answer, K);
        }
        cout << answer << endl;
    }
    return 0;
}
