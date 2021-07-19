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

void BFS(int V, vector<int> adj[], int s){
    
    vector<int> visited(V, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(q.empty()==false){
        int f = q.front();
        cout<<f<<" ";
        q.pop();
        for(int i=0;i<adj[f].size();i++){
            if(visited[adj[f][i]]==false){
                visited[adj[f][i]] = true;
                q.push(adj[f][i]);
            }
        }
    }
}

int main(){

	fast

    int V = 4;
    vector<int> adj[V];
	addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    BFS(4, adj, 2);
		
	return 0;
}