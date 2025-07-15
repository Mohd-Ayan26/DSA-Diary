class Solution {
public:
//using memoization
     int solve(vector<int>& prices, int index, int buy,int fee,
              vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }
        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }
        int profit = 0;
        if (buy) {
            int buykaro = -prices[index] + solve(prices, index + 1, 0,fee, dp);
            int skipkaro = 0 + solve(prices, index + 1, 1,fee, dp);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[index]-fee + solve(prices, index + 1, 1,fee, dp);
            int skipkaro = solve(prices, index + 1, 0,fee ,dp);
            profit = max(sellkaro, skipkaro);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1,fee,dp);
    }

**********************************************************************************************************************************
//using tabulation (space optimized)
    int maxProfit(vector<int>& prices ,int fee) {
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int buykaro =-prices[index] + next[0];
                    int skipkaro = 0 + next[1];
                    profit = max(buykaro, skipkaro);
                } 
                else {
                    int sellkaro =prices[index]-fee + next[1];
                    int skipkaro = next[0];
                    profit = max(sellkaro, skipkaro);
                }
                 curr[buy] = profit;
            }
            next=curr;
        }
        return next[1];
    }
};
