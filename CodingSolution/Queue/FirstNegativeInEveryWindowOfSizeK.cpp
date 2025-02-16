//GFG solution
class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> ans;
        //for first k size window
        for(int i=0;i<k;i++)
        {
            if(arr[i]<0)
            {
                q.push(i);
            }
        }
        if(!q.empty())
        {
            ans.push_back(arr[q.front()]);
        }
        else
        {
            ans.push_back(0);
        }
        //remaining windows
        for(int i=k;i<arr.size();i++)
        {
           while(!q.empty() && i-q.front()>=k)
           {
               q.pop();
           }
           //push the index 
           if(arr[i]<0)
           {
             q.push(i);
           }
           int val=(!q.empty()?arr[q.front()]:0);
            ans.push_back(val);
        }
        return ans;
    }
};
