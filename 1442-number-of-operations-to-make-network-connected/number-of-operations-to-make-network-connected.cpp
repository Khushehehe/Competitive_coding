class Solution {
public:
    vector<int> par, rank;
    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]= find(par[x]);
    }
    void unionByRank(int a , int b){
        int parA= find(a);
        int parB= find(b);
        if(parA==parB){
            return;
        }
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
    }
    int modifiedKruskal(vector<vector<int>> &connections, int n){
        int components=n;
        for(auto &e: connections){
            int parU= find(e[0]);
            int parV= find(e[1]);
            if(parU!=parV){
                unionByRank(e[0], e[1]);
                components--;
            }
        }
        return components;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        for(int i=0;i<n;i++){
            par.push_back(i);
            rank.push_back(0); 
        }
        int c= modifiedKruskal(connections, n);
        if(c==1){
            return 0;
        }
        return c-1;
    }
};