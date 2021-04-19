// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

// Input: low = 100, high = 300
// Output: [123,234]

// Maintain a queue where {1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 23, 34, 45, 56, 67, 78, 89, 123, ...}


vector<int> sequentialDigits(int low, int high)
{
    queue<int> q{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    vector<int> ans;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
    
        if(curr > high)
            break;
        if(curr>=low and curr<=high)
            ans.push_back(curr);
        
        int rem = curr%10;
        int num = curr*10 + (rem+1);
        
        if(rem<9)
            q.push(num);
    }

    return ans;
}