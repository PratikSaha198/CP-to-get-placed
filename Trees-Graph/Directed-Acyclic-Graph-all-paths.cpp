// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, and return them in any order.
// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

void dfs(vector<vector<int>> &graph, vector<vector<int>> &answer, vector<int> path, int curr)
{
    path.push_back(curr);
    if (curr == graph.size() - 1)
        answer.push_back(path);
    else
    {
        for (auto it : graph[curr])
            dfs(graph, answer, path, it);
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> answer;
    vector<int> path;
    int src = 0;
    dfs(graph, answer, path, src);
    return answer;
}