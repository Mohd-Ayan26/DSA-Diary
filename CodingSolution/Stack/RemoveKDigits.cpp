//leetcode solution
class Solution {
public:
    // void reverse(string &ans)
    // {
    //    int i=0;
    //     j
    // }
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0')
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
            
        }
        while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }
        if(st.empty())
        {
            return "0";
        }
        string ans="";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        while(ans.size()!=0 && ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if(ans.size()==0)
        {
            return "0";
        }
        return ans;
    }
};
