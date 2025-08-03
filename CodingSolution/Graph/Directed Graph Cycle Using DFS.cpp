//GFG
class Solution {
  public:
    bool DFS(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adj)
    {
        visited[node]=true;
        dfsvisited[node]=true;
        
        for(auto i:adj[node])
        {
            if(!visited[i])
            {
                bool cycle=DFS(i,visited,dfsvisited,adj);
                if(cycle)
                {
                    return true;
                }
            }
            else if(dfsvisited[i])
            {
                return true;
            }
        }
        dfsvisited[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            
        }
        
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsvisited;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                bool cycle=DFS(i,visited,dfsvisited,adj);
                if(cycle)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
