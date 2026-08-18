class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     nums.push_back(nums[i]);
        // }
        // int bestVal= nums[0];
        // int ans= bestVal;
        // for(int i=1; i<nums.size(); i++){
        //     bestVal= max(nums[i], nums[i]+bestVal);
        //     ans= max(ans, bestVal);
        // }
        // return ans;

        int bestVal = nums[0];
        int worstVal = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            totalSum += nums[i];

            bestVal = max(nums[i], nums[i] + bestVal);
            maxSum = max(maxSum, bestVal);

            worstVal = min(nums[i], nums[i] + worstVal);
            minSum = min(minSum, worstVal);
        }

        if(maxSum < 0)
            return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};