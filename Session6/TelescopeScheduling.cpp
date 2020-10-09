// Problem link: https://csacademy.com/ieeextreme-practice/task/telescope-scheduling/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;


int n,s,f,d;
int dp[10005][1005];

// structure to hold the stars' information
struct star {
    int start;
    int finish;
    int score;
};

vector<star> stars;

bool sortStar(star &a, star &b){
    // sort by starting time (asc.), then by finishing time (asc.), then by score (desc.)
    if(a.start!=b.start) {
        return (a.start < b.start);
    }
    if(a.finish!=b.finish) {
        return (a.finish < b.finish);
    }
    return (a.score > b.score);
}

// In this function: we keep track of the index and the last finishing time (to avoid conflicts)
int cal(int idx, int lastTime) {
    if(idx > n) {
        return 0;
    }
    
    if(dp[idx][lastTime] != -1) {
        return dp[idx][lastTime];
    }
    
    // try not to watch this star:
    dp[idx][lastTime] = cal(idx + 1, lastTime);
    // try to watch this star: (only if it does not conflict with other stars)
    if(stars[idx].start > lastTime) {
        dp[idx][lastTime] = max(dp[idx][lastTime],
                                cal(idx, stars[idx].finish) + stars[idx].score);
    }
    
    return dp[idx][lastTime];
}

int main() {
    cin >> n;
    stars.resize(n);
    
    for(int i=0; i<n; i++){
        cin >> s >> f >> d;
        
        // to start from 1 instead of 0:
        s++;
        f++;
        
        stars[i].start  = s;
        stars[i].finish = f;
        stars[i].score  = d;
    }
    
    memset(dp, -1, sizeof(dp));
    
    // It is important to sort the stars according to their times and scores
    sort(stars.begin(), stars.end(), sortStar);
    
    cout << cal(0, 0) << endl;
    return 0;
}
