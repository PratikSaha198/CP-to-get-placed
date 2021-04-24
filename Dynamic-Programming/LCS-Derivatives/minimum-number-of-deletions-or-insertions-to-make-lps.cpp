#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given one string -> Output the minimum number of characters to be deleted to make lomgest palindromic subsequence.
// Find LPS and then sustract it from the original string length.

// For Insertion essential the characters which had to be deleted neede to be paired up with themselves in their either right or left half.
// So its the same nunmber of deletions or insertions as answer, the question is JUST A TRICK QUESTION TO FIGURE OUT IF WE CAB FIND IF BOTH HAVE ASKED THE SAME THING.


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

int main()
{
    fast

    string str = "GEEKSFORGEEKS";
    string revstr;
    
    for (auto it = str.rbegin(); it != str.rend(); it++)
        revstr.push_back(*it);

    cout << str.length() - lcs(str, revstr, str.length(), revstr.length());

    return 0;
}
