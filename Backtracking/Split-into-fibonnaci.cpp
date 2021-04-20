// Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].
// Input: "123456579"
// Output: [123,456,579]

// Input: "0123"
// Output: []
// Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.

vector<int> all;

bool fibochecker(vector<int> num){
    for(int i=0;i<num.size()-2;i++){
        if((num[i]+num[i+1])!=num[i+2]) return false;
    }
    return true;
}

void findall(string s, int index, vector<int> &dum){

    if(index==s.length() and dum.size()>=3 and fibochecker(dum)){
        all = dum;
        return;
    }

    for(int i=s.length()-1;i>=index;i--){
        string sub = s.substr(index, i-index+1);
        if(sub.length()>29) return;
        if((sub[0]=='0' and sub.size()>1) || sub.length()>10) continue;
        long long int hey = stoll(sub);
        dum.push_back(hey);
        findall(s, i+1, dum);
        dum.pop_back();
    }
}

vector<int> splitIntoFibonacci(string s) {
    vector<int> dum;
    findall(s, 0, dum);
    return all;
}