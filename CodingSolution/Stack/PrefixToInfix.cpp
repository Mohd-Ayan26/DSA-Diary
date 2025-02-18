//GFG solution
class Solution {
    bool isalpha(char exp)
    {
        if(exp>='a' && exp<='z' || exp>='A' && exp<='Z'||exp>='0' && exp<='9' )
        {
            return true;
        }
        return false;
    }
  public:
    string preToInfix(string pre_exp) {
        stack<string> st;
        string ans="";
        for(int i=pre_exp.length()-1;i>=0;i--)
        {
            if(isalpha(pre_exp[i]))
            {
                 // Create an string with one occurrence of exp[i]
                st.push(string(1,pre_exp[i]));
            }
            else
            {
                string s2=st.top();
                st.pop();
                string s1=st.top();
                st.pop();
                string res = ")" + s1 + pre_exp[i] + s2 + "(";
                st.push(res);
            }
        }
        ans=st.top();
        reverse(ans.begin(),ans.end());
        return ans;
        
    
    }
};
