class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    bool knowns(vector<vector<int>> mat,int a,int b,int n)
    {
        if(mat[a][b]==1)
        {
            return true;
        }
        return false;
    }
    int celebrity(vector<vector<int> >& mat) {
        stack<int> st;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }

       
        while(st.size()>1)
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(knowns(mat,a,b,n))
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
            
        }
        int curr=st.top();
        //verify
        int zerocount=0;
        for(int i=0;i<n;i++)
        {
            if(mat[curr][i]==0)
            {
                zerocount++;
            }
            
        }
        if(zerocount!=n)
        {
            return -1;
        }
        int onecount=0;
        for(int i=0;i<n;i++)
        {
            if(mat[i][curr]==1)
            {
                onecount++;
            }
            
        }
        if(onecount!=n-1)
        {
            return -1;
        }
        
        return curr;
        
    }
};
