#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newnode(int val)
{
    Node *node = new Node();
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    if (left > right)
        return left + 1;
    else
        return right + 1;
}

void levelorder(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        levelorder(root->left, level - 1);
        levelorder(root->right, level - 1);
    }
}

void printlevel(Node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
        levelorder(root, i);
}

int main()
{

    Node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    printlevel(root);

    return 0;
}
