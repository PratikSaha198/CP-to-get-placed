// Each node may have a next larger value: for node_i, next_larger(node_i) is the node_j.val such that j > i, node_j.val > node_i.val, 
// and j is the smallest possible choice.  If such a j does not exist, the next larger value is 0.

// Return an array of integers answer, where answer[i] = next_larger(node_{i+1}).

// Input : [ 1, 7, 5, 1, 9, 2, 5, 1 ]
// Output : [ 7, 9, 9, 9, 0, 5, 0, 0 ]


// Take all elements from LL to ARRAY
// Go from right to left
// Delete all elements from stack till values are smaller than equal to the current element
// The stack is empty means no element is larger and convert to 0
// Else the only element left is the one greater to convert the original to that
// Keep on pushing the elements 


vector<int> nextLargerNodes(ListNode *head)
{
    vector<int> v;
    while (head)
    {
        v.push_back(head->val);
        head = head->next;
    }

    stack<int> s;
    
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int val = v[i];
        while (!s.empty() && s.top() <= v[i])
            s.pop();
        v[i] = s.empty() ? 0 : s.top();
        s.push(val);
    }
    
    return v;
}