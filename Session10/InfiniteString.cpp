// Problem link: https://csacademy.com/ieeextreme-practice/task/infinite-string/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, b;
    unsigned long long x;
    cin >> t;
    while(t--){
        cin >> b >> x;
        if(b==1) { 
            // special case, will cause TLE verdict if not handled separately
            cout << 'a' << endl;
            continue;
        }
        
        // without "unsigned", calculations will cause overflowing 
        unsigned long long words = b;
        unsigned long long wordLength = 1;
        unsigned long long letters = words * wordLength;
        
        while(x >= letters) {
            x -= letters;
            wordLength++;
            words *= b;
            letters = words * wordLength;
        }
        
        unsigned long long i = x / wordLength; // i-th word
        unsigned long long j = x % wordLength; // j-th letter in the i-th word
        for(unsigned long long k = 1; k < wordLength - j; k++) {
            i /= b;
        }
        char ch = 'a' + (i%b);
        cout << ch << endl;
    }
    return 0;
}
