#include<bits/stdc++.h>
using namespace std;

// Have an minus storing queue
// If the window is less than k then increase j
// Else if the minus array si empty then the window doesnt have any negative numbers 
// Else push the 1st element 
// Next step while moving the window
// The last element has to be removed and the next one of j to be added, thus check if the front of the minus queue is same as the arr[i] ele, thus remove that

vector<int> solve(vector<int> arr, int k){
    vector<int> ans;
    queue<int> minus;
    int i=0, j=0;
    while(j<arr.size()){
        if(arr[j]<0) minus.push(arr[j]);
        if((j-i+1)<k) j++;
        else if((j-i+1)==k){
            if(minus.empty()) ans.push_back(0);
            else ans.push_back(minus.front());
            if(minus.front()==arr[i]) minus.pop();
            i++;
            j++;
        }
    }
    return ans;
}

// TC : O(n
// SC : O(k)

int main(){

    // Given an array, find the first negative integer for every window of size k

    // Input  : arr[] = {12, -1, -7, 8, -15, 30, 16, 28}, k = 3
    // Output : {-1, -1, -7, -15, -15, 0}

    vector<int> arr{12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> ans;
    ans = solve(arr, k);
    
    for(auto it : ans) cout<<it<<" ";

    return 0;
}