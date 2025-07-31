//GFG
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<int> indegree(V);
        for(auto i:adj)
        {
            for(auto j:i.second)
            {
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        //BFS
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(auto neighbour:adj[temp])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }
};
