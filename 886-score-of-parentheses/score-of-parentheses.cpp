class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char c: s){
            if(c=='('){
                st.push(0);
            }else{
                int innerScore= st.top();
                st.pop();
                int currScore;
                if(innerScore==0){
                    currScore=1;
                }else{
                    currScore= 2*innerScore;
                }
                st.top()+=currScore;
            }
        }
        return st.top();
    }
};