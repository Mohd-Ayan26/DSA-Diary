//GFG
class Solution {
  public:
  //using memoization
    int solve(vector<int> &wt,vector<int> &val,int w,int index,vector<vector<int>> &dp)
    {
        if(index==0)
        {
            if(wt[0]<=w)
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }
        if(dp[index][w]!=-1)
        {
            return dp[index][w];
        }
        
        int inc=0;
        if(wt[index]<=w)
        {
             inc=val[index]+solve(wt,val,w-wt[index],index-1,dp);
        }
        int exc=solve(wt,val,w,index-1,dp);
        dp[index][w]=max(inc,exc);
        return  dp[index][w];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return solve(wt,val,W,n-1,dp);
        
    }
***************************************************************************************************************************************************************    
    //using tabulation
    int knapsack(int W, vector<int> &val, vector<int> &wt){
        int n=wt.size();
        if (n == 0 || W <= 0) {
        return 0;
    }
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        for (int cap = wt[0]; cap <= W; ++cap) {
        if (wt[0] <= W) {
            dp[0][cap] = val[0];
        }
    }
        
      for(int i=1;i<n;i++)
      {
          for(int cap=0;cap<=W;cap++)
          {
              int inc=0;
              if(wt[i]<=cap && cap-wt[i]>=0)
              {
                    inc=val[i]+dp[i-1][cap-wt[i]];
              }
               
              int exc=dp[i-1][cap];
        
               
              dp[i][cap]=max(inc,exc);
          }
      }
      return dp[n-1][W];
    }
   *************************************************************************************************************************************************************

    //space optimize
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n=wt.size();
        if (n == 0 || W <= 0) 
        {
        return 0;
        }
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        for (int cap = wt[0]; cap <= W; ++cap) 
        {
        if (wt[0] <= W) {
            prev[cap] = val[0];
        }
        }
        for(int i=1;i<n;i++)
        {
          for(int cap=0;cap<=W;cap++)
          {
              int inc=0;
              if(wt[i]<=cap && cap-wt[i]>=0)
              {
                    inc=val[i]+prev[cap-wt[i]];
              }
               
              int exc=prev[cap];
        
              curr[cap]=max(inc,exc);
          }
          prev=curr;
      }
      return prev[W];
        
    }
    
    
};
