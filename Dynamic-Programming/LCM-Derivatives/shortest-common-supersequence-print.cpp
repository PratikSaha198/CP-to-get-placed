#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// If the same character is encountered in both the strings, then add it once in the superstring.
// Else Add both the characters according to which is greater.
// In print LCS, when base condition of either of the string's length becoming 0 then it was stopped.
// But here when either becomes 0, still the rest characters of the string whose length has become 0 has to be included.
// So both the loops are provided to add rest charcters, maybe either of them run, or none.


void print_SCSS(char X[], char Y[], int m, int n)
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
            {
                s.push_back(Y[j - 1]);
                j--;
            }
            else
            {
                s.push_back(X[i - 1]);
                i--;
            }
        }
    }

    while (i > 0)
    {
        s.push_back(X[i - 1]);
        i--;
    }
    while (j > 0)
    {
        s.push_back(Y[j - 1]);
        j--;
    }

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

    print_SCSS(X, Y, m, n);

    return 0;
}
