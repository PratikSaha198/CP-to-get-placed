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
    
    bool dp[n+1][sum+1];
    
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
    
    // 2 seperate subset sums have to be formed and you have to find the min difference possible.
    // Minimum differnece is possible is both the sums are as cloase to each other as possible

    // Therefore form the subset sum, bool 2D matrix and in the last row where all elements are available
    // Check from just lesser than half tyhe total SUM, that is the answer after SUM-2*j
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
