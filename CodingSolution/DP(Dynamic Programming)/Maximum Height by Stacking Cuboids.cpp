class Solution {
public:
    bool check(vector<int> curr,vector<int> prev)
    {
       if( curr[0]>=prev[0] && curr[1]>=prev[1] && curr[2]>=prev[2])
          return true;

        return false;
    }
    int solve(vector<vector<int>> &cuboids,int n,int curr,int prev,vector<vector<int>> &dp)
    {
        if(curr==n)
        {
            return 0;
        }
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        
        int take=0;
        if(prev==-1 || check(cuboids[curr],cuboids[prev]))
            take=cuboids[curr][2]+solve(cuboids,n,curr+1,curr,dp);
        
        int ntake=solve(cuboids,n,curr+1,prev,dp);

        return dp[curr][prev+1]=max(take,ntake);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(int i=0;i<n;i++)
        {
            sort(cuboids[i].begin(),cuboids[i].end());
        }

        sort(cuboids.begin(),cuboids.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(cuboids,n,0,-1,dp);
    }
};
