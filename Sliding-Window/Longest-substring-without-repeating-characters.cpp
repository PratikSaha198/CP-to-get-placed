#include<bits/stdc++.h>
using namespace std;

// The k is not provided explicitly in this question
// Can be refactorred from the previous question where k distinct charcater longest substring was asked
// The condition will be hit when the map's size if the current window's size
// Else, keep on deleting from the i's end and dreasing the map's size when any character hits 0

int solve(string s){
    int ans = INT_MIN;
    int i=0, j=0;
    string st;
    unordered_map<char, int> m;
    while(j<s.length()){
        m[s[j]]++;
        // if(m.size()>(j-i+1)) j++;
        if(m.size()==(j-i+1)){
            if((j-i+1)>ans){
                st = s.substr(i, j-i+1);
                ans = j-i+1;
            }
            j++;
        }
        else{
            while(m.size()<(j-i+1)){
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

    // Find the largest lengthed substring having all distinct chracters

    // Input  : "geeksforgeeks"
    // Output : 7 along with "eksforg"

    string s = "geeksforgeeks";

    int ans = solve(s);
    cout<<ans;

    return 0;
}