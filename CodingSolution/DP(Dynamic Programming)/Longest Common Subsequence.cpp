class Solution {
public:
//using memoization
    int solve(string text1, string text2, int i, int j,
              vector<vector<int>>& dp) {
        if (i == text1.length()) {
            return 0;
        }
        if (j == text2.length()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + solve(text1, text2, i + 1, j + 1, dp);
        } else {
            ans = max(solve(text1, text2, i + 1, j, dp),
                      solve(text1, text2, i, j + 1, dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(text1,text2,0,0,dp);
    
    }
***********************************************************************************************************
//using tabulation
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int ans = 0;
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    ans = 1 + dp[i + 1][j + 1];
                } else {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
                 dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
**********************************************************************************************************************
//using tabulation(space optimized)
    int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.length();
    int n2 = text2.length();
    vector<int> curr(n2 + 1, 0);
    vector<int> next(n2 + 1, 0);

    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            if (text1[i] == text2[j]) {
                curr[j] = 1 + next[j + 1];
            } else {
                curr[j] = max(next[j], curr[j + 1]);
            }
        }
        next = curr;
    }
    return next[0];
}

};
