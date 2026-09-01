class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int b= store.top();
                store.pop();
                int a= store.top();
                store.pop();
                if(tokens[i]=="+"){
                    store.push(a+b);
                }else if(tokens[i]=="-"){
                    store.push(a-b);
                }else if(tokens[i]=="*"){
                    store.push(a*b);
                }else if(tokens[i]=="/"){
                    store.push(a/b);
                }
            }else{
                store.push(stoi(tokens[i]));
            }
        }
        return store.top();
    }
};