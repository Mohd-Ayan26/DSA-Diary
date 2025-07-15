class Solution {
public:
//using memoization
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        if (i == a.length()) {
            return b.length() - j;
        }
        if (j == b.length()) {
            return a.length() - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j]) {
            ans = solve(a, b, i + 1, j + 1, dp);
        } else {
            int insert = 1 + solve(a, b, i, j + 1, dp);
            int del = 1 + solve(a, b, i + 1, j, dp);
            int replace = 1 + solve(a, b, i + 1, j + 1, dp);
            ans = min(insert, min(del, replace));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1,
        vector<int>(word2.length(),-1)); return solve(word1, word2, 0, 0,
        dp);
    }
***********************************************************************************************************
//using tabulation
    int minDistance(string a, string b) {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length()+1, 0));
        for (int j = 0; j < b.length(); j++) {
            dp[a.length()][j] = b.length() - j;
        }
        for (int i = 0; i < a.length(); i++) {
            dp[i][b.length()] = a.length() - i;
        }

        for (int i = a.length() - 1; i >= 0; i--) {
            for (int j = b.length() - 1; j >= 0; j--) {
                
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i + 1][j +1];
                } else {
                    int insert = 1 +dp[i][j + 1] ;
                    int del = 1 + dp[i + 1][j];
                    int replace = 1 + dp[i + 1][j + 1];
                    dp[i][j] = min(insert, min(del, replace));
                }
            }
        }
        return dp[0][0];
    }
};
