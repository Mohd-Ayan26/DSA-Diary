class Solution {
public:
    int solve(vector<int> &obstacles,int currlane,int currpos,vector<vector<int>> &dp)
    {
        int n=obstacles.size()-1;
        if(currpos==n)
        {
            return 0;
        }

        if(dp[currlane][currpos]!=-1)
        {
            return dp[currlane][currpos];
        }
        if(obstacles[currpos+1]!=currlane)
        {
            return dp[currlane][currpos]=solve(obstacles,currlane,currpos+1,dp);
        }
        else
        {
            int ans=INT_MAX;
            for(int i=1;i<=3;i++)
            {
                if(i!=currlane && i!=obstacles[currpos])
                    ans=min(ans,1+solve(obstacles,i,currpos,dp));
            }
            dp[currlane][currpos]=ans;
            return dp[currlane][currpos];

        }

    }
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n+1,-1));
        return solve(obstacles,2,0,dp);
    }
};
