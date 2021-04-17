// A happy string is a string that:
// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
// Return the kth string of this list or return an empty string if there are less than k happy strings of length n

//Input: n = 3, k = 9
// Output: "cab"
// Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. 
// You will find the 9th string = "cab"

// USE DFS and a same logic as count possible substrings


vector<string> ans;

void dfs(vector<char> &chars, string &s, int n, int k)
{
    if(ans.size()==k) 
        return;
    
    if(s.length()==n){
        ans.push_back(s);
        return;
    }
    
    for(int i=0;i<3;i++)
    {
        if(s.empty() || (s.back()!=chars[i]))
        {
            s+=chars[i];
            dfs(chars, s, n, k);
            s.pop_back();
        }
    }
}

string getHappyString(int n, int k)
{
    vector<char> chars{'a', 'b', 'c'};
    string emp = "";
    dfs(chars, emp, n, k);

    // TO PRINT THEM --------->

    // for(int i=1;i<=n;i++)
        // dfs(chars, emp, i, k);
    // for(auto it : ans) cout<<it<<endl;
    
    return ans.size()==k?ans.back():"";
}