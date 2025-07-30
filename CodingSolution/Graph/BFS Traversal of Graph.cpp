//GFG
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int node,unordered_map<int,bool> &visited,vector<vector<int>> &adj,vector<int> &ans)
    {
        queue<int> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(auto j:adj[temp])
            {
                if(!visited[j])
                {
                   q.push(j);
                   visited[j]=true;
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        unordered_map<int,bool> visited;
        vector<int> ans;
        for(int i=0;i<adj.size();i++)
        {
            if(!visited[i])
            {
                bfs(i,visited,adj,ans);
            }
        }
        return ans;
        
    }
};
