class Solution {
public:
//using memoization
    int solve(vector<int> &nums,int index,int target,vector<vector<int>> &dp)
    {
        if(target<0)
        {
            return 0;
        }

        if(target==0)
        {
            return 1;
        }
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index][target]!=-1)
           return dp[index][target];

        int inc=solve(nums,index+1,target-nums[index],dp);
        int exc=solve(nums,index+1,target,dp);
        return dp[index][target]=inc or exc;
    }
    bool canPartition(vector<int>& nums) {
          int n=nums.size();
          int sum=0;
          for(int i=0;i<n;i++)
          {
             sum+=nums[i];
          }
          if(sum & 1)//odd
          {
            return 0;
          }
    
          int target=sum/2;
          vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
          return solve(nums,0,target,dp);

    }

*******************************************************************************************************************************************************
//using tabulation
     bool canPartition(vector<int>& nums) {
          int n=nums.size();
          int sum=0;
          for(int i=0;i<n;i++)
          {
             sum+=nums[i];
          }
          if(sum & 1)//odd
          {
            return 0;
          }
    
          int target=sum/2;
          vector<vector<int>> dp(n+1,vector<int>(target+1,0));
          for(int i=0;i<n;i++)
          {
            dp[i][0]=1;
          }

          for(int i=n-1;i>=0;i--)
          {
            for(int t=1;t<=target;t++)
            {
                int inc=0;
                if( t-nums[i]>=0)
                {
                    inc=dp[i+1][t-nums[i]];
                }
                int exc=dp[i+1][t];
                 dp[i][t]=inc or exc;
            }
          }
          return dp[0][target];

    }
};
