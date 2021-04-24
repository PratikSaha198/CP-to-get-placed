#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;


// Given a rod of length L, and values associated with each small length, tell the max value but cutting any number of pieces.
// The lenghts associated array may sometimes be not given so 1->N of lengths should be considered.
// SAME AS Unbounded Knapsack, as any length of pieces can be cut multiple number of times.
// Just a fancey way of asking the Unbounded Knapsack problem (may have to sometimes initialise the lengths array from 1->N and then pass on to the function)


int ubks(int wei[], int val[], int W, int n){
    
    int dp[n+1][W+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            
            if(i==0 || j==0)
                dp[i][j] = 0;
                
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
    
    // Unbounded KS, just every length has length's value, which is given and you have to make an array of lengths
    int val[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int len = 8;
    int pie[8];
    for(int i=0;i<len;i++) pie[i]=i+1;
    cout<<ubks(pie, val, len, len);
    
	return 0;
}
