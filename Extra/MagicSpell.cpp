// Problem link: https://csacademy.com/ieeextreme-practice/task/magic-spell/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

string letters = "qwertyuiopasdfghjklzxcvbnm";
map<string,int> num;

void fillMap() {
    num["zero"]     =  0;
    num["one"]      =  1;
    num["two"]      =  2;
    num["three"]    =  3;
    num["four"]     =  4;
    num["five"]     =  5;
    num["six"]      =  6;
    num["seven"]    =  7;
    num["eight"]    =  8;
    num["nine"]     =  9;
    num["ten"]      = 10;
    num["eleven"]   = 11;
    num["twelve"]   = 12;
    num["thirteen"] = 13;
    num["fourteen"] = 14;
    num["fifteen"]  = 15;
}

long long calculate(string s) {
    string number = "";
    long long answer = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            answer += num[number];
            answer *= 16;
            number = "";
            continue;
        }
        
        for(int j = 1; j < letters.length(); j++) {
            if(letters[j] == s[i]) {
                number = number + letters[j-1];
                break;
            }
        }
    }
    answer += num[number];
    return answer;
}

int main() {
    fillMap();
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    
    long long ans = 1;
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        ans *= calculate(s);
    }
    cout << ans;
    return 0;
}
