#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v ,int w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void shortestPath(int V, vector<pair<int, int>> adj[], int s){

    // Set of weight, vertice to keep track of the one with minimum weight
    set<pair<int, int>> st;

    // Distances/weights of the vertices to be reached through, initially all are infinity
    vector<int> dist(V, INT_MAX);

    // Insert the starting node and set the distance to itself to be 0
    st.insert({0, s});
    dist[s] = 0;

    // For all the nodes in the set
    while(!st.empty()){

        // Get the current one
        pair<int, int> p = *(st.begin());
        st.erase(st.begin()); 

        // Get the current vertice
        int u = p.second;

        // Loop over its elements
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            // If there is a shorter path to V through u
            if(dist[v] > dist[u]+weight){

                // Delete the current one in the set and add the updated one
                if(dist[v]!=INT_MAX) st.erase(st.find({dist[v], v}));
                dist[v] = dist[u]+weight;
                st.insert({dist[v], v});
            }
        }
    }

    // For all verices, print the corresponding distances
    for(int u=0;u<V;u++){
        cout<<u<<" -> "<<dist[u]<<endl;
    }
}

int main(){

	fast

    // O(V + E*log(E))
    // because
    // the algorithm goes through all nodes in the graph and adds for each edge at most
    // one distance to the priority queue.
    
	int V=9;
    vector<pair<int, int>> adj[V];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    int s=0;
    shortestPath(V, adj, s);
		
	return 0;
}