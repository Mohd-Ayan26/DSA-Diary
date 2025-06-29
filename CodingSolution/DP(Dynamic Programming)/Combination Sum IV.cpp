  #define MOD 1000000007
class Solution {
public:
//using memoization
    int solve(vector<int> &nums,int target,int index,vector<int> &dp)
    {
        if(target==0)
        {
            return 1;
        }
        if(target<0)
        {
            return 0;
        }
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=solve(nums,target-nums[i],index+1,dp);
        }
        dp[target]=ans;
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return solve(nums,target,n-1,dp);

    }


******************************************************************************************************************************************************************
//using tabulation
      int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }

        vector<uint> dp(target + 1, 0);
        dp[0] = 1;

        for (int tar = 1; tar <= target; ++tar) {
            for (int num : nums) {
                if (tar - num >= 0) {
                    dp[tar]+=dp[tar - num] ;
                }
            }
        }

        return dp[target];
    }
};
