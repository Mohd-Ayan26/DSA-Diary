class Solution {
  public:
   //using memoization
    // Function to find the maximum number of cuts.
    int solve(int n,int x,int y,int z,vector<int> &dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(n<0)
        {
            return INT_MIN;
        }
          if(dp[n]!=-1)
          {
              return dp[n];
          }
        int first=solve(n-x,x,y,z,dp)+1;
        int second=solve(n-y,x,y,z,dp)+1;
        int third=solve(n-z,x,y,z,dp)+1;
        dp[n]=max(first,max(second,third));
        return dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n+1,-1);
        int ans=solve(n,x,y,z,dp);
        if(ans<=0)
        {
            return 0;
        }
        return ans;
        
    }
   ********************************************************************************************************************************************************************
   *****************************************************************************************************************************************************************

//using tabulation
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,INT_MIN);
        dp[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            if(i-x>=0)
            {
                dp[i]=max(dp[i],dp[i-x]+1);
            }
            if(i-y>=0)
            {
                dp[i]=max(dp[i],dp[i-y]+1);
            }
            if(i-z>=0)
            {
                dp[i]=max(dp[i],dp[i-z]+1);
            } 
            
        }
        if(dp[n]<=0) 
        {
            return 0;
        }
        return dp[n];
    }
};
