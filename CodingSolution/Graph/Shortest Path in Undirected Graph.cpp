//GFG
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        vector<int> dist(adj.size(),INT_MAX);
        dist[src]=0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            
               for(auto i:adj[temp])
                {
                    if(dist[temp]+1<dist[i])
                    {
                        dist[i]=dist[temp]+1;
                        q.push(i);
                    }
                    
                }
            
        }
        for(int i=0;i<adj.size();i++)
        {
            if(dist[i]==INT_MAX)
            {
                dist[i]=-1;
            }
        }
        return dist;
    }
};
