#include<bits/stdc++.h>
using namespace std;

// VARIABLE SIZED WINDOW, as the window was fixed before with the given k, but here k is a sum, and any sized window length can have it.
// Keep on maintaing a sum
// 3 cases arise, still not hit the sum, hit, and hit and passed
// If the sum is not hit then just keep on adding to it, thus j++
// If sum is hit the generate a probable answer and increase the size (j++)
// If the we have passed the sum, then keep on decreasing the sum and increasing the i (thus reducing window size), increase j too thereafter

int solve(vector<int> arr, int k){
    int ans = INT_MIN, sum=0;
    int i=0, j=0;
    while(j<arr.size()){
        sum+=arr[j];
        if(sum<k) j++;
        else if(sum==k){
            ans = max(ans, j-i+1);
            j++;
        }
        else{
            while(sum>k){
                sum-=arr[i];
                i++;
            }
            j++;
        }
    }
    return ans;
}

// TC : O(n)    
// SC : O(1)    

int main(){

    // Find the longest sized subarray having sum k

    // Input  : arr[] = {4, 1, 1, 1, 2, 3, 5}, k = 5
    // Output : 

    vector<int> arr{4, 1, 1, 1, 2, 3, 5};
    int k = 5;

    int ans = solve(arr, k);
    cout<<ans;

    return 0;
}