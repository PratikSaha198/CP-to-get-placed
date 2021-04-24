#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given 2 strings -> output the shortest common supersequence.
// Derivative of LCS, here only choose the characters once when its repeating in both strings and then if not maintain order and add in final superstring.
// Essentailly m + n - lcs = its length (BEST CASE) (shortest)
//             m + n (WORST CASE) (longest)
// In the merged supersequence both the strings subsequence should be present.

// TC : O(m * n)
// SC : O(m * n)


int lcs(char X[], char Y[], int m, int n)
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
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[m][n];
}

int main()
{

    fast

    // Shortest common supersequence means, both the strings togther are there and a subsequence thing is gonna happen.
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    // Adding both the strings len and deleting the lcs does the job
    cout << m + n - lcs(X, Y, m, n);

    return 0;
}
