// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1.
// Find the area of largest rectangle in the histogram.

// Input : [ 2, 1, 5, 6, 2, 3 ]
// Output : 10

// Store the widhths
// If the current height is grater than the previous one then increase the width.
// Else the previous element * width (i - s.top() - 1) is taken as area when the stack is empty else that index*height of prevoius one is taken.

int largestRectangleArea(vector<int> &heights)
{
    heights.push_back(0);
    int h = heights.size();
    int i = 0, maxi = 0;
    stack<int> s;
    while (i < h)
    {
        if (s.empty() || heights[i] >= heights[s.top()])
            s.push(i++);
        else
        {
            int hei = s.top();
            s.pop();
            maxi = max(maxi, heights[hei] * (s.empty() ? i : i - s.top() - 1));
        }
    }
    return maxi;
}

