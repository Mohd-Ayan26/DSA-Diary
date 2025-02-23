/**leetcode solution
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
     void solve(TreeNode* root,vector<int> &ans,int k,bool &target,vector<vector<int>> &res)
    {
        if(root==NULL)
        {
            return ;
        }
        ans.push_back(root->val);
        solve(root->left,ans,k,target,res);
        solve(root->right,ans,k,target,res);
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
               res.push_back(ans);
           }
        }
        ans.pop_back();
       
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        bool target=false;
        vector<vector<int>> res;
        solve(root,ans,targetSum,target,res);
        return res;
    }
};
