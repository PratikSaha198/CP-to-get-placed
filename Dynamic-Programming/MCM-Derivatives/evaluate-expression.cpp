#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// ALSO CALLED BOOLEAN PARENTHESISATION 

// Given a string which contains T or F with symbols & | ^ in between each alternatively -> Output number of ways to Make the expression true by placing brackets at places.

// MCM derivative as placing brackets or making division sis the primary goal.
// 'State' a 3rd variable is needed to kep track of the T OR F at each step, we need T at end.
// BC : If null string then 0 ways
//      If 1 len then if the state is true return 1 else if false return 0
// i -> k-1 , k (the operator in between left and right states) , k+1 -> j are the partitons 
// Make t or f of left and right and compute all the states then according to operator in between compute the answer.

// A 3D DP is required as i, j and state are the changing variables but it also can be done using a map where key is "i j state" nad value as answer.
// Store the states there and check whenever its present then return the answer.


int cntParway(string s, int i, int j, int state){

    if(i>j)
        return 0;
        
    if(i == j){
        if(state==1)
            return (s[i]=='T');
        else
            return (s[i]=='F');
    }
    
    int lt, lf, rt, rf, answer=0;
    
    for(int k=i+1;k<=j-1;k+=2){
        
        lt = cntParway(s, i, k-1, 1);
        lf = cntParway(s, i, k-1, 0);
        rt = cntParway(s, k+1, j, 1);
        rf = cntParway(s, k+1, j, 0);
        
        if(s[k] == '&')
        {
            if(state==1)
                answer += lt * rt;
            else    
                answer += lf * rt + lt * rf + lf * rf;
        }
        
        else if(s[k] == '^')
        {
            if(state==1)
                answer += lf * rt + lt * rf;
            else
                answer += lt * rt + lf * rf;
        }
        
        else if(s[k] == '|')
        {
            if(state==1)
                answer += lt * rt + lt * rf + lf * rt;
            else
                answer += lf * rf;
        }
        
    }
    return answer;
}

unordered_map<string, int> mp;

int cntParwayDP(string s, int i, int j, int state)
{
    if (i > j)
        return 0;

    if (i == j)
    {
        if (state == 1)
            return (s[i] == 'T');
        else
            return (s[i] == 'F');
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(state));

    if (mp.find(temp) != mp.end())
        return mp[temp];

    int lt, lf, rt, rf, answer = 0;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        lt = cntParway(s, i, k - 1, 1);
        lf = cntParway(s, i, k - 1, 0);
        rt = cntParway(s, k + 1, j, 1);
        rf = cntParway(s, k + 1, j, 0);

        if (s[k] == '&')
        {
            if (state == 1)
                answer += lt * rt;
            else
                answer += lf * rt + lt * rf + lf * rf;
        }

        else if (s[k] == '^')
        {
            if (state == 1)
                answer += lf * rt + lt * rf;
            else
                answer += lt * rt + lf * rf;
        }

        else if (s[k] == '|')
        {
            if (state == 1)
                answer += lt * rt + lt * rf + lf * rt;
            else
                answer += lf * rf;
        }
    }
    mp[temp] = answer;
    return answer;
}

int main()
{
    fast

    char symbols[] = "TTFT";
    char operators[] = "|&^";
    
    int si = sizeof(symbols)-1;
    
    string str;
    
    for(int i=0;i<si;i++){
        str+=symbols[i];
        if(i<si-1)
            str+=operators[i];
    }
    
    cout << cntParway(str, 0, str.size()-1, 1);

    cout << cntParwayDP(str, 0, str.size()-1, 1);

    return 0;
}