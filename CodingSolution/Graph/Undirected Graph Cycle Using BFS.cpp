//GFG
class Solution {
  public:
     bool bfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,unordered_map<int,int> &parent){
         
         visited[node]=true;
         queue<int> q;
         q.push(node);
         parent[node]=-1;
         while(!q.empty())
         {
             auto temp=q.front();
             q.pop();
             
             for(auto neighbour:adj[temp])
             {
                 if(visited[neighbour] && neighbour!=parent[temp])
                 {
                     return true;
                 }
                 
                 if(!visited[neighbour])
                 {
                     q.push(neighbour);
                     parent[neighbour]=temp;
                     visited[neighbour]=true;
                 }
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
                bool ans=bfs(i,visited,adj,parent);
                if(ans) return ans;
            }
        }
        return false;
        
    }
};
