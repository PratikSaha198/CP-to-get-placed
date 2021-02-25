#include <bits/stdc++.h>
using namespace std;


// Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
// Union : Join two subsets into a single subset.
// Watch ABDUL BARI video to understand the use of union and find to do it : https://www.youtube.com/watch?v=wU6udHRIkcc
// O( n ) worst case.


// 0-1-2 in a circle

//For each edge, make subsets using both the vertices of the edge. If both the vertices are in the same subset, a cycle is found.
// Initially, all slots of parent array are initialized to -1 (means there is only one item in every subset).

// 0   1   2
// -1 -1  -1
// Now process all edges one by one.
// Edge 0-1: Find the subsets in which vertices 0 and 1 are. Since they are in different subsets, we take the union of them. For taking the union, either make node 0 as parent of node 1 or vice-versa. 

// 0   1   2    <----- 1 is made parent of 0 (1 is now representative of subset {0, 1})
// 1  -1  -1
// Edge 1-2: 1 is in subset 1 and 2 is in subset 2. So, take union.

// 0   1   2    <----- 2 is made parent of 1 (2 is now representative of subset {0, 1, 2})
// 1   2  -1
// Edge 0-2: 0 is in subset 2 and 2 is also in subset 2. Hence, including this edge forms a cycle.
// How subset of 0 is same as 2? 
// 0->1->2 // 1 is parent of 0 and 2 is parent of 1

int E, V;

int findit(vector<int> &pa, int x)
{
    if (pa[x] == -1)
        return x;
    return findit(pa, pa[x]);
}

void unionit(vector<int> &pa, int x, int y)
{
    int xs = findit(pa, x);
    int ys = findit(pa, y);
    pa[x] = y;
}

int iscycle(vector<pair<int, int>> &v)
{
    vector<int> pa(V + 1, -1);
    for (int i = 0; i < E; i++)
    {
        int a = findit(pa, v[i].first);
        int b = findit(pa, v[i].second);
        if (a == b)
            return 1;
        unionit(pa, a, b);
    }
    return 0;
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
    if (iscycle(v))
        cout << "PRESENT";
    else
        cout << "NOT PRESENT";

    return 0;
}
