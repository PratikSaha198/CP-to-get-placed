// Given an array of integers nums and an integer limit.
// Return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

// Input: nums = [8,2,4,7], limit = 4
// Output: 2

// A mutiset is sorted stuff thing, choose the last and first elements and do the following
// TC : O(nlongn)
// SC : O(n)

int longestSubarray(vector<int>& nums, int limit) {
    int ans = INT_MIN;
    int i=0, j=0;
    int k=limit;
    multiset<int> m;
    while(j<nums.size()){
        m.insert(nums[j]);
        if(abs(*m.begin() - *m.rbegin())<=k) ans = max(ans, j-i+1);
        else{
            m.erase(m.find(nums[i]));
            i++;
        }
        j++;
    }
    return ans;
}

// Use 2 double ended queues to store the the max and min
// TC : O(n)
// SC : O(n)

int longestSubarray(vector<int>& nums, int limit){
    int ans = INT_MIN;
    int i=0, j=0;
    int k=limit;
    deque<int> maxd, mind;
    while(j<nums.size()){
        while(!maxd.empty() && maxd.back()<nums[j]) maxd.pop_back();
        while(!mind.empty() && mind.back()>nums[j]) mind.pop_back();
        maxd.push_back(nums[j]);
        mind.push_back(nums[j]);
        if(abs(mind.front() - maxd.front())<=k) ans = max(ans, j-i+1);
        else{
            if(maxd.front()==nums[i]) maxd.pop_front();
            if(mind.front()==nums[i]) mind.pop_front();
            i++;
        }
        j++;
    }
    return ans;
}