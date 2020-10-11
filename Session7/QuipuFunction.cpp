// Problem link: https://csacademy.com/ieeextreme-practice/task/concentration-game/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
bool isPrime[N];
vector<int> primes;

int main() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1]=0;
    for(long long i = 2; i < N; i++){ // i=2 => 2,4,6,8,... // i=7 => 49,56,...
        if(!isPrime[i]){
            continue;
        }
        primes.push_back(i);
        for(long long j = i*i; j < N; j += i){ // N * summation of 1/p = O(N * log(log(N)))
            isPrime[j] = 0;
        }
    }
    
    int t;
    long long a,b,d;
    cin >> t >> a >> b;
    long long range = b - a + 1;
    
    vector<long long> values(range), factors(range, 1); // initialize the number of factors by 1
    for(int i = 0; i < range; i++){
        values[i] = a + i;
    }
    
    // cout << primes.size() << endl; // approximately 78,500 primes below 1,000,000
    
    for(int p : primes){
        /* This will result in Time Limit Exceeded Verdict:
        for(int i=0;i<range; i++){
            int k=0;
            while(values[i] % p == 0){ // 48 => 3 => 1
                values[i] /= p;
                k++;
            }
            // 48 = 2^4 * ...
            factors[i] *= k+1;
        }
        */
        
        // This is a better option
        long long starting = a - (a % p);
        if(starting < a){
            starting += p;
        }
        for(long long i = starting; i <= b; i += p) {
            int k=0;
            while(values[i - a] % p == 0){ // 48 => 3 => 1
                values[i - a] /= p;
                k++;
            }
            // 48 = 2^4 * ...
            factors[i - a] *= k+1;
        }
        
    }
    
    for(int i = 0; i < range; i++){
        if(values[i] != 1){ // values[i] = p^1
            factors[i] *= 2;
        }
        values[i] = a + i; // original value
    }
    
    while(t--){
        cin >> d;
        long long sum = 0;
        for(int i = 0; i < range; i++){
            int k =0 ;
            while(values[i] % d == 0){
                values[i] /= d;
                k++;
            }
            sum += factors[i] / (k+1);
            values[i] = a + i; // original value
        }
        cout << sum << endl;
    }
    
    
    return 0;
}
