#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given two strings A and B, convert A to B by either inserting or deletting elements -> output both minimum number of insertions and deletions.
// Example : "heap" -> "pea", find lcs between them "ea", then essentially "h" and "p" to be deleted and "p" to be added.
// Basically make an intermediate step from A to LCS to B.
// Answer -> len(A) - lcs : DELETION
//           len(B) - lcs : INSERTION


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

    char X[] = "geeksforgeeks";
    char Y[] = "geeks";
    int m = strlen(X);
    int n = strlen(Y);

    cout << (m - lcs(X, Y, m, n)) << " " << (n - lcs(X, Y, m, n));

    return 0;
}
