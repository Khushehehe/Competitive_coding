class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int degree=0;
        for(auto &it: mp){
            degree= max(degree, it.second);
        }
        int ans=nums.size();
        for(auto &it: mp){
            if(it.second==degree){
                int first=-1;
                int last=-1;
                for(int i=0;i<nums.size(); i++){
                    if(nums[i]==it.first){
                        if(first==-1){
                            first=i;
                        }
                        last=i;
                    }
                }
                ans=min(ans, last-first+1);
            }
        }
        return ans;
    }
};