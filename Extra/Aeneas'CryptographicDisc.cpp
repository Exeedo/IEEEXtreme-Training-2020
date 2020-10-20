// Problem link: https://csacademy.com/ieeextreme-practice/task/d48ada9a7213299f1b24b22b2fb9443f
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

double angle[26];

int cal(int r, vector<int> &letters) {
    double PI = acos(-1); // cos(PI) = -1, [PI in radian]
    double answer = r;
    for(int i = 1; i < letters.size(); i++) {
        double total_angle = abs(angle[letters[i]] - angle[letters[i-1]]);
        answer += r * sqrt(2 - 2 * cos(total_angle * PI/180)); // convert the total_angle to radian
    }
    return ceil(answer);
}

int main() {
    int r;
    cin >> r;
    for(int i = 0; i < 26; i++){
        char c;
        double a;
        cin >> c >> a;
        c &= (~32); // convert to upper case character
        angle[c - 'A'] = a;
    }
    
    vector<int> letters;
    string s;
    getline(cin,s); // read the empty line after the last number
    
    getline(cin,s); // read the message
    
    for(int i = 0; i < s.length(); i++) {
        s[i] &= (~32); // convert to upper case character
        if(s[i] >= 'A' && s[i]<='Z') {  // if it is a letter:
            letters.push_back(s[i]-'A');
        }
        // otherwise, skip the character
    }
    cout << cal(r,letters) << endl;
    return 0;
}
