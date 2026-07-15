class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(auto &it: edges){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        for(auto &it: mp){
            if(it.second==edges.size()){
                return it.first;
            }
        }
        return -1;
        // unordered_map<int, vector<int>> mp;
        // for(auto &e: edges){
        //     int u=e[0];
        //     int v=e[1];
        //     mp[u].push_back(v);
        //     mp[v].push_back(u);
        // }
        // int count=0;
        // for(auto &[u, v]: mp){
        //     if(v.size()>edges.size()-1){
        //         return u;
        //     }
        // }
        // return -1;
    }
};