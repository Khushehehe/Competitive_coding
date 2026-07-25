class Solution {
public:
    bool dfs(vector<vector<char>> &board, int row, int col, string x, string word, vector<vector<bool>> &visited){
        int m= board.size();
        int n= board[0].size();
        if(row<0 || row>=m || col<0 || col>=n){
            return false;
        }
        if(visited[row][col]==true){
            return false;
        }
        if(board[row][col]!=word[x.size()]){
            return false;
        }
        x+=board[row][col];
        if(x==word){
            return true;
        }
        visited[row][col]=true;
        bool ans = dfs(board, row - 1, col, x, word, visited) ||
                   dfs(board, row + 1, col, x, word, visited) ||
                   dfs(board, row, col - 1, x, word, visited) ||
                   dfs(board, row, col + 1, x, word, visited);
        visited[row][col] = false; 
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m= board.size();
        int n= board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    vector<vector<bool>> visited(m, vector<bool> (n, false));
                    if(dfs(board, i, j, "", word, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};