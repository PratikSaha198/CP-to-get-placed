#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Substrings means it has to be contiguous
// Derivate of LCS
// If one by one matching contnuies, then increase answer by 1, else return ans into 0 and again inc/dec ing.
// Store the max() of the length matching subtrings.


int LCSubStr(char X[], char Y[], int m, int n)
{
    int dp[m + 1][n + 1];
    int ans = 0;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }

            else
                dp[i][j] = 0;
        }
    }
    
    return ans;
}

int main()
{

    fast

    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";
    int m = strlen(X);
    int n = strlen(Y);

    cout << LCSubStr(X, Y, m, n);

    return 0;
}
