#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;    


// Same as recursive approach just store the subproblem's answer in a DP table for non repetation.
// If the table's cell contains -1 then answer has to be computed at that value or else just return that answer if -1 is not present.


int dp[1001][1001];

int MCM(int arr[], int i, int j)
{

    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    int tempans;

    for (int k = i; k <= j - 1; k++)
    {
        tempans = MCM(arr, i, k) + MCM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        dp[i][j] = min(dp[i][j], tempans);
    }

    return dp[i][j];
}

int main()
{

    fast

    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    memset(dp, -1, sizeof(dp));

    cout << MCM(arr, 1, n - 1);

    return 0;
}
