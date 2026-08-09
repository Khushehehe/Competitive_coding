class Solution {
public:
    void dfs(int ancestor, int curr, vector<vector<int>> &adj, vector<vector<int>> &ans, vector<int> &visited){
        visited[curr]=true;
        for(auto &neighbor: adj[curr]){
            if(!visited[neighbor]){
                ans[neighbor].push_back(ancestor);
                dfs(ancestor, neighbor, adj, ans, visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            vector<int> visited(n, false);
            dfs(i, i, adj, ans, visited);
        }
        return ans;
    }
};