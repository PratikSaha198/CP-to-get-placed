void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root.
// When you select a node x as the root, the result tree has height h.
// Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
// Return a list of all MHTs' root labels. You can return the answer in any order.
// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

// Input: n = 4, edges = [[1,0],[1,2],[1,3]]
// Output: [1]

// Basic idea: the roots of MHT must be the mid points of the longest leaf to leaf path in the tree.
// And to find the longest path, we can first find the farthest leaf from any node, and then find
// the farthest leaf from the node found above. Then these two nodes we found are the end points
// of the longest path. And last, we find the centers of the longest path.

// 1.Create adjcent list(neighbors)
// 2.Count in-degree of all vertices.
// 3.Pick any vertex 'v' which has in-degree of 0.
// 4.Print 'v'. Remove the vertex 'v' and all edges coming out of it. Decrement in-degrees of all neighbors of vertex 'v' by 1.
// 5.Repeat steps 3 and 4 till u either have just 1 or 2 nodes available.

vector<int> findMinHeightTrees(int V, vector<vector<int>> &edges)
{

    if (V == 0)
        return {};
    if (V == 1)
        return {0};

    vector<int> adj[V];
    for (auto it : edges)
    {
        addEdge(adj, it[0], it[1]);
    }

    vector<int> ans;
    vector<int> degree(V, 0);
    for (auto it : edges)
    {
        degree[it[0]]++;
        degree[it[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (degree[i] == 1)
            q.push(i);

    while (!q.empty())
    {
        ans.clear();
        int si = q.size();
        for (int i = 0; i < si; i++)
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (auto it : adj[curr])
            {
                degree[it]--;
                if (degree[it] == 1)
                    q.push(it);
            }
        }
    }
    return ans;
}