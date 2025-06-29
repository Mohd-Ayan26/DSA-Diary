#define MOD 1000000007
class Solution {
  public:
//using memoization
    int solve(int n,vector<int> &dp)
    {
        if(n==1 )
        {
            return 0;
        }
        if(n==2)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        
      int first=solve(n-1,dp)%MOD;
      int second=solve(n-2,dp)%MOD;
      dp[n]=((n-1)%MOD*(first+second)%MOD)%MOD;
       
      return dp[n];
    }
    
    int countDer(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
*****************************************************************************************************************************************************************
****************************************************************************************************************************************************************
//using Tabulation
    int countDer(int n) 
    {
        vector<int> dp(n+1,0);
        dp[1]=0;
        dp[2]=1;
        
        for(int i=3;i<=n;i++)
        {
            dp[i]=((i-1)%MOD*(dp[i-1]%MOD+dp[i-2]%MOD))%MOD;
        }
        return dp[n];
    }
    
};
