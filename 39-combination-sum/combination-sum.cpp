class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void solve(int i, vector<int>& candidates, int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0 || i==candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        solve(i, candidates, target-candidates[i]);
        curr.pop_back();
        solve(i+1, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};