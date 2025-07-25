class Solution {
public:
    bool solve(string &s,string &p,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        if(i>=0 && j<0)
        {
            return false;
        }
        if(i<0 && j>=0)
        {
            for(int k=0;k<=j;k++)
            {
                if(p[k]!='*')
                {
                    return false;
                }
                
            }
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
         bool ans = false;
        if(s[i]==p[j] ||p[j]=='?')
        {
            ans=solve(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*')
        {
            ans=solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp);
        }
        else
        {
           ans=false;
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        return solve(s,p,s.length()-1,p.length()-1,dp);
    }
};
