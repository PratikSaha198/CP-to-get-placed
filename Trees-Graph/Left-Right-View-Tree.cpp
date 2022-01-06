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

void printUtil(Node* root, int level, int &max_level){
    if(!root) return;
    if(max_level < level){
        cout<<root->data<<" ";
        max_level = level;
    }
    // Swwp the left and right for right view instead
    printUtil(root->left, level+1, max_level);
    printUtil(root->right, level+1, max_level);
}

void printLeftView(Node* root){
    int max_level = 0;
    printUtil(root, 1, max_level);
}

int main()
{

    Node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    printLeftView(root);

    return 0;
}
