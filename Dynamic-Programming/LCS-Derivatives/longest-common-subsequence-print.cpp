#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Print the actual LCS, rather than just its length.
// Make the LCS table.
// Starting from the dp[m][n] reverse back your steps taken till any of the strings becomes empty, i.e either i=0 OR j=0
// If the chosen cell has same character in both the strings then add it to a string, and move to the upper left diagonal cell.
// Otherwise just move to the left or above cell whichever was maximum.
// Reverse the string and print it.


void print_LCS(char X[], char Y[], int m, int n)
{
    // Make th normal dp table
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

    // As the last element contains the answer, thus move backwards from it, as keeping on checking if both are same
    // Else if not same, check which is greater and move towards it

    int i = m, j = n;
    vector<char> s;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            s.push_back(X[i - 1]);
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

    // As the string is generated backwards up, thus reverse it
    reverse(s.begin(), s.end());

    for (auto it : s)
        cout << it;
}

int main()
{

    fast

    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    print_LCS(X, Y, m, n);

    return 0;
}
