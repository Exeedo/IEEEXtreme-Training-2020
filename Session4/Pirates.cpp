// Problem link: https://csacademy.com/ieeextreme-practice/task/pirates
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

bool grid[1005][1005];
bool vis[1005][1005];
set<int> g[1000010];
int par[1000010];
int depth[1000010];
int group[1005][1005];
int n,m,q;

int grp;

int dx[]={1,-1,0,0  ,1,1,-1,-1};
int dy[]={0,0,1,-1  ,1,-1,1,-1};

void dfsGrid(int x,int y){
    vis[x][y]=1;
    vector<pair<int,int>> nxtGroup;
    for(int i=0;i<8;i++){
        int newX=x+dx[i];
        int newY=y+dy[i];
        
        if(newX<0) continue;
        if(newY<0) continue;
        if(newX>=n) continue;
        if(newY>=m) continue;
        
        if(grid[newX][newY] == grid[x][y]){
            group[newX][newY]= group[x][y];
            if(!vis[newX][newY]){
                dfsGrid(newX,newY);
            }
        }
        else{
            if(vis[newX][newY]){
                int u=group[x][y];
                int v=group[newX][newY];
                g[u].insert(v);
                g[v].insert(u);
            }
        }
    }
}

void dfsGroups(int u){ 
    for(int v:g[u]){
        if(v==par[u]) continue;
        par[v]=u;
        depth[v]=depth[u]+1;
        dfsGroups(v);
    }
}

int dist(int u,int v){ // returns the distance
    int answer=0;
    if(depth[u]<depth[v]) swap(u,v);
    while(depth[u]!=depth[v]){
        u=par[u];
        answer++;
    }
    while(u!=v){
        u=par[u];
        v=par[v];
        answer+=2;
    }
    return answer;
}

int main() {
    cin >> n >> m >> q;
    memset(vis,0,sizeof(vis));
    memset(group,0,sizeof(group));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin >> ch;
            grid[i][j]=(ch=='~'); // true in the sea
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                group[i][j]=++grp;
                dfsGrid(i,j);
            }
        }
    }
    
    par[1]=-1;
    dfsGroups(1);

    for(int i=0;i<q;i++){
        int a,b;
        int x1,x2,y1,y2;
        
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        
        a=group[x1][y1];
        b=group[x2][y2];
        cout << dist(a, b)/2 << endl;
    }
    
    return 0;
}
