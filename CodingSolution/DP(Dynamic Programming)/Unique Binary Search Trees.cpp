class Solution {
public:
//using memoization
    int solve(int n,vector<int> &dp)
    {
        if(n<=1)
        {
            return 1;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=ans+solve(i-1,dp)*solve(n-i,dp);
        }
        return dp[n]=ans;


    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
************************************************************************************************************************************************
//using tabulation

    int numTrees(int n)
    {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;

        for(int i=2;i<=n;i++)
        {
             int ans=0;
             for(int j=1;j<=i;j++)
             {
                ans=ans+dp[j-1]*dp[i-j];
             }

               dp[i]=ans;
        }
         return dp[n];

    }
};
