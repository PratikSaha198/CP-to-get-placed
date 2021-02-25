// Given a balanced parentheses string S, compute the score of the string based on the following rule :

// () has score 1 
// AB has score A+B, where A and B are balanced parentheses strings.
// (A)has score 2 * A, where A is a balanced parentheses string.

// Input: "(()(()))"
// Output: 6


// Intuition and Algorithm --> STACK

// Every position in the string has a depth - some number of matching parentheses surrounding it. For example, the dot in (()(.())) has depth 2, because of these parentheses: (__(.__))

// Our goal is to maintain the score at the current depth we are on. When we see an opening bracket, we increase our depth, and our score at the new depth is 0. When we see a closing bracket, we add twice the score of the previous deeper part - except when counting (), which has a score of 1.

// For example, when counting (()(())), our stack will look like this:

// [0, 0] after parsing (
// [0, 0, 0] after (
// [0, 1] after )
// [0, 1, 0] after (
// [0, 1, 0, 0] after (
// [0, 1, 1] after )
// [0, 3] after )
// [6] after )

int scoreOfParentheses(string s)
{
    stack<int> st;
    st.push(0);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(0);
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a + max(2 * b, 1));
        }
    }
    return st.top();
}

// Time Complexity: O(N), where NN is the length of S.
// Space Complexity: O(N), the size of the stack.


// Intuition --> 

// The final sum will be a sum of powers of 2, as every core (a substring (), with score 1) 
// will have it's score multiplied by 2 for each exterior set of parentheses that contains that core.

// Algorithm

// Keep track of the balance of the string, as defined in Approach #1. 
// For every ) that immediately follows a (, the answer is 1 << balance, as balance is the number of exterior set of parentheses that contains this core.

int scoreOfParentheses(string s)
{
    int ans = 0, bal = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            bal++;
        else
        {
            bal--;
            if (s[i - 1] == '(')
                ans += 1 << bal;
        }
    }
    return ans;
}

// Time Complexity: O(N), where NN is the length of S.
// Space Complexity: O(1).