// You are given a string s that consists of only digits.
// Check if we can split s into two or more non-empty substrings such that the numerical values of the substrings are in descending order and the difference between numerical values of every two adjacent substrings is equal to 1.

// For example, the string s = "0090089" can be split into ["0090", "089"] with numerical values [90,89]. 
// The values are in descending order and adjacent values differ by 1, so this way is valid.

// Return true if it is possible to split s​​​​​​ as described above, or false otherwise. 

// Input: s = "10009998"
// Output: true
// Explanation: s can be split into ["100", "099", "98"] with numerical values [100,99,98].

// Insert into an array if its empty (only after making it valid)
// Then keep on cheking with the last element of it regarding the condition of 1 difference and if true move forward the index
// If the size of the array is greater than 2 when you ahve reached the last index it means that the answer is available else not

bool recur_tradi(string &s, int i, vector<unsigned long long> arr){
    if(i>=s.length()) return arr.size()>=2;
    unsigned long long curr = 0;
    for(int j=i;j<s.length();j++){
        curr = curr*10 + (s[j] - '0');
        if(arr.size()==0 || (arr.back()-curr==1)){
            arr.push_back(curr);
            if(recur_tradi(s, j+1, arr)) return true;
            arr.pop_back();
        }
    }
    return false;
}

// No need to keep the vector of the splitted string -> nums, as only trye or false is asked, keep the array count.
// A curr and previous element structure helps this comparison.
// If the curr is greater than the prev one, this means the descending structure is not followed so break from it.

bool recur(string &s, long long prev, int i, int cnt){
    if(i==s.length()) return cnt>1;
    unsigned long long curr = 0;
    for(int j=i;j<s.length();j++){
        curr = curr*10 + s[j] - '0';
        if(prev-curr == 1 || prev==-1){
            if(recur(s, curr, j+1, cnt+1)) return true;
        }
        if(curr > prev && prev!=-1) break;
    }
    return false;
}

bool splitString(string s){

    if(s.length()<=1) return false;
    cout<<recur(s, -1, 0, 0);
    
    vector<unsigned long long> arr;
    cout<<recurtwo(s, 0, arr);
}