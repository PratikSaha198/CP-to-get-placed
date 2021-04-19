// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Use normal recursion of backtracking to solve
// The condition that the last element is smaller than the next element must be ensured
// 4 ms time


vector<vector<int>> ans;

void doit(vector<int> &nums, vector<int> dum)
{
    ans.push_back(dum);

    for(int i=0;i<nums.size();i++)
    {
        if(find(dum.begin() ,dum.end(), nums[i])==dum.end() and (dum.size()==0 or dum.back()<nums[i]))
        {
            dum.push_back(nums[i]);
            doit(nums, dum);
            dum.pop_back();
        }
    }
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<int> dum;

    doit(nums, dum);

    return ans;
}


// IMPROVED TIME COMPLEXITY
// Keep track of the index of the one added and while the next call of function after that index only is added.
// 1 ms


void subsets(vector<int>& nums, int index, vector<int>& dum, vector<vector<int>>& ans)
{
    ans.push_back(dum);

    for(int j = index; j < nums.size(); j++)
    {
        dum.push_back(nums[j]);
        subsets(nums, j + 1, dum, ans);
        dum.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> dum;

    subsets(nums, 0, dum, ans);

    return ans;
}


// SUBSET 2 ----------------------------------------------------------------------------------
// Contains duplicates

// Keep track of the index being added and dont let ot be larger than the current one


vector<vector<int>> ans;  

void doit(vector<int> &nums, vector<int> dum, int index)
{   
    ans.push_back(dum);
    
    for(int i=index;i<nums.size();i++)
    {
        if(i>index and nums[i]==nums[i-1]) 
            continue;

        dum.push_back(nums[i]);
        doit(nums, dum, i+1);
        dum.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    vector<int> dum;
    sort(nums.begin(), nums.end());
    doit(nums, dum, 0);
    return ans;
}