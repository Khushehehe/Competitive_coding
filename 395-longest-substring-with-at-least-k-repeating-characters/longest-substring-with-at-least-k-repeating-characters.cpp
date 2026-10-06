class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxlen=0;
        int n= s.length();
        for(int targetUnique=1; targetUnique<=26; targetUnique++){
            vector<int> count(26, 0);
            int left= 0;
            int right= 0;
            int uniqueWithMinK= 0;
            int currUnique= 0;
            while(right<n){
                if(currUnique<=targetUnique){
                    int idx= s[right]-'a';
                    if(count[idx]==0){
                        currUnique++;
                    }
                    count[idx]++;
                    if(count[idx]==k){
                        uniqueWithMinK++;
                    }
                    right++;
                }else{
                    int idx= s[left]-'a';
                    if(count[idx]==k){
                        uniqueWithMinK--;
                    }
                    count[idx]--;
                    if(count[idx]==0){
                        currUnique--;
                    }
                    left++;
                }
                if(currUnique==targetUnique && currUnique==uniqueWithMinK){
                    maxlen= max(maxlen, right-left);
                }
            }
        }
        return maxlen;
    }
};