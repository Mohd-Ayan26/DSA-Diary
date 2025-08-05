class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> key(V,INT_MAX);
        vector<bool> mst(V,false);
        
        key[0]=0;
        for(int i=0;i<V;i++)
        {
            int mini=INT_MAX;;
            int u;
            
            for(int v=0;v<V;v++)
            {
                if(mst[v]==false && key[v]<mini)
                {
                    u=v;
                    mini=key[v];
                }
            }
            
            mst[u]=true;
            
            for(auto temp:adj[u])
            {
                int v=temp.first;
                int w=temp.second;
                
                if(mst[v]==false && w<key[v])
                {
                    key[v]=w;
                }
            }
        }
        int ans=0;
        for(int i=0;i<V;i++)
        {
            ans+=key[i];
        }
        return ans;
    }
};
