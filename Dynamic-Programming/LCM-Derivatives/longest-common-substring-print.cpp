#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Make the Substring table.
// But keep track of the indexs of the max length substring result.
// After table move diagonally adding to the string till any of them reach i==0 || j==0 where dp[i][j]==0


void lcss(string X, string Y, int m, int n)
{   
    int result = 0, r, c;
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if(result < dp[i][j]){
                    result = dp[i][j];
                    r = i;
                    c = j;
                }
            }

            else
                dp[i][j] = 0;
        }
    }
    
    if(result == 0)
        cout<<"No substring";
        
    else{
        string answer;
        
        while(dp[r][c]!=0){
            answer.push_back(X[r-1]);
            r--;
            c--;
        }
        
        reverse(answer.begin(), answer.end());
        
        cout<<answer;
    }
    
}

int main()
{

    fast

    string a = "GEEKSFORGEEKS";
    string b = "GEEKSQUIZ";
    
    lcss(a, b, a.length(), b.length());

    return 0;
}
