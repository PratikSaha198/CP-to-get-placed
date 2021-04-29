#include<bits/stdc++.h>
using namespace std;

// Take in the count of the 2nd substring characters, and basically when the count (i.e all the distinct characters) become 0, we take in a answer
// Iterate over the 1st string and if the curr elemeent is in it then decrease its count and 'count' variable accordingly
// THE CATCH HERE IS ---> if the t string is "ABC", then a substring "BCDA" can also be the answer, so different stuff can also come in it, but it ahs to minimum overall
// Till the count is remains 0 and the i part is less than j till then keep on increasing i, thus OPTIMISING THE ANSWER
// Take in a len and a string 
// If the s[i] is present then increase it and also the 'count' variable
// EXMAPLE - if the map is A : 2, B : 1, and the all the elements have been encountered and suppose more A eles are encountered then like the count becomes A : -2
// ... therefore the i part window sliding changes it to 0, thus minimising the window 
// Slide window

// TC : O(n+m)
// SC : O(n+m)

void solve(string s, string t){

    unordered_map<char, int> m;
    for(auto it : t) m[it]++;
    
    string ans = "";
    int maxlen = INT_MAX;
    int i=0, j=0;
    int count = m.size();
    
    while(j<s.length()){
        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0) count--; 
        }
        while(count==0 and i<=j){
            if(maxlen > (j-i+1)){
                maxlen = j-i+1;
                ans = s.substr(i, j-i+1);
            }
            if(m.find(s[i])!=m.end()){
                m[s[i]]++;
                if(m[s[i]]==1) count++;
            }
            i++;
        }
        j++;
    }
    
    cout<<ans<<" "<<maxlen;
}

int main(){

    // Given two strings s and t, return the minimum window in s which will contain all the characters in t.

    // Input: s = "ADOBECODEBANC", t = "ABC"
    // Output: "BANC"

    string s = "ADOBECODEBANC";
    string t = "ABC";

    solve(s, t);

    return 0;
}