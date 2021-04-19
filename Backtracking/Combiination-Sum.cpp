// Given an array of distinct integers candidates and a target integer target
// Return a list of all unique combinations of candidates where the chosen numbers sum to target. 
// You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. 
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

// Start from the target then keep on decreasing as you keep on adding elements to it.
// Keep track of index and start from the next index as you go on, but dont increase by 1 due to repeatation allowed


void doit(vector<vector<int>> &ans, vector<int> &dum, vector<int> &candi, int n, int index)
{
    if(n<0) 
        return;
    
    else if(n==0) 
        ans.push_back(dum);
    
    else{
        for(int i=index;i<candi.size();i++)
        {
            dum.push_back(candi[i]);
            doit(ans, dum, candi, n-candi[i], i);
            dum.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> dum;

    doit(ans, dum, candidates, target, 0);
    
    return ans;
}


// SAME QUESTION BUT REPEATATION NOT ALLOWED

// So first sort the array
// Then also keep on increasing the index and dont add of the last element of original array is the sam eas the next element.


void doit(vector<vector<int>> &ans, vector<int> &dum, vector<int> &candi, int n, int index)
{
    if(n<0) 
        return;
    else if(n==0) 
        ans.push_back(dum);
    else{
        for(int i=index;i<candi.size();i++)
        {
            if(i>index and candi[i]==candi[i-1]) 
                continue;

            dum.push_back(candi[i]);
            doit(ans, dum, candi, n-candi[i], i+1);
            dum.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> dum;

    sort(begin(candidates), end(candidates));

    doit(ans, dum, candidates, target, 0);
    
    return ans;
}