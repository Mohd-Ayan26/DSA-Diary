//GFG solution
class Solution {
  public:
  bool isalpha(char exp)
    {
        if(exp>='a' && exp<='z' || exp>='A' && exp<='Z' )
        {
            return true;
        }
        return false;
    }
    string postToPre(string post_exp) {
    stack<string> st;
        string ans="";
        for(int i=0;i<post_exp.length();i++)
        {
            if(isalpha(post_exp[i]))
            {
                 // Create an string with one occurrence of exp[i]
                st.push(string(1,post_exp[i]));
            }
            else
            {
                string s2=st.top();
                st.pop();
                string s1=st.top();
                st.pop();
                string res = post_exp[i] + s1 +  s2 ;
                st.push(res);
            }
        }
        ans=st.top();
        return ans;
    }
};
