// In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

// Return the maximum amount of gold you can collect under the conditions:

// Every time you are located in a cell you will collect all the gold in that cell.
// From your position, you can walk one step to the left, right, up, or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the grid that has some gold.

// Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
// Output: 24
// Explanation:
// [[0,6,0],
//  [5,8,7],
//  [0,9,0]]
// Path to get the maximum gold, 9 -> 8 -> 7

// Use dfs/recursion to choose the maximum among the options when possible
// Make the current cell as 0 and then later on change it back


int m, n;

int dfs(vector<vector<int>> &grid, int i, int j)
{
    if(grid[i][j]==0) 
        return 0;
    
    int ans = 0;
    int temp = grid[i][j];
    
    grid[i][j] = 0;
    
    if(i>0)
        ans = max(ans, temp + dfs(grid, i-1, j));
    if(j>0) 
        ans = max(ans, temp + dfs(grid, i, j-1));
    if(i<m-1)
        ans = max(ans, temp + dfs(grid, i+1, j));
    if(j<n-1)
        ans = max(ans, temp + dfs(grid, i, j+1));
    
    grid[i][j] = temp;
    
    return ans;
}

int getMaximumGold(vector<vector<int>>& grid) {
    
    m=grid.size();
    n=grid[0].size();
    
    int ans=0;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans = max(ans, dfs(grid, i, j));
        }
    }

    return ans;
}