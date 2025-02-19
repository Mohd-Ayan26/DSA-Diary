//leetcode solution
class Solution {
public:
    vector<int> findnext(vector<int> arr)
    {
       deque<int> q;
        int n=arr.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
                while(!q.empty() && q.back()<arr[i] )
                {
                    q.pop_back();
                }
                ans[i]=q.empty()?arr[i]:q.front();
                q.push_back(arr[i]);
        }
        return ans;
    }
    vector<int> findprev(vector<int> arr)
    {
        deque<int> q;
        int n=arr.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
               while(!q.empty() && q.back()<arr[i] )
                {
                    q.pop_back();
                }
                ans[i]=q.empty()?arr[i]:q.front();
                q.push_back(arr[i]);
        }
        return ans;
    }
    int trap(vector<int>& height) {
        //find array of next greater element
        vector<int> next=findnext(height);
        vector<int> prev=findprev(height);
        int ans=0;
        for(int i=0;i<height.size();i++)
        {
            int res=min(next[i],prev[i])-height[i];
                ans+=res;
        }
        return ans;
    }
};
