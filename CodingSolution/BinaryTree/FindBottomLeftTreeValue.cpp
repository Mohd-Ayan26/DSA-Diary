/**
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
    int maxdepth(TreeNode* root)
    {
        if(root==NULL)
        {
            return -1 ;

        }
        int  left=maxdepth(root->left);
        int  right=maxdepth(root->right);
        return max(left,right)+1;
    }
    void find(TreeNode* root,int depth,int &ans,int level)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            if(level==depth)
            {
                ans=root->val;
            }
        }
        find(root->right,depth,ans,level+1);
        find(root->left,depth,ans,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int depth=maxdepth(root);
        int ans;
        int level;
        find(root,depth,ans,level);
        return ans;
    }
};
