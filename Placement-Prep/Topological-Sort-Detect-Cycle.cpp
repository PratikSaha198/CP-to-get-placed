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

void topoSortUtil(int u, vector<int> adj[], vector<int> &visited, stack<int> &st){
    visited[u] = true;
    for(int i=0;i<adj[u].size();i++){
        if(visited[adj[u][i]] == false)
            topoSortUtil(adj[u][i], adj, visited, st);
    }
    st.push(u);
}

void topoSort(int V, vector<int> adj[]){
    stack<int> st;
    vector<int> visited(V, false);
    for(int u=0;u<V;u++){
        if(visited[u] == false)
            topoSortUtil(u, adj, visited, st);
    }

    // Stores the position of the vertex in topological order   

    unordered_map<int, int> pos;
    int index=0;
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        pos[st.top()] = index;
        index++;
        st.pop();
    }
    cout<<endl;

    bool isthere = false;

    for(int u=0;u<V;u++){
        for(int i=0;i<adj[u].size();i++){
            // If the parent doesnt appear first
            
            if(pos[u]>pos[adj[u][i]]){
                cout<<"CYCLE PRESENT";
                isthere = true;
                break;
            }
        }
    }

    if(!isthere) cout<<"CYCLE NOT PRESENT";
}

int main(){

	fast

    int V=5;
    vector<int> adj[V];

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);

    // In Topological Sort, the idea is to visit the parent node followed by the child node. 
    // If the given graph contains a cycle, then there is at least one node which is a parent as well as a child so this will break Topological Order.
    // Therefore, after the topological sort, check for every directed edge whether it follows the order or not.

    topoSort(V, adj);
		
	return 0;
}