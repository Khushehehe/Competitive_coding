class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto &it: knowledge){
            mp[it[0]]=it[1];
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                int st= i;
                string x= "";
                i++;
                while(s[i]!=')'){
                    x.push_back(s[i]);
                    i++;
                }
                int len= i-st+1;
                string val="";
                if(mp.count(x)){
                    val= mp[x];
                    s.replace(st, len, val);
                }else{
                    val="?";
                    s.replace(st, len, val);
                }
                i= st+val.size()-1;
            }
        }
        return s;
    }
};