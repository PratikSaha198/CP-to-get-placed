#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Find the min and max distances wrt the root
void findMinMax(Node *root, int &min, int &max, int dist){
    if(!root) return;
    
    if(max < dist) max = dist;
    else if(dist < min) min = dist;

    // Going to left means dist-1 as its wrt to root's position
    findMinMax(root->left, min, max, dist-1);
    findMinMax(root->right, min, max, dist+1);
}

// Print the node according to the vertical dist of it
void printVertical(Node *root, int lineno, int dist){
    if(!root) return;

    if(lineno == dist) cout<<root->data<<" ";

    printVertical(root->left, lineno, dist-1);
    printVertical(root->right, lineno, dist+1);
}

void verticalOrder(Node* root){
    int min=0, max=0;

    // Find the max and min vertical distances from the root
    findMinMax(root, min, max, 0);

    // Iterate over the range of max and min distances and print
    for(int i=min;i<=max;i++){
        printVertical(root, i, 0);
        cout<<endl;
    }
}

// Using map to store the values of a certain distant vertical order
void verticalOrderOpti(Node *root, int dist, map<int, vector<int>> &m){
    if(!root) return;

    m[dist].push_back(root->data);

    verticalOrderOpti(root->left, dist-1, m);
    verticalOrderOpti(root->right, dist+1, m);
}

// Printing all the elements in that vertical order
void printVerticalOpti(Node *root){
    map<int, vector<int>> m;
    verticalOrderOpti(root, 0, m);

    for(auto it : m){
        for(auto itr : it.second){
            cout<<itr<<" ";
        }
        cout<<endl;
    }
}

int main(){

    fast

    // Vertical Order Traversal of a Binary tree 
    // O(n*width) ~ O(n2)

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    verticalOrder(root);
    cout<<endl;
    printVerticalOpti(root);

    return 0;
}