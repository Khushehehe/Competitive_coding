class Solution {
public:
    int rob(vector<int>& nums) {
        // int suma=0;
        // int sumb=0;
        // for(int i=0;i<nums.size();i++){
        //     int newSum=max(suma+nums[i],sumb);
        //     suma=sumb;
        //     sumb=newSum;
        // }
        // return sumb;

        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            dp[i]= max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};