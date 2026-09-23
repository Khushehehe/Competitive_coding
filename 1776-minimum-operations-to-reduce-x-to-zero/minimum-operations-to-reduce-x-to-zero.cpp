class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
        }
        int target= total_sum-x;
        if(target==0){
            return nums.size();
        }
        if(target<0){
            return -1;
        }
        int left=0;
        int maxLen= -1;
        int currSum=0;
        for(int right=0;right<nums.size();right++){
            currSum+=nums[right];
            while(currSum>target && left<=right){
                currSum-=nums[left];
                left++;
            }
            if(currSum==target){
                maxLen= max(maxLen, right-left+1);
            }
        }
        if(maxLen==-1){
            return -1;
        }
        return nums.size()-maxLen;
    }
};