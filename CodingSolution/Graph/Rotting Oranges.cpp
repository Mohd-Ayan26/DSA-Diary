//leetcode
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int cntFresh=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 if(grid[i][j]==2)
                 {
                    visited[i][j]=2;
                    q.push({{i,j},0});
                 }
                 

                  if(grid[i][j]==1) cntFresh++;
                 

            }
        }
        int time=0;
        int cnt=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(t,time);

            int dr[4] = {-1, 1, 0, 0};
            int dc[4] = {0, 0, -1, 1};

            for(int i=0;i<4;i++)
            {
                int newR=r+dr[i];
                int newC=c+dc[i];

                if(newR>=0 && newR<m && newC>=0 && newC<n && visited[newR][newC]!=2 && grid[newR][newC]==1)
                {
                    q.push({{newR,newC},t+1});
                    visited[newR][newC]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntFresh) return -1;
        return time;
    }
};
