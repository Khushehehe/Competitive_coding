class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int leftSum=0;
        int rightSum;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            rightSum=sum-leftSum-nums[i];
            if(leftSum==rightSum){
                return i;
            }else{
                leftSum+=nums[i];
            }
        }
        return -1;
    }
};