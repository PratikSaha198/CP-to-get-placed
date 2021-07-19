#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double
#define INF INT_MAX

using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w){
    adj[u].push_back({v, w});
}

void topoSort(int u, vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &st){
    visited[u] = true;
    for(int i=0;i<adj[u].size();i++){
        if(visited[adj[u][i].first] == false)
            topoSort(adj[u][i].first, adj, visited, st);
    }
    st.push(u);
}

void shortestPath(int V, vector<pair<int, int>> adj[], int s){
    stack<int> st;
    vector<int> dist(V, INF);
    vector<int> visited(V, false);

    for(int u=0;u<V;u++){
        if(visited[u]==false)
            topoSort(u, adj, visited, st);
    }

    dist[s] = 0;

    while(!st.empty()){
        int u = st.top();
        st.pop();

        // Update the value, if 
        // Taking this current path is a lower weight than the existing weight it takes to reach it

        if(dist[u]!=INF){
            for(int i=0;i<adj[u].size();i++){
                if(dist[adj[u][i].first] > dist[u]+adj[u][i].second)
                    dist[adj[u][i].first] = dist[u]+adj[u][i].second;
            }
        }
    }

    for(int u=0;u<V;u++){
        (dist[u] == INF)?cout<<"INF ":cout<<dist[u]<<" ";
    }
}

int main(){

	fast

    int V=6;
    vector<pair<int, int>> adj[V];

    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 3);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 4, 4);
    addEdge(adj, 2, 5, 2);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 3, 4, -1);
    addEdge(adj, 4, 5, -2);

    int s=1;
    shortestPath(V, adj, s);
        
	return 0;
}