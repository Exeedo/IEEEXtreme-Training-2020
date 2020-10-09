// Problem link: https://csacademy.com/ieeextreme-practice/task/72a7d67e7e18f4f7d033f7f5a5a09bef/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

int books;
int allTopicsMask;
int dp[2][1<<21];

map<string, int> topicIndex;
vector<int> bitmasks, times;

int main() {
    // Reading the input and saving a bitmask for each book:
    int t;
    while(cin >> t) { // read all the times
        bitmasks.push_back(0);
        times.push_back(t);
        
        string str, topicName;
        getline(cin, str); // read the whole line after the time
        // int len = str.length();
        
        auto startPoint = str.find(" ") + 1; // find the first space (it will be right after the time)
        auto endPoint   = str.find(" ", startPoint); // find the next space (after the topic name)
        
        while(endPoint!=string::npos){
            topicName = str.substr(startPoint, endPoint - startPoint);
            
            if(!topicIndex[topicName]) { // give the topic a new index if it is not found in the map
                topicIndex[topicName] = topicIndex.size();
            }
            
            // fill the bitmask of the current book with this topic
            bitmasks.back() |= (1 << (topicIndex[topicName] - 1));
            
            // find the next topic
            startPoint  = endPoint + 1;
            endPoint    = str.find(" ", startPoint);
        }
        
        // handle the last topic similarly: 
        topicName = str.substr(startPoint);
        
        if(!topicIndex[topicName]) {
            topicIndex[topicName] = topicIndex.size();
        }
        
        bitmasks.back() |= (1 << (topicIndex[topicName] - 1));
        
        // Increase the number of books after finishing reading all of its topics
        books++;
    }
    
    // Initializing the [reduced] dynamic programming array:
    for(int j = 0; j < (1<<21); j++) {
        dp[0][j]=1e9;
        dp[1][j]=1e9;
    }
    dp[0][0]=0; //starting point
    
    // bitmask for all the topics: (it will also be the largest bitmask)
    int allTopicsBitmask = (1 << topicIndex.size()) - 1;
    
    // Trying all books:
    bool idx = 0;
    for(int book = 0; book < books; book++) {
        // to alternate the first index in the reduced array for each book
        idx = !idx;
        
        // Try not to take this book (same time as the previous book for all the bitmasks)
        for(int mask = 0; mask <= allTopicsBitmask; mask++) {
            dp[idx][mask] = dp[!idx][mask];
        }
        
        // try to take this book and add its total time to the previous book for all bitmasks
        for(int mask = 0; mask <= allTopicsBitmask; mask++){
            int newMask = mask | bitmasks[book];
            dp[idx][newMask] = min(dp[idx][newMask],
                                    dp[!idx][mask] + times[book]);
        }
    }
    
    // Printing the answer: (last index, bitmask for all the topic)
    cout << dp[idx][allTopicsBitmask] << endl;
    return 0;
}
