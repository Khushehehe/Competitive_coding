class Solution {
public:
    vector<vector<int>> ans;
    vector<int> arr;
    void add(vector<int> &nums, int i){
        if(i==nums.size()){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]); 
        add(nums, i+1);
        arr.pop_back();
        add(nums, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        add(nums, 0);
        return ans;
    }
};