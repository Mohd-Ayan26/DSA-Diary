class Solution {
public:
    int solve(vector<int> &satisfaction,int n,int index,int time,vector<vector<int>> &dp)
    {
        if(index==n)
        {
            return 0;
        }
        if(dp[index][time]!=-1)
        {
            return dp[index][time];
        }
        int take=(time*satisfaction[index])+solve(satisfaction,n,index+1,time+1,dp);
        int nottake=solve(satisfaction,n,index+1,time,dp);
        dp[index][time]=max(take,nottake);
        return dp[index][time];


    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(satisfaction,n,0,1,dp);
    }
};
