//leetcode
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, list<int>> adj;
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int> indegree(numCourses, 0);

        for (auto i : adj) {
            for (auto j : i.second) {
                indegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        vector<int> ans;
        while (!q.empty()) {
            auto temp = q.front();
            ans.push_back(temp);
            q.pop();
            cnt++;
            for (auto i : adj[temp]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        if(cnt==numCourses)
        {
            return ans;
        }
        return {};
    }
};
