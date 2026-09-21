class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto &it: mp){
            if(it.second.size()==3){
                int i=1;
                if((it.second[i]-it.second[i-1])==(it.second[i+1]-it.second[i])){
                    ans++;
                }
            }else{
                continue;
            }
        }
        return ans;
    }
};