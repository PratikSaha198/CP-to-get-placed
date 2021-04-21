// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

// MAP COMPARATOR FUNCTION EXPLAINED -------------------------------------------------------


vector<int> frequencySort(vector<int>& nums){
    unordered_map<int, int> m;
    for(auto it : nums) m[it]++;
    sort(begin(nums), end(nums), [&](int a, int b) {
        return m[a]==m[b]?a>b:m[a]<m[b];
    });
    return nums;
}