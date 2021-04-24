#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;


// Similar to 0-1 Knapsack but you have got a option of choosing the same element more than once.
// In 0-1 Knapsack once you call on n, then next time you call on n-1, even if you don't take
// that element into consideration stil you move over to next n-1 elements, but here you again have
// can take the same element if you have already taken it, that's why dp[i-1][] -> dp[i][]. 
// Everything else same as 0-1 KS
// Thumb rule for multiple times same thing choosing is i-1 to i.
    

int ubks(int wei[], int val[], int W, int n){
    
    int dp[n+1][W+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            
            if(i==0 || j==0)
                dp[i][j] = 0;
                
            // If you are choosing an element then you have the option of choosing it again, so dont decrease the count, else decrease.
            else if(wei[i-1]<=j)
                dp[i][j]=max(val[i-1]+dp[i][j-wei[i-1]], dp[i-1][j]);
            
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[n][W];
    
}

int main(){

	fast
    
    // Same as knapsack, but you have the option of choosing the same element more than once.
    int wei[] = { 1, 50 };
    int val[] = { 1, 30 };
    int N = 2;
    int weight = 100;
    cout<<ubks(wei, val, weight, N);
    
	return 0;
}
