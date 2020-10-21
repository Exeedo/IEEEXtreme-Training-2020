// Problem link: https://csacademy.com/ieeextreme-practice/task/tweedledees-split-brackets/
// By: Osama Khallouf

// THIS IS NOT A FULL ANSWER. IT WILL SCORE 97.14/100.
// PLEASE LET ME KNOW IF YOU HAPPEN TO KNOW HOW TO FULLY ANSWER IT.

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<char, int> mp;

void print(long long x) {
    for(int i = 2*n - 1; i >= 0; i--) {
        cout << (x & (1ll << i) ? 2 : 1) << ' ';
    }
    exit(0);
}

void cal(int s1, int s2, long long last_s1, long long last_s2, long long seq){
    if(s1 > n)
        return;
    if(s2 > n)
        return;
    
    int idx = s1 + s2;
    if(idx == n*2){
        if(last_s1 == 0 && last_s2 == 0)
            print(seq);
        else
            return;
    }
    
    if(mp[s[idx]] & 4) { // a closing bracket
        if(s1 > 0 && (last_s1 & 3) == (mp[s[idx]] & 3) ){
            // Trying in s1:
            cal(s1 + 1, s2, last_s1 >> 2, last_s2, seq << 1);
        }
        if(s2 > 0 && (last_s2 & 3) == (mp[s[idx]] & 3) ){
            // Trying in s2:
            cal(s1, s2 + 1, last_s1, last_s2 >> 2, (seq << 1) | 1);
        }
    }
    
    else { // an opening bracket
        // Trying in s1 :
        cal(s1 + 1, s2, (last_s1 << 2) | mp[s[idx]], last_s2, seq << 1);
        if (idx != 0) {
            // Trying in s2 :
            cal(s1, s2 + 1, last_s1, (last_s2 << 2) | mp[s[idx]], (seq << 1) | 1);
        }
    }
}

int main() {
    cin >> s;
    
    n = s.length();
    if(n%2 == 1){
        cout << "impossible";
        return 0;
    }
    
    n /= 2; // length of S1, S2
    if(n%2 == 1) {
        cout << "impossible";
        return 0;
    }
    
    mp['('] = 1; // 001
    mp['['] = 2; // 010
    mp[')'] = 5; // 101
    mp[']'] = 6; // 110
    
    cal(0, 0, 0, 0, 0);
    
    cout << "impossible";
    return 0;
}
