class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // vector<pair<int, int>> v;
        // for(int i=0;i<score.size();i++){
        //     v.push_back({score[i], i});
        // }
        // sort(v.rbegin(), v.rend());
        // vector<string> ans(score.size());
        // for(int rank=0;rank<score.size();rank++){
        //     if(rank==0){
        //         ans[v[rank].second]="Gold Medal";
        //     }else if(rank==1){
        //         ans[v[rank].second]="Silver Medal";
        //     }else if(rank==2){
        //         ans[v[rank].second]="Bronze Medal";
        //     }else{
        //         ans[v[rank].second]=to_string(rank+1);
        //     }
        // }
        // return ans;

        int n= score.size();
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<n;i++){
            pq.push({score[i], i});
        }
        vector<string> ans(n);
        for(int rank=0;rank<score.size();rank++){
            if(rank==0){
                ans[pq.top().second]="Gold Medal";
                pq.pop();
            }else if(rank==1){
                ans[pq.top().second]="Silver Medal";
                pq.pop();
            }else if(rank==2){
                ans[pq.top().second]="Bronze Medal";
                pq.pop();
            }else{
                ans[pq.top().second]=to_string(rank+1);
                pq.pop();
            }
        }
        return ans;
    }
};