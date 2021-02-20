#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given 2 strings, you can making a binary tree by diving a string in 2 parts but any of them can't be null/empty string.
// a scrambled string can form if any or more no leaf nodes are swapped in the binary tree breakdown and the string is put back together.
// OUTPUT True/False of they 2nd string is a scrambled string of the 1st one.

// BC : If length unequal => false
//      If both of them are null => true
//      If both are indentical then => true
//      If a's length is 1 then it's a leaf node so false
// The division lines will go from 1 to n-1 as 0 index's one whould result in |great but we need start as g|reat.
// Divsion can be done or cant be done so we ahev 2 options.
// A = ...smol... | ......big...... B = .....big......|...smol... check a.smol with b.smol and a.big with b.big
// OR
// A = ...smol... | ......big...... B = ...smol... | ......big...... same as above.
// If found true with all return true else false

// MEMORISATION ================================

// Make an unordered map and store key as a + " " + b and true/false as value.
// Hence check before entering loop that the key is present or not, hence small insances are saved and looked up
// At the end before returning answer, store the key value pair.


bool srams_recur(string a, string b)
{
    if (a.compare(b) == 0)
        return true;

    if (a.length() <= 1)
        return false;

    bool ans = false;
    int n = a.length();

    for (int i = 1; i <= n - 1; i++)
    {
        if (((srams_recur(a.substr(0, i), b.substr(n - i, i)) == true && srams_recur(a.substr(i, n - i), b.substr(0, n - i)) == true) || (srams_recur(a.substr(0, i), b.substr(0, i)) == true && srams_recur(a.substr(i, n - i), b.substr(i, n - i)) == true)))
            return true;
    }

    return false;
}

unordered_map<string, bool> mp;

bool srams_memo(string a, string b)
{

    if (a.compare(b) == 0)
        return true;

    if (a.length() <= 1)
        return false;

    string s = a + " " + b;

    if (mp.find(s) != mp.end())
        return mp[s];

    bool ans = false;
    int n = a.length();

    for (int i = 1; i <= n - 1; i++)
    {
        if (((srams_recur(a.substr(0, i), b.substr(n - i, i)) == true && srams_recur(a.substr(i, n - i), b.substr(0, n - i)) == true) || (srams_recur(a.substr(0, i), b.substr(0, i)) == true && srams_recur(a.substr(i, n - i), b.substr(i, n - i)) == true)))
        {
            ans = true;
            break;
        }
    }
    mp[s] = ans;
    return ans;
}

int main()
{

    fast

    string a = "great";
    string b = "rgeat";

    if (a.length() != b.length())
        cout << false;

    else if (a.length() == 0 && b.length() == 0)
        cout << true;

    else
    {
        cout << srams_recur(a, b);
        cout << srams_memo(a, b);
    }

    return 0;
}