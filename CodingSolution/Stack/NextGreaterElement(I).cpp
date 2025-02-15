class Solution {
public:
    void solve(vector<int> num2,map<int,int> &ans)
    {
        stack<int> st;
        st.push(-1);
        for(int i=num2.size()-1;i>=0;i--)
        {
           int curr=num2[i];
           while(st.top()!=-1 && curr>st.top())
           {
            st.pop();
           }
           ans[curr]=st.top();
           st.push(curr);
        }

    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> ans;
        solve(nums2,ans);
        vector<int> result(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++)
        {
            result[i]=ans[nums1[i]];

        }
        return result;
    }
};
