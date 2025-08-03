//GFG
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            
        }
        
       vector<int> indegree(V,0);
       
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
      
       int cnt=0;
       while(!q.empty())
       {
           auto temp=q.front();
           q.pop();
           cnt++;
           for(auto i:adj[temp])
           {
               indegree[i]--;
               if(indegree[i]==0)
               {
                   q.push(i);
               }
           }
       }
       return cnt != V;
    }
};
