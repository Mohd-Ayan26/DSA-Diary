class Solution {
public:

//using memoization
    int solve(int n,vector<int> &coins,int x,vector<int> &dp)
    {
        if(x==0)
        {
            return 0;
        }
        if(x<0)
        {
            return INT_MAX;
        }
        if(dp[x]!=-1)
        {
            return dp[x];
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int ans=solve(n,coins,x-coins[i],dp);
            if(ans!=INT_MAX)
            {
                mini=min(mini,ans+1);
            }
        }
        dp[x]=mini;
        return dp[x];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,-1);
        int ans=solve(n,coins,amount,dp);
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
**********************************************************************************************************************************************************
//using tabulation
     int coinChange(vector<int>& coins, int amount) 
     {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
                {
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[amount]==INT_MAX)
        {
            return -1;
        }
        return dp[amount];
     }
};
