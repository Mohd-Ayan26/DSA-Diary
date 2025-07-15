class Solution {
public:
 //using memoization
   int solve(vector<int> &nums1,vector<int> &nums2,int index,int swapped,vector<vector<int>> &dp)
   {
    if(index==nums1.size())
    {
        return 0;
    }
    if(dp[index][swapped]!=-1)
    {
        return dp[index][swapped];
    }
    int prev1=nums1[index-1];
    int prev2=nums2[index-1];
    
    if(swapped)
    {
        swap(prev1,prev2);
    }
    int ans=INT_MAX;
    if(nums1[index]>prev1 && nums2[index]>prev2)
    {
        ans=solve(nums1,nums2,index+1,0,dp);
    }
    if(nums1[index]>prev2 && nums2[index]>prev1)
    {
        ans=min(ans,1+solve(nums1,nums2,index+1,1,dp));
    }
     return dp[index][swapped]=ans;

   }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(nums1,nums2,1,false,dp);
    }

************************************************************************************************************************************************************

//using tabulation
   int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        // dp[n + 1][0] = 0;
        // dp[n + 1][1] = 0;


        for(int i=n;i>=1;i--)
        {
            for(int swapped=1;swapped>=0;swapped--)
            {
                int prev1=nums1[i-1];
                int prev2=nums2[i-1];
                if(swapped)
                {
                    swap(prev1,prev2);
                }
                int ans=INT_MAX;
                if(nums1[i]>prev1 && nums2[i]>prev2)
                {
                   ans=dp[i+1][0];
                }
                if(nums1[i]>prev2 && nums2[i]>prev1)
                {
                    ans=min(1+dp[i+1][1],ans);
                }
                dp[i][swapped]=ans;
            }
        }
        return dp[1][0];
    }
};
