//gfg solution
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
    string postToInfix(string exp) {
        stack<string> st;
        string ans="";
        for(int i=0;i<exp.length();i++)
        {
            if(isalpha(exp[i]))
            {
                 // Create an string with one occurence of exp[i]
                st.push(string(1,exp[i]));
            }
            else
            {
                string s2=st.top();
                st.pop();
                string s1=st.top();
                st.pop();
                string res = "(" + s1 + exp[i] + s2 + ")";
                st.push(res);
            }
        }
        return st.top();
        
    }
};
