class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestVal= nums[0];
        int ans= bestVal;
        for(int i=1; i<nums.size(); i++){
            bestVal= max(nums[i], nums[i]+bestVal);
            ans= max(ans, bestVal);
        }
        return ans;
    }
};