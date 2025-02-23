/*GFG solution
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void solve(Node* root,vector<int> &ans,int k,int &count)
    {
        if(root==NULL)
        {
            return ;
        }
        ans.push_back(root->data);
        solve(root->left,ans,k,count);
        solve(root->right,ans,k,count);
        int sum=0;
        int n=ans.size();
        for(int i=n-1;i>=0;i--)
        {
           sum+=ans[i];
           if(sum==k)
           {
               count++;
           }
        }
        ans.pop_back();
    }
    int sumK(Node *root, int k) {
       vector<int> ans;
       int  count=0;
       solve(root,ans,k,count);
       return count;
       
       
    }
};
