string lpsub(string X, string Y, int m, int n)
{
    int result = 0, r, c;
    int dp[m + 1][n + 1];
    string ans;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (result < dp[i][j])
                {
                    string temp = X.substr(i - dp[i][j], dp[i][j]);
                    string rev = temp;
                    reverse(rev.begin(), rev.end());
                    if (rev == temp)
                    {
                        result = dp[i][j];
                        ans = temp;
                    }
                }
            }

            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

string longestPalindrome(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return lpsub(s, rev, s.length(), s.length());
}