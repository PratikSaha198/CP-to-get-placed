#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;


// Show if the given sum can be made using the numbers provided.
// Base Conditions : if sum = 0, then just not choosing lead to correct answer, so always true
//                   if n = 0, then anything other than sum=0 can't be made, so always false.
// True / False is output so bool function with option of choosing OR not choosing so ||


bool ss(int arr[], int sum, int n){
    
    bool dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    
    for(int j=1;j<=sum;j++)
        dp[0][j]=false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}

int main(){

	fast
    
    int arr[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 9; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << ss(arr, sum, n); 
    return 0;   
	
	return 0;
}