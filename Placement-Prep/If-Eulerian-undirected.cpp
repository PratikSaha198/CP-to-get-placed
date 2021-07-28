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
    
    int i;
    for(i=0;i<V;i++){
        if(adj[i].size()!=0) break;
    }

    // EDGE CASE, where there are no edges in the graph
    if(i==V) return false;

    DFS(i, adj, visited);

    // Check if all the non-zero degree vertices are visited
    for(i=0;i<V;i++){
        if(visited[i]==false && adj[i].size()>0) return false;
    }

    return true;
}

void isEulerain(int V, vector<int> adj[]){

    // Check if all non-zero degree vertice are connected
    if(!isConnected(V, adj)){
        cout<<"NOT CONNECTED THEREFORE, NOT ANY TYPE OF EULERIAN";
    }  
    else{

        // Store the degree
        vector<int> degree;
        for(int i=0;i<V;i++){
            int si = adj[i].size();
            degree.push_back(si);
        }

        // Calculate number of vertices having ODD degrees
        int odd = 0;
        for(auto it : degree) if(it%2!=0) odd++;

        if(odd>2) cout<<"NOT EULERIAN";
        else if(odd == 2) cout<<"EULERIAN -> EULERIAN PATH";
        else if(odd == 0) cout<<"EULERIAN -> EULERIAN CIRCUIT/CYCLE";
    }
}

int main(){

	fast

    // Eulerian Path is a path in graph that visits every edge exactly once.
    // Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.

    int V=5;
    vector<int> adj[V];

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);

    isEulerain(V, adj);
		
	return 0;
}