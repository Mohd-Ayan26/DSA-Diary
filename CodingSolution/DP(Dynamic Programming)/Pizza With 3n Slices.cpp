class Solution {
public:
    int solve(vector<int> &slices,int n,int index,int slice,vector<vector<int>> &dp)
    {
        if(slice==0 || index>n)
        {
            return 0;
        }

        if(dp[index][slice]!=-1)
        {
            return dp[index][slice];
        }

        int inc=slices[index]+solve(slices,n,index+2,slice-1,dp);
        int exc=solve(slices,n,index+1,slice,dp);
        return dp[index][slice]=max(inc,exc);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        vector<vector<int>> dp1(n,vector<int>(n,-1));
        int ans1=solve(slices,n-2,0,n/3,dp1);
        vector<vector<int>> dp2(n,vector<int>(n,-1));
        int ans2=solve(slices,n-1,1,n/3,dp2);
        return max(ans1,ans2);

    }
};
