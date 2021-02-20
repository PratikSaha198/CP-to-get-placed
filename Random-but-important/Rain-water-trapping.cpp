// DP : 
// O( N^2 ) : Space ccomplexity ~ O( N )

// Algorithm
// Find maximum height of bar from the left end upto an index i in the array left_max.
// Find maximum height of bar from the right end upto an index i in the array right_max.
// Iterate over the min(left_max[i], right_max[i]) − height[i] to ans

int trap_dp(vector<int> &height)
{
    if (height.size() == 0)
        return 0;
    int sh = height.size();
    vector<int> lefth(sh), righth(sh);
    lefth[0] = height[0];
    for (int i = 1; i < sh; i++)
    {
        lefth[i] = max(height[i], lefth[i - 1]);
    }
    righth[sh - 1] = height[sh - 1];
    for (int i = sh - 2; i >= 0; i--)
    {
        righth[i] = max(height[i], righth[i + 1]);
    }
    int ans = 0;
    for (int i = 1; i < sh - 1; i++)
    {
        ans += min(lefth[i], righth[i]) - height[i];
    }
    return ans;
}

// USING TWO POITNTERS

int trap_two_pointer(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int lmax = 0, rmax = 0;
    while (left < right)
    {
        if (height[left] < height[right])
        {
            height[left] >= lmax ? lmax = height[left] : ans += lmax - height[left];
            left++;
        }
        else
        {
            height[right] >= rmax ? rmax = height[right] : ans += rmax - height[right];
            right--;
        }
    }
    return ans;
}