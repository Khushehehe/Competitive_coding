class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n= nums.size();
        int goodRotations= 0;
        long long lSum= 0;
        long long rSum= 0;
        for(int i=0;i<n/2;i++){
            lSum+=nums[i];
            rSum+=nums[i+(n/2)];
        }
        if(lSum>rSum){
            goodRotations++;
        }
        for(int i=0;i<n-1;i++){
            lSum= lSum-nums[i]+nums[(i+(n/2))%n];
            rSum= rSum+nums[i]-nums[(i+(n/2))%n];
            if(lSum>rSum){
                goodRotations++;
            }
        }
        return goodRotations;
    }
};