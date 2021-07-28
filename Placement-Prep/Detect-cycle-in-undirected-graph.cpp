#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfs(int u, vector<int> adj[], vector<int> &visited, int parent){
    visited[u] = true;
    for(int i=0;i<adj[u].size();i++){
        if(visited[adj[u][i]] == false){
            if(dfs(adj[u][i], adj, visited, u))
                return true;
        }
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if(adj[u][i]!=parent) 
            return true;
    }
    return false;
}

bool detect(int V, vector<int> adj[]){
    vector<int> visited(V, false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(dfs(i, adj, visited, -1))
                return true;
        }
    }
    return false;

    // To find the node making it a cycle
    // Keep on adding an edge one by one and test, 
    // Check if there is a back edge to any if its nodes, then a cycle is being formed
    // If its being formed then the vertice before that was the culprit
}

int main(){

	fast

	int V=5;
    vector<int> adj[V];

    // undirected graph

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);

    if(detect(V, adj)) cout<<"CYCLE PRESENT";
    else cout<<"NOT PRESENT";
		
	return 0;
}