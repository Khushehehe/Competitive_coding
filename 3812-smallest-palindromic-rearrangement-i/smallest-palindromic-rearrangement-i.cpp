class Solution {
public:
    string smallestPalindrome(string s) {
        int left=0;
        int right=s.size();
        int mid= left+((right-left)/2);
        string x="";
        for(int i=0;i<mid;i++){
            x+=s[i];
        }
        sort(x.begin(), x.end());
        string y=x;
        sort(y.rbegin(), y.rend());
        if(s.size()%2!=0){
            return x+s[mid]+y;
        }
        return x+y;
    }
};