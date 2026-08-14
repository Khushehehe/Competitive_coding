class Solution {
public:
    int maximumLengthSubstring(string s) {
        int right=0;
        int left=0;
        int size=INT_MIN;
        unordered_map<int, int> mp;
        while(right<s.size()){
            mp[s[right]]++;
            if(mp[s[right]]<2){
                int val=right-left+1;
                size=max(size, val);
                right++;
            }else{
                while(mp[s[right]]>2){
                    mp[s[left]]--;
                    left++;
                }
                int val=right-left+1;
                size=max(size, val);
                right++;
            }
        }
        return size;
    }
};