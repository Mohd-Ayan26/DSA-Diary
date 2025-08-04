// GFG
class Solution {
  public:
    void dfs(int node,unordered_map<int,bool> &visited, unordered_map<int,list<pair<int,int>>> &adj,stack<int> &st)
    {
        visited[node]=true;
        for(auto i:adj[node])
        {
            if(!visited[i.first])
                   dfs(i.first,visited,adj,st);
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<E;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        unordered_map<int,bool> visited;
        stack<int> st;
        dfs(0,visited,adj,st);
        vector<int> dist(V,INT_MAX);
        dist[0]=0;
        while(!st.empty())
        {
            auto temp=st.top();
            st.pop();
            
            if(dist[temp]!=INT_MAX)
            {
                for(auto i:adj[temp])
                {
                    if(dist[temp]+i.second<dist[i.first])
                    {
                        dist[i.first]=dist[temp]+i.second;
                    }
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(dist[i]==INT_MAX)
            {
                dist[i]=-1;
            }
        }
        return dist;
    }
};
