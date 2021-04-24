#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;


// Count the number of subsets that can be formed of the given sum provided.
// As count is asked it can be || and has to return an INT
// Base Conditions : if sum = 0, then just not choosing lead to correct answer, so always true i.e = 1
//                   if n = 0, then anything other than sum=0 can't be made, so always false i.e = 0
// Change || to + ans this OR that can be taken.

// TC : O(n * SUM)
// SC : O(n * SUM)


int css(int arr[], int sum, int n){
    
    int dp[n+1][sum+1];
    
    // If the sum is 0, then by just by not choosing, leads to correct answer and such 1 number of subset can be formed.
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    
    // If there are NO elements present then subsets cant be formed.
    for(int j=1;j<=sum;j++)
        dp[0][j]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){

            // Add the 2 AS OR operation and intially 1 is already provided in base case for backtracking stack.
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}

int main(){

	fast
    
    // Count the number of subsets that can be formed of the given sum provided.

    int arr[] = { 2, 3, 5, 6, 8, 10 };
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << css(arr, sum, n); 
    return 0;   
	
	return 0;
}