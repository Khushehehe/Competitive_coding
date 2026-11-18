class Solution {
public:
    // int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    //     int n= matrix.size();
    //     int m= matrix[0].size();
    //     if(j<0 || j>=m){
    //         return INT_MAX;
    //     }
    //     if(i==0){
    //         return matrix[0][j];
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int up= helper(i-1, j, matrix, dp);
    //     int left= helper(i-1, j-1, matrix, dp);
    //     int right= helper(i-1, j+1, matrix, dp);
    //     return dp[i][j]= matrix[i][j]+min(up, min(left, right));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n= matrix.size();
        // int m= matrix[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // int ans= INT_MAX;
        // for(int j=0;j<m;j++){
        //     ans= min(ans, helper(n-1, j, matrix, dp));
        // }
        // return ans;

        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up= dp[i-1][j];
                int left= INT_MAX;
                if(j>0){
                    left= dp[i-1][j-1];
                }
                int right=INT_MAX;
                if(j<m-1){
                    right= dp[i-1][j+1];
                }
                dp[i][j]= matrix[i][j]+min(up, min(left, right));
            }
        }
        int ans= INT_MAX;
        for(int j= 0;j<m; j++) {
            ans= min(ans, dp[n-1][j]);
        }
        return ans;
    }
};