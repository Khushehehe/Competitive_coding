class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> v;
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[i].size()-1;j>=0;j--){
                v.push_back(grid[i][j]);
            }
        }
        int a=0;
        while(a<k){
            v.push_back(v[a++]);
        }
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[i].size()-1;j>=0;j--){
                grid[i][j]=v[a++];
            }
        }
        return grid;
    }
};