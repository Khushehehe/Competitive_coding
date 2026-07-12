class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()){
            return arr;
        }
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        map<int, int> mp;
        int j=1;
        mp.insert({temp[0], j});
        for(int i=1;i<temp.size();i++){
            if(temp[i]!=temp[i-1]){
                j+=1;
                mp.insert({temp[i], j});
            }else{
                mp.insert({temp[i], j});
            }
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};