// Problem link: https://csacademy.com/ieeextreme-practice/task/7df0da0b0477307be410f4772c739528/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7, N=1e6+5;
int t,a,b,c;

vector<int> primes;
bool isPrime[N];
long long freq[N];

void addFactorial(int x, int sgn){
    for(int p:primes){
        long long k=0;
        long long prime = p;
        while(x >= prime){
            k += x/prime;
            prime *= p;
        }
        freq[p] += k * sgn;
    }
}


void choose(int n,int r){ //nCr
    memset(freq, 0 , sizeof(freq));
    addFactorial(n,+1); // add n!
    addFactorial(r,-1); // sub r!
    addFactorial(n-r, -1); // sub (n-r)!
}

long long pwr(long long base, long long expo, long long m){ // (base^expo)%m
    if(expo == 0){
        return 1;
    }
    long long p = pwr(base, expo/2, m);
    p = (p*p)%m;
    if(expo%2==1){
        p = (p*base)%m;
    }
    return p;
}


int main() {
    memset(isPrime, 1, sizeof(isPrime));
    for(long long i=2;i<N;i++){
        if(!isPrime[i]){
            continue;
        }
        primes.push_back(i);
        for(long long j=i*i;j<N;j+=i){
            isPrime[j]=0;
        }
    }
    
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        choose(b,c);
        long long expo2 = 1;
        for(int p:primes){
            expo2 *= pwr(p,freq[p],M-1);
            expo2 %= M-1;
        }
        long long answer = pwr(a, expo2, M);
        cout << answer << endl;
    }
    return 0;
}
