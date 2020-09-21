// Problem link: https://csacademy.com/ieeextreme-practice/task/xtreme-rappers/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

long long j,k;

int main() {
    cin >> j >> k;
    cout << min(min(j,k),(j+k)/3) << endl;
    return 0;
}
