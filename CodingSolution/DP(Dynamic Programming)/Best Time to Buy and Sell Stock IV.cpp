class Solution {
public:
//using memoization
    int solve(vector<int>& prices, int index, int operation, int k,
              vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }

        if (operation == 2 * k) {
            return 0;
        }
        if (dp[index][operation] != -1) {
            return dp[index][operation];
        }
        int profit = 0;
        if (operation % 2 == 0) {
            int buykaro =
                -prices[index] + solve(prices, index + 1, operation + 1, k, dp);
            int skipkaro = solve(prices, index + 1, operation, k, dp);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro =
                prices[index] + solve(prices, index + 1, operation + 1, k, dp);
            int skipkaro = solve(prices, index + 1, operation, k, dp);
            profit = max(sellkaro, skipkaro);
        }
        return dp[index][operation] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k,-1));
        return solve(prices,0,0,k,dp);
    }
************************************************************************************************************************************************
//using tabulation
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k+1, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int operation = 2*k-1; operation >= 0; operation--) {
                int profit = 0;
                if (operation % 2 == 0) {
                    int buykaro = -prices[index] + dp[index + 1][operation + 1];
                    int skipkaro = dp[index + 1][operation];
                    profit = max(buykaro, skipkaro);
                } else {
                    int sellkaro = prices[index] + dp[index + 1][operation + 1];
                    int skipkaro = dp[index + 1][operation];
                    profit = max(sellkaro, skipkaro);
                }
                 dp[index][operation] = profit;
            }
        }
        return dp[0][0];
    }

**********************************************************************************************************************************
//using space optimized

     int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
      //  vector<vector<int>> dp(n + 1, vector<int>(2 * k+1, 0));
        vector<int> curr(2*k+1,0);
        vector<int> next(2*k+1,0);
        for (int index = n - 1; index >= 0; index--) {
            for (int operation = 2*k-1; operation >= 0; operation--) {
                int profit = 0;
                if (operation % 2 == 0) {
                    int buykaro = -prices[index] + next[operation + 1];
                    int skipkaro = next[operation];
                    profit = max(buykaro, skipkaro);
                } else {
                    int sellkaro = prices[index] + next[operation + 1];
                    int skipkaro = next[operation];
                    profit = max(sellkaro, skipkaro);
                }
                 curr[operation] = profit;
            }
            next=curr;
        }
        return next[0];
    }
};
