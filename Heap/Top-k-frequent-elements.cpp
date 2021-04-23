// Given an integer array nums and an integer k, return the k most frequent elements.
// You may return the answer in any order.

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// NORMAL MIN HEAP IMPLEMENTATION


typedef pair<int, int> p;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    map<int, int> m;

    for(auto it : nums)
        m[it]++;
    
    // A min heap is needed as the minimum frequency element is at the top and its constantly being deleted.
    // At the end the k most frequency ones remain.

    priority_queue<p, vector<p>, greater<p>> pq;
    
    for(auto it : m)
    {
        pq.push({it.second, it.first});
    
        if(pq.size()>k) 
            pq.pop();
    }
    
    vector<int> ans;
    
    while(!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    
    return ans;
}