#include <bits/stdc++.h>
using namespace std;

// Given a string, output the number of possible palindromes which are substrings.

// Check all substrings if each is a palindrome then keep on adding to the result.
// O( N^3 )

// DP :
// BASE CONDITIONS : Single letters substring, dp[i][i] = true
//                   Double letters substring, dp[i][i+1] = true if(s[i] == s[i+1]) : else false
// Go from first to last and last to first : dp[i][j] = true if dp[i+1][j-1] else false
// O( N^2 ) : Space O( N^2 )

// Expand Around Possible Centers
// Algorithm
// Choose all possible centers for potential palindromes:
// 1. Every single character in the string is a center for possible odd-length palindromes
// 2. Every pair of consecutive characters in the string is a center for possible even-length palindromes.
// For every center, we can expand around it as long as we get palindromes (i.e. the first and last characters should match).
// O( N^2 ) : Space O( 1 )

int ispalin(string s, int l, int h)
{
    while (l < h)
    {
        if (s[l++] != s[h--])
            return false;
    }
    return true;
}

int allSubstrings(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            cnt += ispalin(s, i, j);
        }
    }
    return cnt;
}

int cs_dp(string s)
{
    int n = s.length();
    if (n <= 0)
        return 0;
    bool dp[n][n];
    fill_n(*dp, n * n, false);
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = (s[i] == s[i + 1]);
        ans += dp[i][i + 1];
    }
    for (int l = 3; l <= n; l++)
    {
        for (int i = 0, j = i + l - 1; j < n; i++, j++)
        {
            dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            ans += dp[i][j];
        }
    }
    return ans + s.length();
}

int toftob(string &s, int i, int j)
{
    int ans = 0;
    while (i >= 0 && j < s.length())
    {
        if (s[i--] != s[j++])
            break;
        ans++;
    }
    return ans;
}

int expandac(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ans += toftob(s, i, i);
        ans += toftob(s, i, i + 1);
    }
    return ans;
}

int main()
{

    string s = "aaa";

    cout << allSubstrings(s);

    cout << cs_dp(s);

    cout << expandac(s);

    return 0;
}
