// Problem link: https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/dog-walking
// By: Osama Khallouf

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    sort(v.begin(), v.end()); // sort in ascending order
    
    vector<int> differences(n-1);
    for(int i=0; i<n-1; i++){
        differences[i]=v[i+1]-v[i]; // find the difference of each two consecutive elements
    }
    sort(differences.begin(),differences.end()); // sort in ascending order
    
    int answer=0;
    for(int i=0; i < (n-1) - (m-1); i++){
        answer+=differences[i]; // summing the differences except the largest (m-1)
    }
    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
