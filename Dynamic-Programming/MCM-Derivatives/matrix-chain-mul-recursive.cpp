#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given an array (sequence of matrices) -> output the minimum cost to multiply them all together.
// (ABC)D = (AB)(CD) = A(BCD) = ....
// EXAMPLE :  A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix =>
//            10 30 5 60
//            (AB) C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations (cost)
//            A (BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations (cost)

// Divide array into 2 parts, from i->k AND k+1->j, solve them recursively and also add their in between results to tempans and finalanswer is the minimum of the lot.
// i.....k k+1......j
// BASE CONDITIONS : if i > j or i == j then it is not valid as 1st case impossible and 2nd case only 1 elemnent is there.
// A size(M X N) is given by arr[i] = arr[i] X arr[i-1]
// Size of array - 1 number of matrices's size are given.
// If A B C is AB BC ~ A*B*C
// A B C D E F
// A B   B C   C D   D E
// A C               C E
// A*C*E = arr[i-1]*arr[k]*arr[j] = as i pointed to 1 index and j pointed to last index.


int MCM(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    int ans = INT_MAX, tempans;

    for (int k = i; k <= j - 1; k++)
    {
        tempans = MCM(arr, i, k) + MCM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, tempans);
    }

    return ans;
}

int main()
{

    fast

    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << MCM(arr, 1, n - 1);

    return 0;
}
