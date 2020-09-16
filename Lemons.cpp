// Problem link: https://csacademy.com/ieeextreme-practice/task/lemons/

#include <bits/stdc++.h> // This simply includes all the libraries that you need. Be careful: it does not work in Visual Studio!
using namespace std;

int n , m , s;

int LOG2(int x){
    int ans=0;
    while( x != 0 ){
        ans++;
        x = x/2;
    }
    return ans;
}

int main() {
    cin >> n >> m >> s;
    cout << s*LOG2(n-1) // Total checking time
            + m*(n-1); // Total travelling time
    return 0;
}
