class Solution {
public:
    vector<int> findnext(vector<int> nums)
    {
        int n=nums.size();
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        //virtually increase the size of array
        for(int i=2*nums.size()-1;i>=0;i--)
        {
            //As the size double , so to get real index do i%n
            int curr=nums[i%n];
            while(!st.empty() && st.top()<=curr)
            {
               st.pop();
            }
            //do not update value till i<n
            if(i<n)
            {
               ans[i] = (st.empty()) ? -1 : st.top();
            }   
            
           
            st.push(curr);
        }
        return ans;
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) {
       return findnext(nums);
    }
};
