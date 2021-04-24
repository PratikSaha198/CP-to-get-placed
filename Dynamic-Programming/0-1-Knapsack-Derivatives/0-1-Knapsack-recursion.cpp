#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;


// Base conditions are justified
// If the weight of an item is lesser than the weight available then it's not possible to take it in.
// Otherwise maximise the option of choosing or not choosing the item.  


// TC : O(2^n)
// SC : O(1)

int kp(int wei[], int val[], int W, int n){

    // If the weigts or the number of elements gets depleted then theres nothing to add.
    if(W==0 || n==0)
        return 0;

    // If the curr ele's weight is lesser than the WEIGHT AVAILABLE
    // Them we have got 2 options : Choose that, OR not choose it
    // Take the maximum of the two options (as maximise the value is required)
    if(wei[n-1]<=W)
        return max(val[n-1] + kp(wei, val, W-wei[n-1], n-1), kp(wei, val, W, n-1));

    // If the current weight is more than AVAILBLE then just move on to next one.
    else if(wei[n-1]>W)
        return kp(wei, val, W, n-1);
}

int main(){

	fast
    
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << kp(wt, val, W, n); 
    return 0;   
	
	return 0;
}
