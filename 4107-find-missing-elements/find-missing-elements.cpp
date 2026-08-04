class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int maxi=0;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            if(nums[i]<mini){
                mini=nums[i];
            }
        }
        for(int i=mini; i<maxi; i++){
            if(!mp.count(i)){
                ans.push_back(i);
            }else{
                continue;
            }
        }
        return ans;
    }
};