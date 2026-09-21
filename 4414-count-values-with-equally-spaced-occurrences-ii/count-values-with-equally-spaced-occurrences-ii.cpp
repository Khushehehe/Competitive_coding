class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto &it: mp){
            if(it.second.size()>=3){
                int diff= it.second[1]-it.second[0];
                bool add= true;
                for(int i=2;i<it.second.size();i++){
                    if(it.second[i]-it.second[i-1]!=diff){
                        add= false;
                        break;
                    }
                }
                if(add==true){
                    ans++;
                }
            }
        }
        return ans;
    }
};