class Solution {
public:
    vector<int> findnext(vector<int> heights)
    {
        int n=heights.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n,-1);
        for(int i=heights.size()-1;i>=0;i--)
        {
           int curr=heights[i];
           while(st.top()!=-1 && heights[st.top()]>=curr)
           {
            st.pop();
           }
           ans[i]=st.top();
           st.push(i);
        }
        return ans;
    }
    vector<int> findprev(vector<int> heights)
    {
        int n=heights.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
           int curr=heights[i];
           while(st.top()!=-1 && heights[st.top()]>curr)
           {
            st.pop();
           }
           ans[i]=st.top();
           st.push(i);
        }
        return ans;
    }
    int largestArea(vector<int> heights) {
        int n=heights.size();
        vector<int> next(n,-1);
        next=findnext(heights);
        vector<int> prev(n,-1);
        prev=findprev(heights);
        int maxarea=INT_MIN;
        int l=0,b=0,area=0;
        for(int i=0;i<n;i++)
        {
             l=heights[i];
            if(next[i]==-1)
            {
                next[i]=n;
            }
             b=next[i]-prev[i]-1;
            int area=l*b;
            maxarea=max(maxarea,area);

        }
        return maxarea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j]=matrix[i][j]-'0';
            }
        }
        int area=largestArea(mat[0]);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]!=0)
                {
                    mat[i][j]=mat[i][j]+mat[i-1][j];
                }
                else
                {
                    mat[i][j]=0;
                }
               
            }
             area=max(area,largestArea(mat[i]));
        }
        return area;

        
    }
};
