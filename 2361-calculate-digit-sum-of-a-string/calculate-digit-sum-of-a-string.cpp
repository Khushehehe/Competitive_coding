class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string ans= "";
            for(int i=0;i<s.size();i+=k){
                string x= s.substr(i, k);
                int sum=0;
                for(char c: x){
                    sum+= c-'0';
                }
                ans+= to_string(sum);
            }
            s= ans;
        }
        return s;
    }
};