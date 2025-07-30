//GFG
class Solution {
  public:
    void dfs(int node,unordered_map<int,bool> &visited,vector<vector<int>> &adj,vector<int> &ans)
    {
        visited[node]=true;
        ans.push_back(node);
        for(auto i:adj[node])
        {
            if(!visited[i])
               dfs(i,visited,adj,ans);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int,bool> visited;
        vector<int> ans;
        for(int i=0;i<adj.size();i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,adj,ans);
            }
        }
        return ans;
    }
};
