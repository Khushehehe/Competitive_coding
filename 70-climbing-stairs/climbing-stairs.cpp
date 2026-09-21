class Solution {
public:
    int helper(int n, vector<int>& dp){
        //dp memoization solution
        if(n==1 || n==2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]= helper(n-1, dp)+helper(n-2, dp);
    }
    int climbStairs(int n) {
        //recursion solution - fails due to tle 
        // if(n==1 || n==2){
        //     return n;
        // }
        // return climbStairs(n-1)+climbStairs(n-2);
        vector<int> dp(n+1, -1);
        return helper(n, dp);  
    }
};