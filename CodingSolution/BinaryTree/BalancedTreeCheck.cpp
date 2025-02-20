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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        int ans=max(left,right)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool ans=abs(maxDepth(root->left)-maxDepth(root->right))<=1;
        if(left && right && ans)
        {
            return true;
        }
        else
        {
            return false;

        }
        
    }
};

OR
/*********************************************************************************************************************************************************************
*********************************************************************************************************************************************************************/

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
   
    pair<bool,int> Balanced(TreeNode* root) {
        if(root==NULL)
        {
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left=Balanced(root->left);
        pair<bool,int> right=Balanced(root->right);
        bool leftans=left.first;
        bool rightans=right.first;
        bool diff=abs(left.second-right.second)<=1;
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        if(leftans && rightans && diff)
        {
            ans.first=true;
        }
        else
        {
            ans.first=false;

        }
        return ans;
        
    }
       
     bool isBalanced(TreeNode* root) 
    {
        pair<bool,int> ans=Balanced(root);
        return ans.first;
        
    }
};
