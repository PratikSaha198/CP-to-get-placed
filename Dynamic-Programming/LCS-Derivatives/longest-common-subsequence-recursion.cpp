#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Subsequence -> elements doesn't have to be one after the other, just have to be in order.
// Sustring -> elements have to be contiguious.
// Given two strings -> output the lcs (number)

// BASE CONDITIONS : If any of their lengths becomes 0 then lcs will be 0
// Checking from back to front, if last char gets match then add 1 and check both the strings -1 length from total.
// Else if not same, either choose last element in 1st string and look for match in whole of 2nd, or vice versa.
// Longest common is required so max() function is used. 


int lcs(char X[], char Y[], int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
}

int main()
{

    fast

    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    cout << lcs(X, Y, m, n);

    return 0;
}
