//leetcode solution
class Solution {
public:
    vector<int> findnext(vector<int> arr)
    {
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n,n);
        for(int i=n-1;i>=0;i--)
        {
                while(!st.empty() && arr[st.top()]>=arr[i] )
                {
                    st.pop();
                }
                ans[i]=st.empty()?n:st.top();
                st.push(i);
        }
        return ans;
    }
    vector<int> findprev(vector<int> arr)
    {
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
                while(!st.empty() && arr[st.top()]>arr[i] )
                {
                    st.pop();
                }
                ans[i]=st.empty()?-1:st.top();
                st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nextSmall=findnext(arr);
        vector<int> prevSmall=findprev(arr);
        long long sum=0;
        int mod= 1000000007;
        for(int i=0;i<arr.size();i++)
        {
            long long rs=nextSmall[i]-i;
            long long ls=i-prevSmall[i];
            //finding range of left and right side for the element
            //product them to find number of ways
            long long prod=((ls)*(rs));
            //mutipling number of ways with element to sum
            long long totalsum=(prod*arr[i]);
            sum=(sum+totalsum)%mod;
        }
        return (sum);

    }
};
