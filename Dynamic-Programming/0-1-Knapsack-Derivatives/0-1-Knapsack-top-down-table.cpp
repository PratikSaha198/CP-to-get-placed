#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;


// Storing of the recursive elements in this one, that prevents exponential time complexity.
// The things that are changing make a table with it +1 size;
// i -> n (elements) 
// j -> W (weights [ 0 -> W ])
// Each bottom cornermost element is the answer of that weight.
// The final column is the given W and is the answer asked. 


int kp(int wei[], int val[], int W, int n){
    
    int dp[n+1][W+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            
            if(i==0 || j==0)    
                dp[i][j]=0;
             
            else if(wei[i-1]<=j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wei[i-1]], dp[i-1][j]);
                
            else
                dp[i][j]=dp[i-1][j];    
            
        }
    }
    return dp[n][W];
}

int main(){

	fast
    
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << kp(wt, val, W, n); 
    return 0;
}
