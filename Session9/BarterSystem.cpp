// Problem link: https://csacademy.com/ieeextreme-practice/task/barter-system/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int N = 2e4+5, M = 998244353;
vector<pair<long long, int>> g[N];
map<string,int> idx;
bool vis[N];

int root[N];
long long fromRoot[N];

long long pwr(long long x, long long y){
    if(y == 0) 
        return 1;
    long long p = pwr(x, y / 2);
    p = (p * p) % M;
    if(y % 2 == 1)
        p = (p * x) % M;
    return p;
}

long long inv(long long x){
    return pwr(x, M - 2);
}

void dfs(int u){
    vis[u] = 1;
    for(auto x : g[u]){
        long long w = x.first;
        int v = x.second;
        if(vis[v]) 
            continue;
        
        root[v] = root[u];
        fromRoot[v] = (fromRoot[u] * inv(w)) % M;
        dfs(v);
    }
}

int main() {
    int m;
    cin >> m;
    int n = 0;
    
    while(m--){
        int a, b;
        string s1, s2;
        long long r;
        cin >> s1 >> s2 >> r;
        
        if(!idx[s1])
            idx[s1] = ++n;
        if(!idx[s2])
            idx[s2] = ++n;
        
        a = idx[s1];
        b = idx[s2];
        g[a].push_back( {  r  ,  b} );
        g[b].push_back( {inv(r), a} );
    }
    
    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            root[i] = i;
            fromRoot[i] = 1;
            dfs(i);
        }
    
    int q;
    cin >> q;
    while(q--){
        int a, b;
        string s1, s2;
        cin >> s1 >> s2;
        a = idx[s1];
        b = idx[s2];
        
        if(root[a] != root[b]){
            cout << -1 << endl;
            continue;
        }
        
        long long ans = (fromRoot[a] * inv(fromRoot[b])) % M;
        cout << ans << endl;
    }
    return 0;
}
