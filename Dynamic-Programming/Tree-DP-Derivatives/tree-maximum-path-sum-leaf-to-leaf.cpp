#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Same as maximum path sum but, only constraint is that it needs to be from a leaf node to another leaf node.
// Check if the node is a leaf node, if it is then only take the maximum of choosing just that node and the already choosen that node plus the maximum of left/right subtree.


struct Node
{
    int val;
    Node *left, *right;
};

struct Node *newNode(int val)
{
    struct Node *node = new Node;
    node->val = val;
    node->left = node->right = NULL;
    return (node);
}

int MPS(Node *root, int &res)
{
    if (root == NULL)
        return 0;

    int l = MPS(root->left, res);
    int r = MPS(root->right, res);

    int temp = max(l, r) + root->val;

    if (root->left == NULL && root->right == NULL)
        temp = max(temp, root->val);

    int ans = max(temp, l + r + root->val);
    res = max(res, ans);
    return temp;
}

int maxPathSum(Node *root)
{
    int ans = INT_MIN;
    MPS(root, ans);
    return ans;
}

int main()
{

    fast

    struct Node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right = newNode(0);
    root->right->right->right->left = newNode(4);
    root->right->right->right->right = newNode(-1);
    root->right->right->right->right->left = newNode(10);
    cout << maxPathSum(root);

    return 0;
}
