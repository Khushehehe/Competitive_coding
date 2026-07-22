class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string a;
        string b;
        for(char c: s){
            if(c==x){
                a+=c;
            }else{
                b+=c;
            }
        }
        return b+a;
    }
};