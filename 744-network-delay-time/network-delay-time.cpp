class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto edge: times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            graph[u].push_back({v, w});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto curr= pq.top();
            pq.pop();
            int currDist=curr.first;
            int node=curr.second;
            if(currDist>dist[node]){
                continue;
            }
            for(auto neighbour: graph[node]){
                int next=neighbour.first;
                int weight=neighbour.second;
                if(currDist+weight<dist[next]){
                    dist[next]=currDist+weight;
                    pq.push({dist[next], next});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans=max(ans, dist[i]);
        }
        return ans;
    }
};