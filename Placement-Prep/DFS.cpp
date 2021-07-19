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

void dfsUtil(int u, vector<int> adj[], vector<int> &visited){
	visited[u] = true;
	cout<<u<<" ";

	for(int i=0;i<adj[u].size();i++){
		if(visited[adj[u][i]]==false)
			dfsUtil(adj[u][i], adj, visited);
	}
}

void DFS(vector<int> adj[], int V){
    
	vector<int> visited(V, false);
	for(int u=0;u<V;u++){
		if(visited[u]==false)
			dfsUtil(u, adj, visited);
	}
}

int main(){

	fast

    int V=5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

	DFS(adj, V);
	
	return 0;
}