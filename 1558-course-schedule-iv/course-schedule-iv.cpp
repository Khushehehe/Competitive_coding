class Solution {
public:
    void helper(int numCourses,
                vector<bool> &answer,
                int a,
                int b,
                vector<vector<int>> &l)
    {
        vector<bool> visited(numCourses, false);
        queue<int> q;

        q.push(a);
        visited[a] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == b) {
                answer.push_back(true);
                return;
            }

            for (int v : l[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        answer.push_back(false);
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> l(numCourses);

        for (auto &v : prerequisites) {
            l[v[0]].push_back(v[1]);
        }

        vector<bool> answer;

        for (auto &v : queries) {
            helper(numCourses, answer, v[0], v[1], l);
        }

        return answer;
    }
};