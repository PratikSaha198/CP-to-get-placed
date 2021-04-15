// A string S of lowercase English letters is given. 
// We want to partition this string into as many parts as possible so that each letter appears in at most one part, 
// and return a list of integers representing the size of these parts.

// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".

// Store the farthest occurence index of each character in a map.
// Initailise a pivot (the starting of curr partition) and end (its ending).
// For each character if the latest occurence index is the current index then insert the size as i-pivot+1 and pivot to the next index (i+1)


vector<int> partitionLabels(string s)
{
    unordered_map<char, int> m;
    
    for(int i=0;i<s.length();i++) 
        m[s[i]] = i;
    
    vector<int> ans;
    
    int pivot=0, end=0;
    
    for(int i=0;i<s.length();i++){
        end = max(end, m[s[i]]);
        if(i==end){
            ans.push_back(i-pivot+1);
            pivot = i+1;
        }
    }
 
    return ans;
}