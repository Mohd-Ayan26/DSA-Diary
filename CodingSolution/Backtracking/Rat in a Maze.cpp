class Solution {
  public:
  
    bool safe(int x,int y,vector<vector<int>> visited,vector<vector<int>> maze,int n)
    {
        if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1 && visited[x][y]==0)
        {
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &maze,vector<vector<int>> &visited,int x,int y,string path,int n,vector<string> &ans)
    {
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return ;
        }
        
        visited[x][y]=1;
        int newx,newy;
        
        
        //Up
        newx=x-1;
        newy=y;
        
        if(safe(newx,newy,visited,maze,n))
        {
            path.push_back('U');
            solve(maze,visited,newx,newy,path,n,ans);
            path.pop_back();
        }
        
        
        //down
        newx=x+1;
        newy=y;
        
        if(safe(newx,newy,visited,maze,n))
        {
            path.push_back('D');
            solve(maze,visited,newx,newy,path,n,ans);
            path.pop_back();
        }
        
        //Right
        newx=x;
        newy=y+1;
        
        if(safe(newx,newy,visited,maze,n))
        {
            path.push_back('R');
            solve(maze,visited,newx,newy,path,n,ans);
            path.pop_back();
        }
        
        //left
        newx=x;
        newy=y-1;
        
        if(safe(newx,newy,visited,maze,n))
        {
            path.push_back('L');
            solve(maze,visited,newx,newy,path,n,ans);
            path.pop_back();
        }
        
        
        
        visited[x][y]=0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        if(maze[0][0]==0)
        {
            return ans;
        }
        string path;
        int x=0,y=0;
        int n=maze.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        solve(maze,visited,x,y,path,n,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
