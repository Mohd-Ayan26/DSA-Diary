class Solution {
public: 
    //using memoization
    int solve(int n,vector<int> &dp)
    {
        if(n==0 || n==1)
        {
            return n;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n]=solve(n-1,dp)+solve(n-2,dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }


****************************************************************************************************************************************************************
      //Using tabulation
       int fib(int n) 
        { 
            vector<int> dp(n+1,0);
            if(n==1 || n==0)
            {
                return n;
            }
            dp[0]=0;
            dp[1]=1;
            for(int i=2;i<=n;i++)
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[n];
        }
};
