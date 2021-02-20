#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given a string find the longest repeated subsequence, it must be repeating to be considered and need not to be contiguious.
// LCS derivative where same str needs to be passed as 2nd string too, and if they are at same positions in both the strings then don't consider, otherwise same as LCS.
// While printing too it has same logic as LCS just i!=j has to be maintained.


int lrs_length(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (X[i - 1] == Y[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

void lrs_print(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (X[i - 1] == Y[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = m, j = n;
    string ans;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1] && i != j)
        {
            ans.push_back(X[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto it : ans)
        cout << it;
}

int main()
{

    fast

    string s = "AABEBCDD";

    cout << lrs_length(s, s, s.length(), s.length());

    lrs_print(s, s, s.length(), s.length());

    return 0;
}