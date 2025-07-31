//GFG
class Solution {
  public:
    bool dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,unordered_map<int,int> &parent){
         
         visited[node]=true;
         
         for(auto neighbour:adj[node])
         {
             if(!visited[neighbour])
             {
                 parent[neighbour]=node;
                 bool ans=dfs(neighbour,visited,adj,parent);
                 if(ans) return true;
             }
             else if(neighbour!=parent[node])
             {
                 return true;
             }
         }
         return false;
    }
     bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                bool ans=dfs(i,visited,adj,parent);
                if(ans) return ans;
            }
        }
        return false;
        
    }
};
