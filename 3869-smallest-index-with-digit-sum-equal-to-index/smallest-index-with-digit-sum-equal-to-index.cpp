class Solution {
public:
    int calSum(int x){
        int sum=0;
        while(x!=0){
            int rem= x%10;
            sum+=rem;
            x=x/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<10){
                if(i==nums[i]){
                    return i;
                }
            }else{
                if(i==calSum(nums[i])){
                    return i;
                }
            }
        }
        return -1;
    }
};