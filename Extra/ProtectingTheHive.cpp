// Problem link: https://csacademy.com/ieeextreme-practice/task/protecting-the-hive/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

// Direction arrays
int dx[]={-1,-1,+0,+0,+1,+1};
int dy[]={+0,+1,-1,+1,+0,+1};

bool active[101][101],
        vis[101][101];

int n,m,q,a,r,c;
char ch;

int dfs(int x,int y){
    /* Check the external boundary of the whole grid
     * and returning 1 as those edges are counted in 
     * the perimeter
     */
    if((x<=0)||(y<=0))
        return 1;
    if((x> n)||(y> m))
        return 1;
    if(((x&1)==0)&&(y==m))
        return 1;
    
    int answer=0;
    vis[x][y]=1;
    
    for(int i=0;i<6;i++){
        int newX=x+dx[i];
        int newY=y+dy[i];
        
        if((x&1)&&dx[i]!=0) { // odd rows differ from even rows
            newY--;
        }
        
        if(vis[newX][newY]) {
            continue;
        }
        
        if(!active[newX][newY]) {
            answer++; // count all edges between an active cell and inactive cell
        }
        else {
            answer += dfs(newX,newY);
        }
    }
    return answer;
}

int main() {
    scanf("%d%d",&n,&m); // similar to (but faster than) cin >> n >> m
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=m-(i&1);j++){
            scanf("%d",&a);
            active[i+1][j]=(a==1);
        }
    }
    
    scanf("%d",&q);
    while(q--){
        scanf(" %c%d%d",&ch,&r,&c);
        if(ch=='a'){
            active[r][c]=1;
        }
        
        else{
            if(!active[r][c]){
                printf("0\n");
                continue;
            }
            
            memset(vis,0,sizeof vis); // un-visit all cells
            printf("%d\n",dfs(r,c));
        }
    }
    return 0;
}
