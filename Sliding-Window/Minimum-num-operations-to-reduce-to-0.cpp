// You are given an integer array nums and an integer x. 
// In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x.
// Note that this modifies the array for future operations.

// Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

// Rather than finding this we can find the sum(nums)-x = SUM, this SUM is to be found, and we find this window
// If the curr sum is less than the required then increase the sum
// Else keep on decreasing from the starting of the window

int minOperations(vector<int>& nums, int x) {
    int sum = accumulate(nums.begin(), nums.end(), 0) - x;
    cout<<sum;
    if(sum<0) return -1;
    if(sum==0) return nums.size();
    int i=0, j=0, len = -1, curr = 0;
    while(j<nums.size()){
        if(curr<sum) curr+=nums[j];
        while(curr>=sum){
            if(curr==sum) len = max(len, j-i+1);
            curr-=nums[i];
            i++;
        }
        j++;
    }
    return (len==-1)?-1:nums.size()-len;
}