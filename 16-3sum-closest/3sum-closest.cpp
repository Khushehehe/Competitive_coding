class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // int sum=0;
        // int i=0;
        // for(int i=0;i<3;i++){
        //     sum+=nums[i];
        // } 
        // int closestSum=sum;  
        // int diff=abs(target-sum);
        // for(int i=3;i<nums.size();i++){
        //     sum+=nums[i];
        //     sum-=nums[i-3];
        //     int newdiff=abs(target-sum);
        //     if(newdiff<diff){
        //         diff=newdiff;
        //         closestSum=sum;
        //     }
        // }
        // return closestSum;
        sort(nums.begin(), nums.end());
        int closestSum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(abs(target-sum)<abs(target-closestSum)){
                    closestSum=sum;
                }
                if(sum<target){
                    left++;
                }else if(sum>target){
                    right--;
                }else{
                    return sum;
                }
            }
        }
        return closestSum;
    }
};