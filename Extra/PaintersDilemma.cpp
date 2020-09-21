// Problem link: https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/painters-dilemma
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

int arr[555];

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v[21];
        for(int i=0;i<n;i++){
            cin >> arr[i];
            v[arr[i]].push_back(i);
        }
        for(int i=0;i<21;i++)
            v[i].push_back(n);
        
        int brush1=0, brush2=0, c=0;
        for(int i=0;i<n;i++){
            if(arr[i]==brush1 || arr[i]==brush2) continue;
            int y1= *upper_bound(v[brush1].begin(),v[brush1].end(),i);
            int y2= *upper_bound(v[brush2].begin(),v[brush2].end(),i);
            if(y1>y2){
                brush1=arr[i];
                c++;
            }else{
                brush2=arr[i];
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}
