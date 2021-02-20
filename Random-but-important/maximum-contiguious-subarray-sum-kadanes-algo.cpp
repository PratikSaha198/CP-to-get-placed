#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;

// Kadane’s Algorithm:

// Initialize:
//     max_so_far = 0
//     max_ending_here = 0

// Loop for each element of the array
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
//   (c) if(max_ending_here < 0)
//             max_ending_here = 0
// return max_so_far


int kadane(int arr[], int n)
{
    int max_so_far = INT_MIN, max_here = 0;

    for (int i = 0; i < n; i++)
    {
        max_here = arr[i] + max_here;

        if (max_so_far < max_here)
            max_so_far = max_here;

        if (max_here < 0)
            max_here = 0;
    }

    return max_so_far;
}

int kadane_impro(int arr[], int n)
{
    int here = arr[0], ans = arr[0];

    for (int i = 1; i < n; i++)
    {
        here = max(arr[i], here + arr[i]);
        ans = max(ans, here);
    }

    return ans;
}

void kadane_print(int arr[], int n)
{
    int here = 0, ans = INT_MIN, s = 0, start = 0, end = 0;

    for (int i = 0; i < n; i++)
    {
        here = here + arr[i];

        if (ans < here)
        {
            ans = here;
            start = s;
            end = i;
        }

        if (here < 0)
        {
            here = 0;
            s = i + 1;
        }

    }

    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
}

// MAX PRODUCT SUBARRAY

// Calculate prefix product in A
// Calculate suffix product in A.
// Return the max.

int maxProduct(vector<int> &nums)
    {
    int ans = nums[0], l = 0, r = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        l = (l == 0 ? 1 : l) * nums[i];
        r = (r == 0 ? 1 : r) * nums[n - i - 1];
        ans = max(ans, max(l, r));
    }
    return ans;
}



int main()
{

    fast

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);

    cout << kadane(a, n) << kadane_impro(a, n);
    cout << endl;
    kadane_print(a, n);

    return 0;
}
