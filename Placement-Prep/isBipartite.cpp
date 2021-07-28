#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

bool dfs(int u, vector<int> adj[], vector<int> &visited, vector<int> &color){
    visited[u] = true;
    for(auto it : adj[u]){
        if(!visited[it]){
            visited[it] = true;

            // Changes to opposite color 
            color[it] = !color[u]; 
            
            if (dfs(it, adj, visited, color))
                return true;
        }
        else if(color[it] == color[u])
            return true;
    }
    return false;
}

bool isBipartite(int V, vector<int> adj[]){
    vector<int> visited(V, false);
    vector<int> color(V);

    color[0] = 1;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(i, adj, visited, color))
                return false;
        }
    }
    return true;
}

int main(){

	fast

    // int V = 6;
	// vector<int> adj[V];

    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 4);
    // addEdge(adj, 4, 5);
    // addEdge(adj, 5, 0);

    int V = 5;
	vector<int> adj[V];

    addEdge(adj, 0, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 3);
    addEdge(adj, 4, 0);

    if(isBipartite(V, adj)) cout<<"YES";
    else cout<<"NO";    

    return 0;
}