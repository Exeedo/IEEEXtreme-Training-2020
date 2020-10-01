// Problem link: https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/game-of-stones-1-1/
// By: Osama Khallouf

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,g,n;
    cin >> t;
    while(t--){
        int moves = 0;
        cin >> g;
        while(g--){
            cin >> n;
            for(int i=0;i<n;i++){
                int a;
                cin >> a;
                moves += (a>>1); // equivalent to a/2 [integer division]
            }
        }
        if(moves%2==0) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
    return 0;
}
