// Problem link: https://csacademy.com/ieeextreme-practice/task/factorial-zeros/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bool isPrime[101];

long long calculateZeros(long long x, vector<pair<int,int>> &factors){
    long long answer = 1e18;
    
    for(int i=0;i<factors.size();i++){
        long long prime=factors[i].first;
        int power=factors[i].second;
        long long k=0;
        while(x>=prime){
            k += x/prime;
            prime *= factors[i].first;
        }
        answer = min(answer,k/power);
    }
    
    return answer;
}


int main() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i=2;i<100;i++){
        if(!isPrime[i]){
            continue;
        }
        primes.push_back(i);
        for(int j=i*i;j<100;j+=i){
            isPrime[i]=0;
        }
    }
    
    int t;
    cin >> t;
    while(t--){
        int b;
        long long n;
        cin >> b >> n;
        vector<pair<int,int>> factors;
        for(int p:primes){
            int k=0;
            while(b%p==0){
                k++;
                b/=p;
            }
            if(k>0){
                factors.push_back({p,k});
            }
        }
        
        long long lo=1, hi=1e18, md, answer = -1;
        // [lo,md,hi] => [md+1,hi] if less
        // [lo,md,hi] => [lo,md-1] if greater
        while(lo<=hi){
            md = (hi+lo)/2;
            long long x=calculateZeros(md,factors);
            if(x<n){
                lo=md+1;
            }
            else if(x>n){
                hi = md-1;
            }
            else{
                answer = md;
                hi=md-1;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
