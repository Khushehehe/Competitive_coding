class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestVal= nums[0];
        int worstVal= nums[0];
        int ans= bestVal;
        for(int i=1;i<nums.size();i++){
            int a= nums[i]*bestVal;
            int b= nums[i]*worstVal;
            int c= nums[i];
            bestVal= max(a, max(b, c));
            worstVal= min(a, min(b, c));
            ans= max(ans, bestVal);
        }
        return ans;
    }
};