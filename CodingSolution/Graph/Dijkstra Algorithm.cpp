// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            
            adj[u].push_back({v,w});
        }
        
        set<pair<int,int>> st;
        vector<int> dist(V,INT_MAX);
        
        dist[src]=0;
        
        st.insert({0,src});
        
        while(!st.empty())
        {
            auto temp=(*st.begin());
            int node=temp.second;
            int distance=temp.first;
            
            st.erase(st.begin());
            
            for(auto i:adj[node])
            {
                if(distance+i.second<dist[i.first])
                {
                    auto record=st.find({dist[i.first],i.first});
                    if(record!=st.end())
                    {
                        st.erase(record);
                    }
                    
                    dist[i.first]=distance+i.second;
                    st.insert({dist[i.first],i.first});
                }
            }
        }
        
        return dist;
    }
};
