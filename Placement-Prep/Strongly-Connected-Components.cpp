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

void dfs(int u, vector<int> adj[], vector<int> &visited){
    visited[u] = true;
    cout<<u<<" ";
    for(int i=0;i<adj[u].size();i++){
        if(visited[adj[u][i]] == false)
            dfs(adj[u][i], adj, visited);
    }
}

void transpose(int V, vector<int> adj[], vector<int> tranAdj[]){
    for(int u=0; u<V; u++){
        for(int i=0;i<adj[u].size();i++){
            addEdge(tranAdj, adj[u][i], u);
        }
    }
}

void dfsStack(int u, vector<int> adj[], vector<int> &visited, stack<int> &st){
    visited[u] = true;
    for(int i=0;i<adj[u].size();i++){
        if(visited[adj[u][i]] == false)
            dfsStack(adj[u][i], adj, visited, st);
    }
    st.push(u);
}

void SCC(int V, vector<int> adj[]){
    
    // initialise stack and a visited array

    stack<int> st;
    vector<int> visited(V, false);
    
    // dfs of the whole graph with a stack containing elements if a vertex leads to an already visited vertex then push.

    for(int u=0; u<V; u++){
        if(visited[u] == false)
            dfsStack(u, adj, visited, st);
    }

    // transpose the whole graph

    vector<int> tranAdj[V];
    transpose(V, adj, tranAdj);

    // again revert back all visited as false

    for(int i=0;i<V;i++) visited[i]=false;

    // starting from the top of the stack perform dfs on the reversed graph
    // FOR COUNT/number of components => count how many time the if statement is executed

    while(st.empty() == false){
        
        int u = st.top();
        st.pop();

        if(visited[u] == false){
            dfs(u, tranAdj, visited);
            cout<<endl;
        }
    }
}

int main(){

	fast

	int V=5;
    vector<int> adj[V];

    // directed graph

    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 1, 0);

    cout<<"Strongly Connected Components"<<endl;
    SCC(V, adj);
		
	return 0;
}