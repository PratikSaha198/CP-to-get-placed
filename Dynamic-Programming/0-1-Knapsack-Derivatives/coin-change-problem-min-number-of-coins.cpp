#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;


// Given some denominations and a SUM, output the minimum number of coins it requires that sum.
// BASE CONDITIONS : If sum is 0 and even if 1 or more coins are present then not choosing any makes sum 0
//                   If 0 no. of coins of any kind is there then infinite (INT_MAX-1) number of coins are required to make a sum.
//                   If 1 no. of coins of any kind is present then it can make a sum if and only if
//                   its a multiple of the sum, or else the sum can't be made and put INT_MAX-1
//                   Loop from 2 number of coins and in it 1 as sum till end of both.
//                   As minimum is asked and number of coins can be increased by one, as no value array is involved so +1 is done and min() function.
//                   As multiple items can be asked so Unbounded KS , dp[i-1][] -> dp[i][]


int ccpmnoc(int arr[], int sum, int n){
    
    int dp[n+1][sum+1];
    
    for(int i=1;i<=n;i++)
        dp[i][0]=0;
    
    for(int j=0;j<=sum;j++)
        dp[0][j]=INT_MAX-1;
        
    for(int j=1;j<=sum;j++){
        if(j%arr[0]==0)
            dp[1][j]=j/arr[0];
        else
            dp[1][j]=INT_MAX-1;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                dp[i][j] = min(1+dp[i][j-arr[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}

int main(){

	fast
    
    int coins[] = { 25, 10, 5 };
    int sum = 30;
    int n = sizeof(coins) / sizeof(coins[0]); 
    cout << ccpmnoc(coins, sum, n); 
    
    return 0;
}