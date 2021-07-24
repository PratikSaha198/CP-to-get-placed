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

    vector<int> dist(V, INT_MAX);

    // To check if a node is present in the queue or not
    vector<int> there(V, 0);
    
    dist[sr] = 0;

    // Add the staritng node
    queue<int> q;
    q.push(sr);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        // Marking the popped node to be ot present in the queue
        there[u] = 0;
        
        for(auto it : adj[u]){
            int v = it.first;
            int weight = it.second;
            if(dist[u]!=INT_MAX and dist[v]>dist[u]+weight){
                dist[v] = dist[u] + weight;

                // If not present in queue then add it
                if(!there[v]){
                    q.push(v);
                    there[v] = 1;
                }
            }
        }
    }

    // Print the distances
    for(auto it : dist) cout<<it<<" ";
}

int main(){

	fast

    // Shortest Path Faster Algorithm 
    // A variation of Bellman Ford but more efficient as it doesnt go through all the edges of each round
    // But chooses the edges intelligently using a queue
    // DOESNT WORK FOR CYCLE DETECTION

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