#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int, vector<int>> m;
    public:
        Graph(int v){
            V = v;
        }
        void addEdge(int x, int y){
            m[x].push_back(y);
        }
        void BFS_classtype(int s){
            vector<bool> visited;
            for(int i=0;i<V;i++) visited.push_back(false);
            visited[s] = true;
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                s = q.front();
                cout<<s<<" ";
                q.pop();
                for(auto it : m[s]){
                    if(!visited[it]){
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }
        }
};

map<int, vector<int>> m;

void BFS_stl(int s, int V)
{
    vector<bool> visited;
    for (int i = 0; i < V; i++)
        visited.push_back(false);

    queue<int> q;
    q.push(s);

    visited[s] = true;

    while (!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop();
        for (auto it : m[s])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
}

int main() {
	
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    g.BFS_classtype(0);

    int V;
    cin >> V;
    int x, y;
    for (int i = 0; i < V; i++)
    {
        cin >> x >> y;
        m[x].push_back(y);
    }

    int start; 
    cin>>start;

    BFS_stl(start, V);

    return 0;
}