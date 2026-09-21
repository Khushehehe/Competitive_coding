class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& adj, vector<int>& color){
        color[node]=col;
        for(auto neighbor: adj[node]){
            if(color[neighbor]==-1){
                if(!dfs(neighbor, 1-col, adj, color)){
                    return false;
                }
            }else if(color[neighbor]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(adj.size(), -1);
        for(int i=0;i<adj.size();i++){
            if(color[i]==-1){
                if(!dfs(i, 0, adj, color)){
                    return false;
                }
            }
        }
        return true;
    }
};