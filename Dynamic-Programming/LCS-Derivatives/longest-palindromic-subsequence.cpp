#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given one string -> Output the length longest palindrome which is a subsequence.
// one would think its not a derivative of lcs as only one string is given but it is.
// Make a second string as reverse of the one given and find out lcs, that an a single interger which is the answer.


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
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[m][n];
}

// Printing is same as NORMAL LCS

int main()
{

    fast

    string str = "GEEKSFORGEEKS";
    string revstr;
    for (auto it = str.rbegin(); it != str.rend(); it++)
        revstr.push_back(*it);

    cout << lcs(str, revstr, str.length(), revstr.length());

    return 0;
}
