// Given a string containing just the characters '(' and ')'
// Find the length of the longest valid (well-formed) parentheses substring.

// Algorithm : Without extra space

// In this approach, we make use of two counters left and right.
// First, we start traversing the string from the left towards the right and for every '(' encountered, we increment the leftleft counter and for every ')' encountered, we increment the right counter.
// Whenever left becomes equal to right, we calculate the length of the current valid string and keep track of maximum length substring found so far.
// If right becomes greater than left we reset left and right to 0.
// Next, we start traversing the string from right to left and similar procedure is applied.

int longestValidParentheses(string s)
{
    if (s.length() <= 1)
        return 0;
    int left = 0, right = 0;
    int maxi = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            left++;
        else
            right++;
        if (left == right)
            maxi = max(maxi, 2 * right);
        else if (right >= left)
            left = right = 0;
    }
    left = 0;
    right = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            left++;
        else
            right++;
        if (left == right)
            maxi = max(maxi, 2 * left);
        else if (left >= right)
            left = right = 0;
    }
    return maxi;
}