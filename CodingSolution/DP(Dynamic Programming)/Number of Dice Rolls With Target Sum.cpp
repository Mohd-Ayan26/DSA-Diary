#define MOD 1000000007
class Solution {
public:

 // using memoization 
    int solve(int dices,int faces,int target,vector<vector<int>> &dp)
    {
        if(target<0)
        {
            return 0;
        }
        if(target!=0 && dices==0)
        {
            return 0;
        }
        if(target==0 && dices!=0)
        {
            return 0;
        }
        if(target==0 && dices==0)
        {
            return 1;
        }
        if(dp[dices][target]!=-1)
        {
            return dp[dices][target];
        }

        long long ans=0;
        for(int i=1;i<=faces;i++)
        {
            ans=(ans+solve(dices-1,faces,target-i,dp)%MOD)%MOD;
        }
        return dp[dices][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }

******************************************************************************************************************************************************
    int numRollsToTarget(int n, int k, int target) {
    const int mod = 1e9+7;
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    dp[0][0] = 1; // Base case: 0 dice to make sum 0.

    for(int dice = 1; dice <= n; dice++) {
        for(int t = 1; t <= target; t++) {
            for(int face = 1; face <= k; face++) {
                if(t - face >= 0) {
                    dp[dice][t] = (dp[dice][t] + dp[dice-1][t-face]) % mod;
                }
            }
        }
    }
    return dp[n][target];
    }
};
