#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;


// Count how many subsets can be made with the given difference 
// OR (can also be framed as)
// Just by placing positive or negative signs on each element how many ways can you get subsets with given difference.
// Diff + Sum = 2*j -> so you have to just have to find Count of SubsetSum of j.


int cgssd(int arr[], int diff, int n){

    int sum = 0;
    for(int i=0;i<n;i++) 
        sum+=arr[i];
    
    int s = (diff+sum)/2;
    
    int dp[n+1][s+1];
    
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;

    for(int j=1;j<=s;j++)
        dp[0][j] = 0;
        
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[n][s];
    
}

int main(){

	fast
    
    int arr[] = { 1, 1, 2, 3 };
    int diff = 1;
    int N = 4;
    cout<<cgssd(arr, diff, N);
    
	return 0;
}
