class Solution {
public:
    void helper(vector<vector<int>> &rooms, set<int> &s, int src){
        if(s.count(src)){
            s.erase(src);
            for(auto &it: rooms[src]){
                if(s.count(it)){
                    helper(rooms, s, it);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> s;
        for(int i=0;i<rooms.size();i++){
            s.insert(i);
        }
        helper(rooms, s, 0);
        if(s.empty()){
            return true;
        }
        return false;
    }
};