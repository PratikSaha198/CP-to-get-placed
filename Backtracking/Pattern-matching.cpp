// Input : 'abc'
// Output : ['a..', 'a.c', 'ab.', '.bc', '.b.', '..c']

#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

void doit(string s, int index){
    ans.push_back(s);
    for(int i=index;i<s.length();i++){
        char dum = s[i];
        s[i]='.';
        doit(s, i+1);
        s[i] = dum;
    }
}

int main(){

    string a = "abc";
    doit(a, 0);
    for(auto it : ans) cout<<it<<" , ";
    return 0;
}