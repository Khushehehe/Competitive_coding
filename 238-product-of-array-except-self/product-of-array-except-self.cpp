class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> answer(n, 0);

        // long long pro = 1;
        // int zeroCount = 0;

        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //        zeroCount++;
        //     }else{
        //         pro*=nums[i]; 
        //     }
        // }
        // if (zeroCount > 1){
        //     return answer;
        // }

        // for (int i = 0; i < n; i++) {
        //     if (zeroCount == 1) {
        //         if (nums[i] == 0)
        //             answer[i] = pro;
        //         else
        //             answer[i] = 0;
        //     } else {
        //         answer[i] = pro / nums[i];
        //     }
        // }
        // return answer;
        vector<int> answer(nums.size(), 1);
        int p=1;
        for(int i=0;i<nums.size();i++){
            answer[i]=p;
            p*=nums[i];
        }
        int s=1;
        for(int i=nums.size()-1;i>=0;i--){
            answer[i]*=s;
            s*=nums[i];
        }
        return answer;
    }
};