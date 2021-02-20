#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given two strings A and B, by insertion, deletion and replacement find minimum number of operations needed to make it.
// From minimum no. of insertions and deletions from a to b question just replacement fucntionality is added.

// BASE CONDTIONS : If first string is empty, the only option is to insert all characters of second string into first.
//                  If second string is empty, the only option is to remove all characters of first string.
// If last element of both strings are same then do nothing, just decrease both of its length.
// Else consider all operations insert, remove, replace take minimum and add 1.


int editDist_recur(string a, string b, int m, int n)
{
    if (m == 0)
        return n;

    if (n == 0)
        return m;

    if (a[m - 1] == b[n - 1])
        return editDist_recur(a, b, m - 1, n - 1);

    else
        return 1 + min({editDist_recur(a, b, m, n - 1), // insert
                        editDist_recur(a, b, m - 1, n), // remove
                        editDist_recur(a, b, m - 1, n - 1)}); // replace
}

int editDist_dp(string a, string b, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;

            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
        }
    }

    return dp[m][n];
}

int main()
{

    fast

    string str1 = "sunday";
    string str2 = "saturday";

    cout << "EDrecur: " << editDist_recur(str1, str2, str1.length(), str2.length());

    cout << endl;

    cout << "EDdp: " << editDist_dp(str1, str2, str1.length(), str2.length());

    return 0;
}
