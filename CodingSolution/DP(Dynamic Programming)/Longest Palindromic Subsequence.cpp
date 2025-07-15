class Solution {
public:
//using memoization
    int solve(string text1, string text2) {
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
   ************************************************************************************************
//using tabulation space optimize
    int solve(string text1, string text2) {
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

    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        return solve(s,rev);

    }
};
