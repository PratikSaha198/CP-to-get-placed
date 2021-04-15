// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

// Sort according to the starting element
// If the answer array is empty or the last vector's 2nd ele is smaller than the current one's the normall add it
// Else the last vector's 2nd ele is the max of (it and the current one's 2nd ele)


vector<vector<int>> merge(vector<vector<int>>& v)
{
    vector<vector<int>> ans;
    
    sort(v.begin(), v.end());
    
    for(auto it : v){
        if(ans.empty() || ans.back()[1]<it[0]) 
            ans.push_back(it);
        else 
            ans.back()[1] = max(ans.back()[1], it[1]);
    }
    
    return ans;
}