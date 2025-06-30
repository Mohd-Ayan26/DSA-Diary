class Solution {
public:
    //using memoization
    int solve(vector<int> &days,vector<int> &costs,int n,int index,vector<int> &dp)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int option1=costs[0]+solve(days,costs,n,index+1,dp);
        int i;
        for(i=index;i<n && days[i]<days[index]+7;i++);
        int option2=costs[1]+solve(days,costs,n,i,dp);
        for(i=index;i<n && days[i]<days[index]+30;i++);
        int option3=costs[2]+solve(days,costs,n,i,dp);
        dp[index]=min(option1,min(option2,option3));
        return dp[index];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        return solve(days,costs,n,0,dp);
    }
*************************************************************************************************************************************************************
    
    //using tabulation
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n=days.size();
        vector<int> dp(n+1,0);
        for(int index=n-1;index>=0;index--)
        {
            int option1=costs[0]+dp[index+1];
            int i;
            for(i=index;i<n && days[i]<days[index]+7;i++);
            int option2=costs[1]+dp[i];
            for(i=index;i<n && days[i]<days[index]+30;i++);
            int option3=costs[2]+dp[i];
            dp[index]=min(option1,min(option2,option3));
        }
        return dp[0];
    }
****************************************************************************************************************************************************************
  
    //space optimize
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int ans=0;
        queue<pair<int,int>> week;
        queue<pair<int,int>> month;
        for(auto day:days)
        {
            while(!week.empty() && week.front().first+7<=day)
            {
                week.pop();
            }
            while(!month.empty() && month.front().first+30<=day)
            {
                month.pop();
            }
            week.push(make_pair(day,ans+costs[1]));
            month.push(make_pair(day,ans+costs[2]));
            ans=min(ans+costs[0],min(week.front().second,month.front().second));
        }
        return ans;
    }
};
