#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v ,int w){
    adj[u].push_back({v, w});
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm.  The function
// also detects negative weight cycle
void bellManFord(int V, vector<pair<int, int>> adj[], int sr){

    // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    vector<int> dist(V, INT_MAX);
    dist[sr] = 0;

    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1
    // edge
    for(int i=1;i<=V-1;i++){
        for(int u=0;u<V;u++){
            for(auto it : adj[u]){
                int v = it.first;
                int weight = it.second;
                if(dist[u]!=INT_MAX and dist[v]>dist[u]+weight)
                    dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for(int u=0;u<V;u++){
        for(auto it : adj[u]){
            int v = it.first;
            int weight = it.second;
            if(dist[u]!=INT_MAX and dist[v]>dist[u]+weight){
                cout<<"NEGATIVE CYCLE";
                return;
            }
        }
    }

    // Print the distances
    for(auto it : dist) cout<<it<<" ";
}

int main(){

	fast

	int V=5, E=8;
    vector<pair<int, int>> adj[V];

    addEdge(adj, 0, 1, -1);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 2);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 3, 2, 5);
    addEdge(adj, 3, 1, 1);
    addEdge(adj, 4, 3, -3);

    int sr=0;
    bellManFord(V, adj, sr);

	return 0;
}