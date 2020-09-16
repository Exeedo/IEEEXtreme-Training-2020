// Problem link: https://csacademy.com/ieeextreme-practice/task/bit-soccer/
// By: Osama Khallouf

#include <bits/stdc++.h> // This simply includes all the libraries that you need. Be careful: it does not work in Visual Studio!
using namespace std;

int n,q;
long long p,g; // long long is 64-bit integer
vector<long long> v;

int main(){
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cin >> q;
    while(q--){
        cin >> p;
        vector<long long> w;
        for(int i=0; i<n; i++){
            if((p|v[i])==p){      // checking bitwise-or between each element and the needed answer (for the first stage of exclusion)
                w.push_back(v[i]); 
            }
        }
        bool ans=0;
        g=0;
        for(int i=0;i<w.size();i++){
            g|=w[i];    // finding the bitwise-or of all the picked numbers
        }
        if(g==p){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}
