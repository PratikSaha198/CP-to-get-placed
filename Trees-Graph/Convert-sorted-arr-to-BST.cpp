// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
// For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]

TreeNode* fuck(vector<int> ans, int f, int l)
{
    if (l <= f)
        return NULL;

    int mid = (f + l) / 2;
    
    TreeNode *root = new TreeNode(ans[mid]);
    
    root->left = fuck(ans, f, mid);
    root->right = fuck(ans, mid + 1, l);
    
    return root;
}

