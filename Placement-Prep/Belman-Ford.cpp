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

void bellManFord(int V, vector<pair<int, int>> adj[], int sr){
    vector<int> dist(V, INT_MAX);
    dist[sr] = 0;
    
    for(int u=1;u<=V-1;i++){
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if(dist[v]>dist[u]+weight and dist[v]!=INT_MAX)
                dist[v] = dist[u]+weight;
        }
    }

    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i].first;
        int weight = adj[u][i].second;
        if(dist[v]>dist[u]+weight and dist[v]!=INT_MAX)
            
    }
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