class Solution {
public:
   using memoization
     int solve(int n,vector<int> &dp,vector<int> &cost)
     {
        if(n==0)
        {
            return cost[0];
        }
        if(n==1)
        {
            return cost[1];
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n]=min(solve(n-1,dp,cost),solve(n-2,dp,cost))+cost[n];
        return dp[n];
     }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(n-1,dp,cost),solve(n-2,dp,cost));
    }
    
*********************************************************************************************************************************************************
    //using tabulation
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
         vector<int> dp(n+1,0);
         dp[0]=cost[0];
         dp[1]=cost[1];
         for(int i=2;i<n;i++)
         {
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
         }
         return min(dp[n-1],dp[n-2]);
    }
};
