#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given two strings A and B, return true or false if string A is a subsequence of string B.
// If the LCS length of A and B is same as A's length then answer is YES, A is a seubsequence of B.


int lcs(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{

    fast

    string a = "AXY";
    string b = "ADXCPY";

    int LCS = lcs(a, b, a.length(), b.length());

    if (LCS == min(a.length(), b.length()))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
