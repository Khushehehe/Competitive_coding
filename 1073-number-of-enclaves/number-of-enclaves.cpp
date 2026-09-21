class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        grid[r][c]= 0;
        if(r>0 && grid[r-1][c]==1){
            dfs(r-1, c, grid);
        }
        if(r<n-1 && grid[r+1][c]==1){
            dfs(r+1, c, grid);
        }
        if(c>0 && grid[r][c-1]==1){
            dfs(r, c-1, grid);
        }
        if(c<m-1 && grid[r][c+1]==1){
            dfs(r, c+1, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0, j, grid);
            }
            if(grid[n-1][j]==1){
                dfs(n-1, j, grid);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i, 0, grid);
            }
            if(grid[i][m-1]==1){
                dfs(i, m-1, grid);
            }

        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};