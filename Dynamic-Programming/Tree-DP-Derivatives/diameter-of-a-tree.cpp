#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long
#define ull unsigned long long
#define ld long double

using namespace std;


// Given a binary tree, output the maximum nunber of nodes in the longest path that can be formed between any two leaves. 

// Each node has to be looked upon and figured out the diameter. A choosen node which is a root can have the path going through them or not.
// 1 + Left height + right height gives the diameter of a node, recursively store the max height of each node and store the max diameter.

struct Node
{
    int data;
    Node *left, *right;
};

struct Node *newnode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int dia(TreeNode *root, int &res)
{
    if (root == NULL)
        return 0;

    int l = dia(root->left, res);
    int r = dia(root->right, res);

    int temp = 1 + max(l, r);
    int ans = max(temp, 1 + l + r);
    res = max(res, ans);

    return temp;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int ans = 1;
    dia(root, ans);
    return ans - 1;
}

int main()
{

    fast

    struct Node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    cout << diameterOfBinaryTree(root);

    return 0;
}
