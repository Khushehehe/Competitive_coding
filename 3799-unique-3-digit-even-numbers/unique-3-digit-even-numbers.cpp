class Solution {
public:
    int ans=0;
    void solve(vector<int> &digits, vector<bool> &used, int idx, int num){
        if(idx==3){
            if(num%2==0){
                ans++;
            }
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(used[i]==true){
                continue;
            }
            if(idx==0 && digits[i]==0){
                continue;
            }
            if(i>0 && digits[i]==digits[i-1] && !used[i-1]){
                continue;
            }
            used[i]=true;
            solve(digits, used, idx+1, num*10+digits[i]);
            used[i]=false;
        }
    }
    int totalNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        vector<bool> used(digits.size(), false);
        solve(digits, used, 0, 0);
        return ans;
    }
};