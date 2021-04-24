#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;


// Given a few denmination of coins and a SUM, find number of ways to use multiple of number times any of them to combine them to it.
// Multiple times choosing so unbounded knapsack derivative.
// Essentially count of subset set sum problem with just dp[i-1][] -> dp[i][] change.


int ccpnow(int arr[], int sum, int n){
    
    int dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    
    for(int j=1;j<=sum;j++)
        dp[0][j]=0;
        
    // Unbounded Knapsack, you have got the option of choosing the same element more than more, so, not decreasing its count after choosing it.
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}

int main(){

	fast
    
    int coins[] = { 1, 2, 3 };
    int sum = 4;
    int n = sizeof(coins) / sizeof(coins[0]); 
    cout << ccpnow(coins, sum, n); 

    return 0;
}
