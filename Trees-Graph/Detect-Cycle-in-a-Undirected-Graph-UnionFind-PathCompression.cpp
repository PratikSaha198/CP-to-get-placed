#include <bits/stdc++.h>
using namespace std;

// The above union() and find() are naive and the worst case time complexity is linear. 
// The trees created to represent subsets can be skewed and can become like a linked list.

//  This technique is called union by rank. The term rank is preferred instead of height because if path compression technique (we have discussed it below) is used, then rank is not always equal to height. Also, size (in place of height) of trees can also be used as rank. Using size as rank also yields worst case time complexity as O(Logn) (See this for proof)
// Let us see the above example with union by rank
// Initially, all elements are single element subsets.
// 0 1 2 3 

// Do Union(0, 1)
//    1   2   3  
//   /
//  0

// Do Union(1, 2)
//    1    3
//  /  \
// 0    2

// Do Union(2, 3)
//     1    
//  /  |  \
// 0   2   3
// The second optimization to naive method is Path Compression. The idea is to flatten the tree when find() is called. When find() is called for an element x, root of the tree is returned. The find() operation traverses up from x to find root. The idea of path compression is to make the found root as parent of x so that we don’t have to traverse all intermediate nodes again. If x is root of a subtree, then path (to root) from all nodes under x also compresses.

// Let the subset {0, 1, .. 9} be represented as below and find() is called
// for element 3.
//               9
//          /    |    \  
//         4     5      6
//      /     \        /  \
//     0        3     7    8
//             /  \
//            1    2  

// When find() is called for 3, we traverse up and find 9 as representative
// of this subset. With path compression, we also make 3 as the child of 9 so 
// that when find() is called next time for 1, 2 or 3, the path to root is reduced.

//                9
//          /    /  \    \
//         4    5    6     3 
//      /           /  \   /  \
//     0           7    8  1   2
// The two techniques complement each other. The time complexity of each operation becomes even smaller than O(Logn). In fact, amortized time complexity effectively becomes small constant.


int E, V;

int findit(vector<pair<int, int>> &subsets, int x)
{
    if (subsets[x].first != x)
        subsets[x].first = findit(subsets, subsets[x].first);
    return subsets[x].first;
}

void unionit(vector<pair<int, int>> &subsets, int x, int y)
{
    int xr = findit(subsets, x);
    int yr = findit(subsets, y);
    if (subsets[xr].second < subsets[yr].second)
        subsets[xr].first = yr;
    else if (subsets[xr].second > subsets[yr].second)
        subsets[yr].first = xr;
    else
    {
        subsets[yr].first = xr;
        subsets[xr].second++;
    }
}

bool isCycle(vector<pair<int, int>> &v)
{
    vector<pair<int, int>> subsets;
    for (int i = 0; i < V; i++)
    {
        subsets.push_back({i, 0});
    }
    for (int i = 0; i < E; i++)
    {
        int a = findit(subsets, v[i].first);
        int b = findit(subsets, v[i].second);
        if (a == b)
            return true;
        unionit(subsets, a, b);
    }
    return false;
}

int main()
{
    cin >> E >> V;
    vector<pair<int, int>> v;
    int a, b;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    if (isCycle(v))
        cout << "PRESENT";
    else
        cout << "NOT PRESENT";
    return 0;
}
