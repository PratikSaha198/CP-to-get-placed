#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given a binary tree with nodes as positive or negative numbers, OUTPUT the max sum possible in a tree's path (can be from any node to any category of node, no bindings)
// Same concept as Diameter of a tree, the maximum sum path can pass through a node or not pass through a node.
// If passes then store the left + right + that value, else store the maximum of either choosing only that node OR choosing the maximum of any subtree + that node.
// Format same as diameter of a tree.


struct Node
{
    int val;
    Node *left, *right;
};

struct Node *newnode(int val)
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

    int temp = max(max(l, r) + root->val, root->val);
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

    struct Node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);

    cout << maxPathSum(root);

    return 0;
}
