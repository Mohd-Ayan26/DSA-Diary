class Solution {
public:
//using memoization
     int solve(int n,vector<int> &arr,vector<int> &dp)
    {
        if(n==0)
        {
            return arr[0];
        }
        if(n<0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        
        int inc=solve(n-2,arr,dp)+arr[n];
        int excl=solve(n-1,arr,dp);
        dp[n]=max(inc,excl);
        return dp[n];
    }
    int rob(vector<int>& arr) {
         int n=arr.size();
         if(n==1)
         {
            return arr[0];
         }
        vector<int> dp1(n,-1);
         vector<int> dp2(n,-1);
        vector<int> arr1;
        vector<int> arr2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                arr1.push_back(arr[i]);
            }
            if(i!=n-1)
            {
                arr2.push_back(arr[i]);
            }
        }
        return max(solve(arr1.size()-1,arr1,dp1),solve(arr2.size()-1,arr2,dp2));

    }
};
