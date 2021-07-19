// Idea is to push in all the routes if going from parent to child in positive and if opposite then in negative manner
// Then for the positive values one, count if the connection is a opposite one or not, if so then increase the count and change to positive

int dfs(int u, vector<vector<int>> &arr, vector<int> &visited){
    int cnt = 0;
    visited[u] = true;
    for(int i=0;i<arr[u].size();i++){
        if(visited[abs(arr[u][i])]==false){
            cnt+= dfs(abs(arr[u][i]), arr, visited) + (arr[u][i]>0);
        }
    }
    return cnt;
}

// There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.
// Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.
// This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
// Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach city 0 after reorder.

int minReorder(int n, vector<vector<int>>& a) {
    vector<vector<int>> arr(n);
    vector<int> visited(n, false);
    for(auto it : a){
        arr[it[0]].push_back(it[1]);
        arr[it[1]].push_back(-it[0]);
    }
    return dfs(0, arr, visited);
}