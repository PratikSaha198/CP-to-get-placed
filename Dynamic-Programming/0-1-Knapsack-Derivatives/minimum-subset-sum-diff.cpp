#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;


// To minimise( Diff ) = TotalSum - 2*j , j is any sum lesser than equal to half of TotalSum, so have to maximise it.
// Same as Subset Sum problem do the table.
// In the end n, that is after choosing all the elements in the array, go from half of it to 0.
// The highest valued j having a True value, is he required j. Giving us the minimum difference.


int minssd(int arr[], int n){
    
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    
    int dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    
    for(int j=1;j<=sum;j++)
        dp[0][j]=false;
        
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    
    int mini = INT_MAX;
    
    for(int j=sum/2;j>=0;j--){
        if(dp[n][j]==true){
            mini = sum - 2*j;
            break;
        }
    }
    
    return mini;
    
}

int main(){

    fast
    
    int arr[] = { 1, 5, 6, 11 };
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << minssd(arr, n); 
    return 0;   
    
    return 0;
}
