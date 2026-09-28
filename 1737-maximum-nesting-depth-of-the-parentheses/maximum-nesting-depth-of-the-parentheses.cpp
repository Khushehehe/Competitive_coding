class Solution {
public:
    int maxDepth(string s) {
        int curr= 0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                curr++;
                ans= max(ans, curr);
            }
            if(s[i]==')'){
                curr--;
            }
        }
        return ans;
    }
};