class Solution {
public:
   
    int solve(vector<vector<int>> &matrix, int n, int i, int j, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= n)
        {
            return 1e9; // large value for out of bounds
        }
        if (i == n - 1)
        {
            return matrix[i][j]; // base case: last row
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int down_left = solve(matrix, n, i + 1, j - 1, dp);
        int down = solve(matrix, n, i + 1, j, dp);
        int down_right = solve(matrix, n, i + 1, j + 1, dp);

        dp[i][j] = matrix[i][j] + min({down_left, down, down_right});
        return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // correct size
        int ans = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            ans = min(ans, solve(matrix, n, 0, j, dp));
        }

        return ans;
    }


};
