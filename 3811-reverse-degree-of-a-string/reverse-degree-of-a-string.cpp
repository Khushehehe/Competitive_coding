class Solution {
public:
    int reverseDegree(string s) {
        map<char, int> mp;
        int temp=26;
        for(char ch='a'; ch<='z'; ch++){
            mp[ch]= temp;
            temp--;
        }
        int reverseDegree=0;
        for(int i=0;i<s.size();i++){
            int a= mp[s[i]]*(i+1);
            reverseDegree+=a;
        }
        return reverseDegree;
    }
};