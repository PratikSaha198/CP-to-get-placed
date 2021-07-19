#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007LL

#define ll long long 
#define ull unsigned long long 
#define ld long double

using namespace std;

void explore_neighbours(int r, int c, vector<int> dr, vector<int> dc, int R, int C, vector<vector<int>> &visited, vector<vector<char>> m, queue<int> &rq, queue<int> &cq, int &nodes_in_next_layer){
    
    int rr, cc;

    for(int i=0;i<4;i++){
        rr = r+dr[i];
        cc = c+dc[i];
        
        if(rr<0 || cc<0) continue;
        if(rr>=R || cc>=C) continue;

        if(visited[rr][cc] == true) continue;
        if(m[rr][cc] == '#') continue;

        rq.push(rr);
        cq.push(cc);
        visited[rr][cc] = true;
        
        nodes_in_next_layer++;
    }
}

int main(){

	fast

	int R=5, C=7;
    vector<vector<char>> m{
        {'S', '.', '.', '#', '.', '.', '.'},
        {'.', '#', '.', '.', '#', '.', '.'},
        {'.', '#', '.', '.', '.', '.', '.'},
        {'.', '.', '#', '#', '.', '.', '.'},
        {'#', '.', '#', 'E', '.', '#', '.'}
    };

    int sr=0, sc=0;
    queue<int> rq;
    queue<int> cq;

    int move_cnt=0, nodes_left_in_layer=1, nodes_in_next_layer=0;
    bool reached_end = false;

    vector<vector<int>> visited(R, vector<int>(C, false));

    vector<int> dr{-1, 1, 0, 0};
    vector<int> dc{0, 0, 1, -1};

    rq.push(sr);
    cq.push(sc);
    visited[sr][sc] = true;

    while(rq.size()>0){
        int r = rq.front();
        int c = cq.front();
        
        rq.pop();
        cq.pop();

        if(m[r][c] == 'E'){
            reached_end = true;
            break;
        }
        explore_neighbours(r, c, dr, dc, R, C, visited, m, rq, cq, nodes_in_next_layer);

        nodes_left_in_layer--;
        
        if(nodes_left_in_layer==0){
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            move_cnt++;
        }
    }

    if(reached_end==true) cout<<move_cnt;
    else cout<<-1;

	return 0;
}