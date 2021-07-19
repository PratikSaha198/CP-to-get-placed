bool solve(int u, vector<vector<int>> &graph, vector<int> &visited, vector<int> &path){
    visited[u] = true;
    
    // For the current state of the path
    bool state = false;

    // The starting node is a cycle
    path[u] = true;
    for(auto it : graph[u]){

        // If its adjacent is true it means its a part of cycle
        if(path[it]) return true;

        // Else check normal and if any node in the path is a part of cycle then keep it in state
        if(visited[it]==false)
            state|=solve(it, graph, visited, path);

        // Check state
        if(state) return true;
    }

    // The current node is turned to false
    path[u] = false;

    // Returns the state
    return state;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ans;
    int n=graph.size();

    // A path vector to store the state of the path currently in 
    vector<int> visited(n, false), path(n, false);

    // Check for each vertice if it falls in a cycle or not
    // The solve function detects cyclicity
    for(int i=0;i<n;i++){
        if(!solve(i, graph, visited, path))
            ans.push_back(i);
    }
    return ans;
}