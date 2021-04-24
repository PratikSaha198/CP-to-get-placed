#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Same as recursive solution, just storing it in an array, and an element in dp[i][j], gives ~
// answer for X of length i and Y of length j. 
// Hence bottom right corner element gives full length of both's answer.

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

    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    cout << lcs(X, Y, m, n);

    return 0;
}
