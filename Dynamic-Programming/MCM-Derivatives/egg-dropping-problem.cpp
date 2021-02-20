#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given some eggs and number of floors. Output the minimum number of tries to find out the maximum floor above which it will always break.

// BC : If we throw eggs from floor 0 or floor 1 then only 1 try is needed to find out.
//      If only 1 egg is given then we would need to try all the floors to find out.
// We have got 2 options the egg breaks or not breaks when we drop it from a floor. 
// We go from kth : floor 1 to f-1 floor.
// If the egg does break we check the above f-k floors and keep the number of eggs the same, else we reduce the eggs by 1 and reduce the floors by one.

// Memorised version is same, make a DP table and check if it has value -1 or not, if not do the normal.

// Optimised Memorisation -> redundant recursive calls of egg breaking or not breaking can be altered by indiidual checking if values are there are values or not at left a and right calls.

// SUPER OPTIMISED BELOW :  

// Drop eggs is a very classical problem.
// Some people may come up with idea O(KN^2)
// where dp[K][N] = 1 + max(dp[K - 1][i - 1], dp[K][N - i]) for i in 1...N.
// However this idea is very brute force, for the reason that you check all possiblity.

// So I consider this problem in a different way:
// dp[M][K]means that, given K eggs and M moves,
// what is the maximum number of floor that we can check.

// The dp equation is:
// dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1,
// which means we take 1 move to a floor,
// if egg breaks, then we can check dp[m - 1][k - 1] floors.
// if egg doesn't breaks, then we can check dp[m - 1][k] floors.

// dp[m][k] is the number of combinations and it increase exponentially to N


int edpr(int e, int f)
{
    if (f == 0 || f == 1)
        return f;

    if (e == 1)
        return f;

    int ans = INT_MAX, temp;

    for (int k = 1; k <= f; k++)
    {
        temp = 1 + max(edpr(e - 1, k - 1), edpr(e, f - k));
        ans = min(ans, temp);
    }

    return ans;
}

int dp[101][10001];

int edpr_memo(int e, int f)
{
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;

    if (dp[e][f] != -1)
        return dp[e][f];

    int ans = INT_MAX, temp;

    for (int k = 1; k <= f; k++)
    {
        temp = 1 + max(edpr(e - 1, k - 1), edpr(e, f - k));
        ans = min(ans, temp);
    }

    dp[e][f] = ans;
    return ans;
}

int edpr_memo_opti(int e, int f)
{
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;

    if (dp[e][f] != -1)
        return dp[e][f];

    int ans = INT_MAX, temp;

    int low, high;

    for (int k = 1; k <= f; k++)
    {

        if (dp[e - 1][k - 1] != -1)
            low = dp[e - 1][k - 1];
        else
        {
            low = edpr_memo_opti(e - 1, k - 1);
            dp[e - 1][k - 1] = low;
        }

        if (dp[e][f - k] != -1)
            high = dp[e][f - k];
        else
        {
            high = edpr_memo_opti(e, f - k);
            dp[e][f - k] = high;
        }

        temp = 1 + max(low, high);
        ans = min(ans, temp);
    }

    dp[e][f] = ans;
    return ans;
}

int edpr_dp(int e, int f)
{
    int dp[f + 1][e + 1];
    memset(dp, 0, sizeof(dp));

    int m = 0;

    while (dp[m][e] < f)
    {
        m++;
        for (int k = 1; k <= e; k++)
            dp[m][k] = 1 + dp[m - 1][k - 1] + dp[m - 1][k];
    }

    return m;
}

int main()
{

    fast

    int e = 2;
    int f = 4;

    cout << edpr(e, f);

    return 0;
}
