#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void DFS(int u, vector<int> adj[], vector<int> &visited){
    visited[u]  = true;
    for(auto it : adj[u]){
        if(!visited[it])
            DFS(it, adj, visited);
    }
}

bool isDisconnected(int V, vector<int> adj[]){
    vector<int> visited(V, false);

    int i;
    for(i=0;i<V;i++){
        if(adj[i].size()>0){
            break;
        }
    }

    DFS(i, adj, visited);

    for(int i=0;i<V;i++){
        if(!visited[i] and adj[i].size()>0) return true;
    }

    return false;
}

void transpose(int V, vector<int> adj[], vector<int> tra[]){
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            tra[it].push_back(i);
        }
    }
}

bool hasONEComponent(int V, vector<int> adj[]){

    vector<int> visited(V, false);
    DFS(0, adj, visited);

    for(int i=0;i<V;i++) visited[i]=false;

    vector<int> trans[V];
    transpose(V, adj, trans);

    DFS(0, trans, visited);

    for(int i=0;i<V;i++){
        if(!visited[i])
            return false;
    }

    return true;
}

void isEulerain(int V, vector<int> adj[]){

    // Check if disconnected or not
    if(isDisconnected(V, adj)){
        cout<<"DISCONNECTED, so NOT EULERIAN";
        return;
    }

    // Check if doesn't even have a chance of becoming eucler circuit
    if(!hasONEComponent(V, adj)) cout<<"DOESNT HAVE A CHANCE OF BECOMING A EULER CIRCUIT"<<endl;
    
    vector<int> in(V, 0), out(V, 0);

    for(int i=0;i<V;i++){
        out[i]+=adj[i].size();
        for(auto it : adj[i]){
            in[it]++;
        }
    }

    int cnt = 0;

    for(int i=0;i<V;i++) cout<<i<<" : IN -> "<<in[i]<<" OUT -> "<<out[i]<<endl;

    for(int i=0;i<V;i++)
        if(in[i]!=out[i])
            cnt++;

    // Check if there are 2 nodes with uneven number of incoming and outgoing edges the its a eulrain path
    if(cnt==0) cout<<"EULERIAN CYCLE";
    else if(cnt==2) cout<<"EULERIAN PATH";
    else cout<<"NOT EULERAIN";
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

    // int V=5;
    // vector<int> adj[V];

    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 4, 4);

    isEulerain(V, adj);
		
	return 0;
}