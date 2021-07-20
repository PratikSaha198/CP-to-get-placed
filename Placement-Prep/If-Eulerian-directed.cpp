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

void DFS(int u, vector<int> adj[], vector<int> &visited){
    visited[u]  = true;
    for(auto it : adj[u]){
        if(!visited[it])
            DFS(it, adj, visited);
    }
}

bool isConnected(int V, vector<int> adj[]){
    vector<int> visited(V, false);
    
    
}

void isEulerain(int V, vector<int> adj[]){

    // Check if Strongly Connected
    if(!isSC(V, adj)) cout<<"NOT EULERIAN";
    
    vector<int> in(V, 0), out(V, 0);

    for(int i=0;i<V;i++){
        out[i]+=adj[i].size();
        for(auto it : adj[i]){
            in[it]++;
        }
    }

    for(int i=0;i<V;i++)
        if(in[i] == out[i])

}

int main(){

	fast

    int V=5;
    vector<int> adj[V];

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);

    isEulerain(V, adj);
		
	return 0;
}