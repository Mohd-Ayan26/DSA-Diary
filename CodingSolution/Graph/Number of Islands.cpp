//Leetcode solution (4 directions)
class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};
            for (int s = 0; s < 4; s++) {

                int newR = r + dx[s];
                int newC = c + dy[s];

                if (newR >= 0 && newR < m && newC >= 0 && newC < n &&
                    !visited[newR][newC] && grid[newR][newC] == '1') {
                    q.push({newR, newC});
                    visited[newR][newC] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return cnt;
    }
};


************************************************************************************************************************************

//GFG solution (8 direction)
class Solution {
  public:
    void bfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &visited)
    {
        int m=grid.size();
        int n=grid[0].size();
        visited[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int dr=-1;dr<=1;dr++)
            {
                for(int dc=-1;dc<=1;dc++)
                {
                    int newR=r+dr;
                    int newC=c+dc;

                    if(newR>=0 && newR<m && newC>=0 && newC<n && !visited[newR][newC] && grid[newR][newC]=='L')
                    {
                        q.push({newR,newC});
                        visited[newR][newC]=1;
                    }

                }

            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j]=='L')
                {
                     cnt++;
                   bfs(i,j,grid,visited);
                  
                }
            }
        }
        return cnt;
        
    }
};
