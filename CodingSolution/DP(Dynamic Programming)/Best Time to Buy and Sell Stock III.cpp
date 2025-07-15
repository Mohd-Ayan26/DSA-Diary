class Solution {
public:
//using memoization
    int solve(vector<int>& prices, int index, int buy, int limit,
              vector<vector<vector<int>>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }
        if (limit == 0) {
            return 0;
        }
        if (dp[index][buy][limit] != -1) {
            return dp[index][buy][limit];
        }
        int profit = 0;
        if (buy) {
            int buykaro =
                -prices[index] + solve(prices, index + 1, 0, limit, dp);
            int skipkaro = 0 + solve(prices, index + 1, 1, limit, dp);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro =
                prices[index] + solve(prices, index + 1, 1, limit - 1, dp);
            int skipkaro = solve(prices, index + 1, 0, limit, dp);
            profit = max(sellkaro, skipkaro);
        }
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>
        dp(n+1,vector<vector<int>>(2,vector<int>(3,-1))); return
        solve(prices,0,1,2,dp);
    }
***********************************************************************************************************************************
//using tabulation

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit < 3; limit++) {
                int profit = 0;
                if (buy) {
                    int buykaro = -prices[index] + dp[index + 1][0][limit];
                    int skipkaro = 0 + dp[index + 1][1][limit];
                    profit = max(buykaro, skipkaro);
                } else {
                    int sellkaro = prices[index] + dp[index + 1][1][limit-1];
                    int skipkaro = dp[index + 1][0][limit];
                    profit = max(sellkaro, skipkaro);
                }
                dp[index][buy][limit] = profit;
                }
            }
        }
             return dp[0][1][2];
        }
****************************************************************************************************************************************************************
//using space optimized

        int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit < 3; limit++) {
                int profit = 0;
                if (buy) {
                    int buykaro = -prices[index] + next[0][limit];
                    int skipkaro = 0 + next[1][limit];
                    profit = max(buykaro, skipkaro);
                } else {
                    int sellkaro = prices[index] + next[1][limit-1];
                    int skipkaro = next[0][limit];
                    profit = max(sellkaro, skipkaro);
                }
                curr[buy][limit] = profit;
                }
            }
            next=curr;
        }
            return next[1][2];

        }

       
    };
