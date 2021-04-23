// k + largest -> min heap (max ele stays on top)
// k + smallest -> max heap (min ele stays in top)

// Heap converts complexity of best sorting nlogn to nlogk

// Identification -> k and max/min

// max heap -> priority_queue<int> maxh;
// min heap -> priority_queue<int, vector<int>, greater<int>> minh;

// #type def pair<int, int> T


// CUSTOM COMPARATOR OF MAP ---------------------------------------------------------------

typedef pair<string, int> p;
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(auto it : words) m[it]++;

        // A structure is essentailly used as a comparator.

        // decltype Keyword
        // It inspects the declared type of an entity or the type of an expression. 
        // Auto lets you declare a variable with particular type whereas ...
        // decltype lets you extract the type from the variable so decltype is sort of an operator that evaluates the type of passed expression. 

        auto comp = [&](const pair<string, int> &p1, const pair<string, int> &p2){
            return p1.second==p2.second?p1.first<p2.first:p1.second>p2.second;   
        };
        priority_queue<p, vector<p>, decltype(comp)> pq(comp);
        for(auto it : m){
            pq.push({it.first, it.second});
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.insert(ans.begin(), pq.top().first);
            pq.pop();
        }
        return ans;
    }

// -----------------------------------------------------------------------------------------------


// Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. 
// For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

// Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50} k = 4
// Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}


#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums{10, 9, 8, 7, 4, 70, 60, 50};
    int k = 4;

    // A Min heap is used as ascending order is needed and the minimum element is always stored in the top.
    // So every time you pop the minimum ele and store it, till the last k elements are left and they are the most value elements.

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