//GFG
class Solution {
  public:
    void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,stack<int> &st)
    {
        visited[node]=true;
        for(auto neighbour:adj[node])
        {
            if(!visited[neighbour])
            {
                dfs(neighbour,visited,adj,st);
            }
        }
        st.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        vector<int> ans;
        unordered_map<int,bool> visited;
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,adj,st);
               
            }
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
