class Solution {
public:
//Using Memoization
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
        vector<int> dp(n+1,-1);
        return  solve(n-1,arr,dp);

    }
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************

//using tabulation
    int rob(vector<int>& arr)
    {
        int n=arr.size();
        vector<int> dp(n+1,0);
        dp[0]=arr[0];


        for(int i=1;i<n;i++)
        {
            int inc=arr[i];
            if(i-2>=0)
            {
                inc=dp[i-2]+arr[i];
            }
             int exc=dp[i-1];
            dp[i]=max(inc,exc);
            
        }
        return dp[n-1];
        

    }
};
