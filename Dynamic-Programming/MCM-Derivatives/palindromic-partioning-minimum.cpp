#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;

// REDCURSION ===============

// Given a string -> output the minimum number of partitions needed to be done to make each part a palindrome.
// EXAMPLE : geek -> g | ee | k => 2 partitions

// Derivative of MUM : Partitons are to be done. so MUM
// BASE CONDITIONS : If size = NULL or 1 i.e i>j OR i==j then no partitions answer is 0
// If the string is palindrome return 0
// Else make 2 parttitons : i -> k and k+1 -> j solve recursively and inbetween these 2 parts 1 partition is required so add 1.
// Store min in each step

// MEMORISATION ==============

// Memorisation same as MCM memo

// OPTIMISATION ==============

// Any of the left and right subparts maybe already a palindrome, but stil they were called with a plus before
// So check if they are and store them in variables or compute them recrsively and store in DP cell.
// Rest same as above non optimum stuff

// SUPER OPTIMISED ===========

// If and only if the left part is a palindrome check the right part for palindrome.

// PRINT =====================

// Same as super optimised, just save the states each time in if statement when you find a left sub part as a palindrome. 

int dp[1001][1001];

bool ispalin(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

int pp(string s, int i, int j)
{
    if (i >= j)
        return 0;

    if (ispalin(s, i, j))
        return 0;

    int ans = INT_MAX, tempans;

    for (int k = i; k <= j - 1; k++)
    {
        tempans = pp(s, i, k) + pp(s, k + 1, j) + 1;
        ans = min(ans, tempans);
    }

    return ans;
}

int ppmemo(string s, int i, int j)
{
    if (i >= j)
        return 0;

    if (ispalin(s, i, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    int tempans;

    for (int k = i; k <= j - 1; k++)
    {
        tempans = pp(s, i, k) + pp(s, k + 1, j) + 1;
        dp[i][j] = min(dp[i][j], tempans);
    }

    return dp[i][j];
}

int ppmemo_optimi(string s, int i, int j)
{

    if (i >= j)
        return 0;

    if (ispalin(s, i, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    int tempans, left, right;

    for (int k = i; k <= j - 1; k++)
    {

        if (dp[i][k] != -1)
            left = dp[i][k];
        else
        {
            left = ppmemo_optimi(s, i, k);
            dp[i][k] = left;
        }

        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
        {
            right = ppmemo_optimi(s, k + 1, j);
            dp[k + 1][j] = right;
        }

        tempans = left + right + 1;
        dp[i][j] = min(dp[i][j], tempans);
    }
 
    return dp[i][j];
}

int ppmemo_super_optimi(string s, int i, int j)
{
    if (i >= j)
        return 0;   

    if (dp[i][j] != -1)
        return dp[i][j];

    if (ispalin(s, i, j))
        return 0;

    int tempans, left, right, ans = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        if (ispalin(s, i, k))
        {
            left = 0;
            right = ppmemo_optimi(s, k + 1, j);
            tempans = left + right + 1;
            ans = min(ans, tempans);
            dp[i][j] = ans;
        }
    }

    return dp[i][j];
}

void allpalin(vector<vector<string>> &ans, vector<string> &curr, int i, int j, string s)
{
    if (i >= j)
    {
        ans.push_back(curr);
        return;
    }
    for (int k = i; k<=j-1; k++)
    {
        if (ispalin(s, i, k))
        {
            string a = "";
            for (int l = i; l <= k; l++)
                a += s[l];
            curr.push_back(a);
            allpalin(ans, curr, k + 1, j, s);
            curr.pop_back();
        }
    }
}

int main()
{

    fast

    string s = "geek";
    int si = s.length();

    cout << pp(s, 0, si - 1);

    memset(dp, -1, sizeof(dp));

    cout << ppmemo(s, 0, si - 1);

    memset(dp, -1, sizeof(dp));

    cout << ppmemo_optimi(s, 0, si - 1);

    memset(dp, -1, sizeof(dp));

    cout << ppmemo_super_optimi(s, 0, si-1);

    vector<vector<string>> ans;
    vector<string> curr;

    allP(ans, curr, 0, si, s);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
