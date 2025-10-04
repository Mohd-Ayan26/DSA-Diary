class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> output,int k,int n,int start)
    {
        if(n==0 && output.size()==k)
        {
            ans.push_back(output);
            return;
        }
        if(n<0 ||output.size()>k)
        {
            return;
        }

        for(int i=start;i<=9;i++)
        {
            output.push_back(i);
            solve(ans,output,k,n-i,i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        int start=1;
        solve(ans,output,k,n,start);
        return ans;
    }
};
