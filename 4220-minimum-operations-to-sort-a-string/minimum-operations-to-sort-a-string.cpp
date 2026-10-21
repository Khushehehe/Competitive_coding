class Solution {
public:
    int minOperations(string s) {
        string temp=s;
        sort(temp.begin(), temp.end());
        if(temp==s){
            return 0;
        }
        if(s.size()==2){
            return -1;
        }
        char mn= s[0];
        char mx= s[0];
        int n= s.size();
        for(int i=1;i<n;i++){
            if(s[i]<mn){
                mn= s[i];
            }
            if(s[i]>mx){
                mx=s[i];
            }
        }
        if(s[0]==mn || s[n-1]==mx){
            return 1;
        }
        bool hasInnerExtreme=false;
        for(int i=1;i<n-1;i++){
            if(s[i]==mn || s[i]==mx){
                hasInnerExtreme= true;
                break;
            }
        }
        if(hasInnerExtreme){
            return 2;
        }
        return 3;
    }
};