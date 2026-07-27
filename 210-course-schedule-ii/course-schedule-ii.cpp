class Solution {
public:
    bool isCycle(int src, vector<bool>& visited, vector<bool>& recPath, vector<vector<int>>& prerequisites){
        visited[src]=true;
        recPath[src]=true;
        for(int i=0;i<prerequisites.size();i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
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
    void dfs(int curr, vector<bool>& visited, stack<int>& s, list<int> l[]){
        visited[curr]=true;
        for(auto &v: l[curr]){
            if(!visited[v]){
                dfs(v, visited, s, l);
            }
        }
        s.push(curr);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(!canFinish(numCourses, prerequisites)){
            return {};
        }
        vector<bool> visited(numCourses, false);
        stack<int> s;
        list<int> l[numCourses];
        for(auto &it: prerequisites){
            l[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(i, visited, s, l);
            }
        }
        vector<int> ans;
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};