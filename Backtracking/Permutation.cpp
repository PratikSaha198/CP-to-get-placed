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


// PERMUTATION 2 ------------------------------------------------------------------------------------------
// THERE ARE REPEATATION ELEMENTS PRESENT

// USE a boolean vector too keep track of the elements already added

vector<vector<int>> ans;

void doit(vector<int> num, vector<int> &dum, vector<bool> cnt, int index)
{
    if(dum.size()==num.size())
    {
        ans.push_back(dum);
    }

    for(int i=0;i<num.size();i++)
    {
        if(cnt[i] or(i>0 and num[i]==num[i-1] and !cnt[i-1]))
            continue;
        
        cnt[i] = true;
        dum.push_back(num[i]);
        doit(num, dum, cnt, index);
        cnt[i] = false;
        dum.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    sort(begin(nums), end(nums));

    vector<int> dum;
    vector<bool> cnt(nums.size());

    doit(nums, dum, cnt, 0);

    return ans;
}


// SWAPPING TECHNIQUE
// Used an unordered set to keep track


void doit(vector<vector<int>> &ans, vector<int> nums, int index)
{
    if(index==nums.size())
    {
        ans.push_back(nums);
        return;
    }

    unordered_set<int> s;
    
    for(int i=index;i<nums.size();i++)
    {
        if(s.find(nums[i])!=s.end())
            continue;
        
        s.insert(nums[i]);
        swap(nums[i], nums[index]);
        doit(ans, nums, index+1);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    vector<vector<int>> ans;

    doit(ans, nums, 0);

    return ans;
}