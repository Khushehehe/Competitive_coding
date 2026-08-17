class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int m=INT_MIN;
        unordered_map<int,int> mp;
        mp[0]=0;
        mp[1]=0;
        for(int h=0;h<nums.size();h++){
            mp[nums[h]]++;
            while(mp[0]> k){
                mp[nums[l]]--;
                l++;
            }
            m=max(m,h-l+1);    
        }
        return m;
    }
};