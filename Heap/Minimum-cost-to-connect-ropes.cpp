// Given n ropes of different lengths, we need to connect these ropes into one rope. 
// We can connect only 2 ropes at a time. The cost required to connect 2 ropes is equal to sum of their lengths. 
// The length of this connected rope is also equal to the sum of their lengths. 
// This process is repeated until n ropes are connected into a single rope. Find the min possible cost required to connect all ropes.

// Input: ropes = [8, 4, 6, 12]
// Output: 58
// Explanation: The optimal way to connect ropes is as follows
// 1. Connect the ropes of length 4 and 6 (cost is 10). Ropes after connecting: [8, 10, 12]
// 2. Connect the ropes of length 8 and 10 (cost is 18). Ropes after connecting: [18, 12]
// 3. Connect the ropes of length 18 and 12 (cost is 30).
// Total cost to connect the ropes is 10 + 18 + 30 = 58

// Always choose the lowest 2 ropes
// Keep on adding their sum to the min heap 
// Keep on adding to the total answer


#include <bits/stdc++.h>
using namespace std;
int main(){

    vector<int> ropes{8, 4, 6, 12};
    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto it : ropes) pq.push(it);

    int ans = 0;
    while(pq.size()>=2){
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        ans+=f+s;
        pq.push(f+s);
    }

    cout<<ans;
    
    return 0;
}