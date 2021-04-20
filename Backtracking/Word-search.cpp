// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells,
// where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


bool doit(vector<vector<char>> &board, int i, int j, int index, const string &word)
{
    if(index==word.length()) 
        return true;
    
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
        return false;
    
    if(board[i][j]!=word[index]) 
        return false;
    
    board[i][j] = '*';
    
    bool further = doit(board, i+1, j, index+1, word)||
                    doit(board, i, j+1, index+1, word)||
                    doit(board, i-1, j, index+1, word)||
                    doit(board, i, j-1, index+1, word);
    board[i][j] = word[index];
    
    return further;
}

bool exist(vector<vector<char>>& board, string s)
{
    int i=0, j=0;

    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(doit(board, i, j, 0, s)) 
                return true;
        }
    }
    return false;
}