class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp.insert({0, -1});
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.count(sum%k) && i-mp[sum%k]>=2){
                return true;
            }else{
                mp.insert({sum%k, i});
            }
        }
        return false;
    }
};