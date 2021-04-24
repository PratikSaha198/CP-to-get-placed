#include <bits/stdc++.h>
using namespace std;

int lis_recur(vector<int> &arr, int prev, int pos)
{
    if (pos == arr.size())
        return 0;

    int taken = 0;
    if (arr[pos] > prev)
        taken += 1 + lis_recur(arr, arr[pos], pos + 1);
    
    int nottaken = lis_recur(arr, prev, pos + 1);
    
    return max(taken, nottaken);
}

int main()
{

    int n; cin >> n;
    vector<int> some;

    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        some.push_back(x);
    }

    cout << lis_recur(some, INT_MIN, 0);

    int dp[n];
    dp[0] = 1;

    int ans = 1;
    
    for (int i = 1; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < i; j++)
        {
            if (some[i] > some[j])
                temp = max(temp, dp[j]);
        }
        dp[i] = temp + 1;
        ans = max(ans, dp[i]);
    }
    
    cout << ans;

    return 0;
}
