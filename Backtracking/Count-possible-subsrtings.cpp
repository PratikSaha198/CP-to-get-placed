// You have n  tiles, where each tile has one letter tiles[i] printed on it.
// Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

// Input: tiles = "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

// Store the count of each characters
// Declare a global sum
// Go through all the character counts
// If the count is empty theres nothing to do
// For each iteration keep on increasing the sum by one and decrease the count and call the dfs over that, later again increase the count
 

#include<bits/stdc++.h>
using namespace std;

int sum=0;
// set<string> se;
// void dfs(vector<int> ans, string s)
void dfs(vector<int> ans)
{   
    // for(auto it : s) cout<<it<<endl;
    // cout<<s<<endl;
    for(int i=0;i<26;i++)
    {
        if(ans[i]==0) 
            continue;
        sum++;
        ans[i]--;
        // s+=char(i+int('A'));
        // se.insert(s);
        // dfs(ans, s);
        dfs(ans);
        ans[i]++;
    }
}

int numTilePossibilities(string tiles)
{
    vector<int> ans(26, 0);
    
    for(auto it : tiles)
        ans[it-'A']++;  

    // string s="";
    // dfs(ans, s);
    dfs(ans);
    
    return sum;
}

int main(){

    cout<<numTilePossibilities("AAB")<<endl;
    // for(auto it : se) cout<<it<<endl;

    return 0;
}