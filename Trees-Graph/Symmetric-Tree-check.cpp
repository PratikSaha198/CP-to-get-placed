// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Therefore, the question is: when are two trees a mirror reflection of each other?
// Two trees are a mirror reflection of each other if:
// Their two roots have the same value.
// The right subtree of each tree is a mirror reflection of the left subtree of the other tree.

// Pass in the tree and itself again
// pass in the l and r in 2 ways with the condition of checking the values match or not


bool bal(TreeNode* t1, TreeNode* t2)
{
    if(!t1 and !t2) return true;
    else if(!t1 or !t2) return false;

    return t1->val==t2->val and bal(t1->left, t2->right) and bal(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root)
{
    return bal(root, root);
}