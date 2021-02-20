#include <bits/stdc++.h>
using namespace std;

class Graph{
    
    int V;
    map<int, vector<int>> m;
    
    void utilDFS(int s, vector<bool> &visited){
        visited[s] = true;
        cout<<s<<" ";
        for(auto it : m[s]){
            if(!visited[it])
                utilDFS(it, visited);
        }
    }
    
    public:
        Graph(int v){
            V = v;
        }
        
        void addEdge(int x, int y){
            m[x].push_back(y);
        }
        
        void DFS(int s){
            vector<bool> visit;
            for(int i=0;i<V;i++) visit.push_back(false);
            utilDFS(s, visit);
        }
};

map<int, vector<int>> m;

void utilDFS_class(int s, vector<bool> &visited){
    visited[s] = true;
    cout<<s<<" ";
    for(auto it : m[s]){
        if(!visited[it])
            utilDFS_class(it, visited);
    }
}

void DFS_stl(int s, int V){
    vector<bool> visit;
    for(int i=0;i<V;i++) 
        visit.push_back(false);
    utilDFS_class(s, visit);
}

int main() {
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(0);
    
	int V, E; cin>>V>>E;
	int x, y;
	for(int i=0;i<E;i++){
	    cin>>x>>y;
	    m[x].push_back(y);
	}
	
	DFS_stl(0, V);
	
	return 0;
}
