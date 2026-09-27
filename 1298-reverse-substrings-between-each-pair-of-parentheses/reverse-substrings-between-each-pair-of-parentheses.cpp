class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char ch: s){
            if(ch!=')'){
                st.push(ch);
            }else{
                string x="";
                while(st.top()!='('){
                    x+=st.top();
                    st.pop();
                }
                st.pop();
                for(char c: x){
                    st.push(c);
                }
            }
        }
        string ans= "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};