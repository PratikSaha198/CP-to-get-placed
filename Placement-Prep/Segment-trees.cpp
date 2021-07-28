#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;

int getMid(int l, int r){
    return l + (r-l)/2;
}

int buildSTUtil(int arr[], int l, int r, int *st, int curr){

    // If l and r are same then its a leaf and 
    if(l==r){
        st[curr] = arr[l];
        return arr[l];
    }

    // Recur the left subtree and right subtree and then put it in the segment tree
    int mid = getMid(l, r);
    st[curr] = buildSTUtil(arr, l, mid, st, curr*2 + 1) + buildSTUtil(arr, mid+1, r, st, curr*2 + 2);
    return st[curr];
}

int *buildST(int n, int arr[]){

    // Allocating the size
    int x = (int)(ceil(log2(n)));

    int maxsize = 2*(int)pow(2, x) - 1;

    int *st = new int[maxsize];

    buildSTUtil(arr, 0, n-1, st, 0);

    return st;
}

int getSumUtil(int *st, int l, int r, int i, int j, int curr){

    // If the search is totally inside then just return the current node
    if(i<=l && j>=r) return st[curr];

    // If out of counds then return 0
    if(r<i || l>j) return 0;

    // Else compute going to both nodes
    int mid = getMid(l, r);

    return getSumUtil(st, l, mid, i, j, curr*2 + 1) + getSumUtil(st, mid+1, r, i, j, curr*2 + 2);
}

int getSum(int *st, int n, int i, int j){
    
    // Handle the out of bounds input
    if(i<0 || j>n-1 || i>j){
        cout<<"INVALID INPUT"<<endl;
        return -1;
    } 

    return getSumUtil(st, 0, n-1, i, j, 0);
}

void getUpdateUtil(int *st, int l, int r, int index, int value, int curr){

    if(index<l || index>r) return;

    st[curr] = value;
    if(l!=r){
        int mid = getMid(l, r);
        getUpdateUtil(st, l, mid, index, value, curr*2 + 1);
        getUpdateUtil(st, mid+1, r, index, value, curr * 2 + 2);
    }
}

void getUpdate(int arr[], int *st, int n, int index, int value){
    
    if(index<0 || index>n-1){
        cout<<"INVALID INPUT"<<endl;
        return;
    }

    arr[index] = value;

    getUpdateUtil(st, 0, n-1, index, value, 0);
}

int main(){

	fast

    // O(log n) for both 

	int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *st = buildST(n, arr);

	cout<<getSum(st, n, 1, 3)<<endl;

    getUpdate(arr, st, n, 1, 10);

    cout<<getSum(st, n, 1, 3)<<endl;

	return 0;
}