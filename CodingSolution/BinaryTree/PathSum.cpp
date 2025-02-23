/**Leetcode solution
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void solve(TreeNode* root,vector<int> &ans,int k,bool &target)
    {
        if(root==NULL)
        {
            return ;
        }
        ans.push_back(root->val);
        solve(root->left,ans,k,target);
        solve(root->right,ans,k,target);
        int sum=0;
        int n=ans.size();
        if(root->left==NULL && root->right==NULL)
        {
        for(int i=n-1;i>=0;i--)
        {
           sum+=ans[i];
        }
        if(sum==k)
           {
               target=true;
           }
        }
        ans.pop_back();
       
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        bool target=false;
       solve(root,ans,targetSum,target);
       return target;
    }
};
