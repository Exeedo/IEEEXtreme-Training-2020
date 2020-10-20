// Problem link: https://csacademy.com/ieeextreme-practice/task/concentration-game/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long c, h, o, d, w, g; // carbon, hydrogen, oxygen, dioxide, water, glucose
    cin >> c >> h >> o;
    if((h - 2 * o + 4 * c) % 24 != 0) { // Check non-integer solutions
        cout << "Error";
        return 0;
    }
    
    // This solution was found by hand and hard-coded:
    g = (h - 2 * o + 4 * c) / 24;
    d = c - 6*g;
    w = o - 2*d - 6*g;
    
    cout<< w << ' '<< d << ' ' << g;
    return 0;
}
