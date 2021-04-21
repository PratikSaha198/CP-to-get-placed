// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 

// Use max heap with first element as the absolulte difference and second as the number itself
// All the numbers greater than k elements are to be popped
// The remaining k elements are the answer


vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    vector<int> ans;
    priority_queue<pair<int, int>> pq;

    for(auto it : arr)
    {
        pq.push({abs(it-x), it});

        if(pq.size()>k) 
            pq.pop();
    }

    while(!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}