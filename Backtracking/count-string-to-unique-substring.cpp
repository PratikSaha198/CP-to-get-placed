// Given a string s, return the maximum number of unique substrings that the given string can be split into.
// You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string.
// However, you must split the substrings such that all of them are unique.

// Input: s = "ababccc"
// Output: 5
// Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. 
// Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.

// As any of the previous substrings character wlll not be continued in the next one.
// Therefore each time a new temporary variable is declared
// Global answer


unordered_set<string> st;
int ans=0;

void dfs(string &s, int idx)
{
    if(st.size()>ans)
        ans=st.size();
    
    if(idx>=s.length())
        return;
    
    string str="";
    
    for(int i=idx ; i<s.length() ; i++)
    {
        str += s[i];
    
        if(st.find(str)==st.end())
        {
            st.insert(str);
            dfs(s,i+1);
            st.erase(str);
        }
    }
}

int maxUniqueSplit(string s) {

    dfs(s,0);

    return ans;
}