#include<bits/stdc++.h>
using namespace std;

// Initialise a two pointers denoting the start and end of the window
// j-i+1 gives us the lengtyh of the window
// Keep on increasing the sum
// When the size of k window is not HIT then only job is to increase j
// If its hit, then take the max/min of the sum 
// And our motive is to maintain that window so, decrease the starting arr[i] from sum and i++ and j++, to keep thw window

// TC : O(n)    
// SC : O(1)    

long solve(vector<int> arr, int k){
    long maxi = INT_MIN;
    int j=0, i=0;
    long sum=0;
    while(j<arr.size()){
        sum+=arr[j];
        if((j-i+1)<k) j++;
        else if((j-i+1)==k){
            maxi = max(maxi, sum);
            sum-=arr[i];
            i++;
            j++;
        }
    }
    return maxi;
}

int main(){

    // Find the maxi or minimum of k sized subarray sum

    // Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}, k = 4 
    // Output : 39

    vector<int> arr{1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;

    long ans = solve(arr, k);
    cout<<ans;

    return 0;
}