//GFG
#define MOD 1000000007
class Solution {
  public:
//using memoization
    int solve(int n, int k, vector<int> &dp)
    {
        if(n==1)
        {
            dp[n]=k;
            return dp[n];
        }
        
        if(n==2)
        {
            int mul = (1LL * k * (k-1)) % MOD;
            int add = (mul + k) % MOD;
            dp[n]=add;
            return dp[n];
        }
        
        if(dp[n]!=-1)
            return dp[n];
        
        int first = (1LL * (k-1) * solve(n-1,k,dp)) % MOD;
        int second = (1LL * (k-1) * solve(n-2,k,dp)) % MOD;
        dp[n] = (first + second) % MOD;
        return dp[n];
    }
    int countWays(int n, int k) {
        // code here
        vector<int> dp(n+1,-1);
        solve(n,k,dp);
        return dp[n];
    }
******************************************************************************************************************************************************************
//using tabulation
    int countWays(int n, int k)
    {
        vector<int> dp(n+1,0);
        dp[1]=k;
        int mul = (1LL * k * (k-1)) % MOD;
        int add = (mul + k) % MOD;
        dp[2]=add;
        for(int i=3;i<=n;i++)
        {
            int first = (1LL * (k-1) * dp[i-1]) % MOD;
            int second = (1LL * (k-1) *dp[i-2]) % MOD;
            dp[i] = (first + second) % MOD;
        }
        return dp[n];
    }
};
