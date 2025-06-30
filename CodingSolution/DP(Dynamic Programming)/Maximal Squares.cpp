//leetcode
class Solution {
public:
//using memoization
   int solve(vector<vector<char>> &matrix, int row, int col, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if(i>=row || j>=col)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right=solve(matrix,row,col,i,j+1,maxi,dp);
        int diagonal=solve(matrix,row,col,i+1,j+1,maxi,dp);
        int bottom=solve(matrix,row,col,i+1,j,maxi,dp);

        if(matrix[i][j] == '1')
        {
            dp[i][j]=1+min(right,min(bottom,diagonal));
            maxi=max(dp[i][j],maxi);
        }
        else
        {
            dp[i][j]=0;
        }
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int maxi=0;
        vector<vector<int>> dp(row+1,vector<int>(col+1,-1));
        solve(matrix,row,col,0,0,maxi,dp);
        return maxi*maxi;
    }

******************************************************************************************************************************************************************
//using tabulation
       int maximalSquare(vector<vector<char>>& matrix)
       {
           int row=matrix.size();
           int col=matrix[0].size();
           int maxi=0;
           vector<vector<int>> dp(row+1,vector<int>(col+1,0));
           for(int i=row-1;i>=0;i--)
           {
            for(int j=col-1;j>=0;j--)
            {
                int right=dp[i][j+1];
                int diagonal=dp[i+1][j+1];
                int bottom=dp[i+1][j];

                if(matrix[i][j] == '1')
              {
                  dp[i][j]=1+min(right,min(bottom,diagonal));
                  maxi=max(dp[i][j],maxi);
              }
               else
               {
                 dp[i][j]=0;
               }
             }
           }
           return maxi*maxi;

       }

};
