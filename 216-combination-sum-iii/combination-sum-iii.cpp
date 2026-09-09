class Solution {
public:
    vector<vector<int>> ans;
    void helper(int val, int remaining, vector<int> &path, int &max){
        if(remaining==0){
            if(path.size()==max){
                ans.push_back(path);
            }
            return;
        }
        if(remaining<0 || val>9 || path.size()>max){
            return;
        }
        path.push_back(val);
        helper(val+1, remaining-val, path, max);
        path.pop_back();
        helper(val+1, remaining, path, max);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        helper(1, n, path, k);
        return ans;
    }
};