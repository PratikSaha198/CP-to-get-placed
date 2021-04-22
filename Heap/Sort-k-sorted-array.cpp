// k + largest -> min heap (max ele stays on top)
// k + smallest -> max heap (min ele stays in top)

// Heap converts complexity of best sorting nlogn to nlogk

// Identification -> k and max/min

// max heap -> priority_queue<int> maxh;
// min heap -> priority_queue<int, vector<int>, greater<int>> minh;

// #type def pair<int, int> T


// --------------------------------------------------------------------------------------------------------------------


// Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. 
// For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

// Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50} k = 4
// Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}


#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums{10, 9, 8, 7, 4, 70, 60, 50};
    int k = 4;

    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> ans;

    for(auto it : nums){
        pq.push(it);
        if(pq.size()>k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    for(auto it : ans) cout<<it<<" ";

    return 0;
}