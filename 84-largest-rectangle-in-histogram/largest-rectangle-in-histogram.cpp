class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevSmall;
        vector<int> nextSmall(heights.size());
        stack<int> store;
        for(int i=0;i<heights.size();i++){
            while(!store.empty() && heights[store.top()]>=heights[i]){
                store.pop();
            }
            if(store.empty()){
                prevSmall.push_back(-1);
            }else{
                prevSmall.push_back(store.top());
            }
            store.push(i);
        }
        while(!store.empty()){
            store.pop();
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!store.empty() && heights[store.top()]>=heights[i]){
                store.pop();
            }
            if(store.empty()){
                nextSmall[i]=heights.size();
            }else{
                nextSmall[i]=store.top();
            }
            store.push(i);
        }
        int ans=0;
        for(int i=0;i<heights.size();i++){
            int width=nextSmall[i]-prevSmall[i]-1;
            ans= max(ans, heights[i]*width);
        }
        return ans;
    }
};