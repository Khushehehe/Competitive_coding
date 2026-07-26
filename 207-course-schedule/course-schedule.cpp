class Solution {
public:
    bool isCycle(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &prerequisites){
        visited[src]=true;
        recPath[src]=true;
        for(int i=0;i<prerequisites.size();i++){
            int v= prerequisites[i][0];
            int u= prerequisites[i][1];
            if(u==src){
                if(!visited[v]){
                    if(isCycle(v, visited, recPath, prerequisites)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> recPath(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(isCycle(i, visited, recPath, prerequisites)){
                    return false;
                }
            }
        }
        return true;
    }
};