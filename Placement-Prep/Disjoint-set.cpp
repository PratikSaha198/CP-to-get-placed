#include <bits/stdc++.h>
using namespace std;

int arr[10];
int parent[10];
int sizes[10];

void makeset(int a)
{
    parent[a] = a;
    sizes[a] = 1;
}

int leader(int i)
{
    if (i == parent[i])
        return i;
    parent[i] = leader(parent[i]);
    return parent[i];
}

void connect(int i, int j)
{
    int a = leader(i);
    int b = leader(j);
    if (a != b)
    {
        //when both leaders are not equal

        if (sizes[a] < sizes[b])
        {
            swap(a, b);
        }
        //cout<<"connected "<<a<<","<<b<<endl;
        //a>b proof till now
        parent[b] = a;
        sizes[a] = sizes[a] + sizes[b];
        arr[a] += arr[b];
        // cout<<"value "<<arr[a]<<endl;
        // cout<<"size "<<sizes[a]<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ok;
        cin >> ok;
        arr[i] = ok;
        makeset(i);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u;
        if (u == 0)
        {
            cin >> v;
            //who is the leader of a component
            cout << leader(v);

            // what is the sum of all the nodes in the component containing this node
            //cout<<arr[leader(v)];
        }
        if (u == 1)
        {
            cin >> v;
            cout << sizes[leader(v)];
            //print
        }
        if (u == 2)
        {
            // add another node
            cin >> v;
            arr[n] = v;
            makeset(n);
            n++;
        }
        if (u == 3)
        {
            //connect two nodes
            int a, b;
            cin >> a >> b;
            connect(a, b);
        }
        if (u == 4)
        {
            cin >> v;
            int wow = leader(v);
            cout << "leader : " << wow << endl;
            cout << arr[wow];
        }
    }
}