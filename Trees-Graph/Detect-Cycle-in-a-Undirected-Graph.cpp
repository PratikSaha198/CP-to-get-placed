#include <bits/stdc++.h>
using namespace std;


// Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
// Union : Join two subsets into a single subset.
// Watch ABDUL BARI video to understand the use of union and find to do it : https://www.youtube.com/watch?v=wU6udHRIkcc
// O( n ) worst case.


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
    vector<int> pa(E + 1, -1);
    for (int i = 0; i < V; i++)
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
    for (int i = 0; i < V; i++)
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
