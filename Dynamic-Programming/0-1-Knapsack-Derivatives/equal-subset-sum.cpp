#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;
	

// Given an array -> True/False if you can divide into two subsets with equal sum.
// If equal sum is asksed then has to be an EVEN number, so if total sum is not even -> answer is false.
// Else find if the other half is present -> question conveted to subset sum -> YES or NO.


bool ss(int arr[], int sum, int n){
    
    bool dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    
    for(int j=1;j<=sum;j++)
        dp[0][j]=false;
        
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}

bool ess(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    if(sum%2!=0)
        return false;
    else
        return ss(arr, sum/2, n);
}

int main(){

	fast
    
    int arr[] = { 1, 5, 11, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << ess(arr, n); 
    return 0;   
	
	return 0;
}