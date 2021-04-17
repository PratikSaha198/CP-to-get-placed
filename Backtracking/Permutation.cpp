// Given an array nums of distinct integers, return all the possible permutations.
// You can return the answer in any order.

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Use DFS to do it


vector<vector<int>> ans;

void dfs(vector<int> num, vector<int> &dum)
{
    if(dum.size()==num.size()){
        ans.push_back(dum);
        return;
    }

    for(int i=0;i<num.size();i++)
    {
        if(dum.empty() || find(dum.begin(), dum.end(), num[i])==dum.end())
        {
            dum.push_back(num[i]);
            dfs(num, dum);
            dum.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<int> dum;
    dfs(nums, dum);
    return ans;
}