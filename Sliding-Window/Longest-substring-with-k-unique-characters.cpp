#include<bits/stdc++.h>
using namespace std;

// Store the on going character count in a map
// The map's size provides us with the distinct characters
// When the k is not hit then just keep on increasgin the window
// If its hit then store the probable answer and increase the window (j++)
// If the window is hit and passed then keep on decreasing from i's end, if any count becomes 0 in the process then delete that ele, and keep of increasing window (j++)

int solve(string s, int k){
    int ans = INT_MIN;
    int i=0, j=0;
    string st;
    unordered_map<char, int> m;
    while(j<s.length()){
        m[s[j]]++;
        if(m.size()<k) j++;
        else if(m.size()==k){
            if((j-i+1)>ans){
                st = s.substr(i, j-i+1);
                ans = j-i+1;
            }
            j++;
        }
        else{
            while(m.size()>k){
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    cout<<st<<endl;
    return ans;
}

// TC : O(n)    
// SC : O(k)    

int main(){

    // Find the largest lengthed substring having k distinct chracters

    // Input  : "aabacbebebe", k = 3
    // Output : 7 along with "cbebebe"

    string s = "aabacbebebe";
    int k = 3;

    int ans = solve(s, k);
    cout<<ans;

    return 0;
}