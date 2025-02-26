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
    void construct(TreeNode* root,vector<int> &inorder)
    {
        if(root==NULL)
        {
            return ;
        }
        construct(root->left,inorder);
        inorder.push_back(root->val);
        construct(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        construct(root,inorder);
        int i=0,j=inorder.size()-1;
        int sum=0;
        while(i<j)
        {
          int sum=inorder[i]+inorder[j];
          if(sum==k)
          {
            return true;
          }
          if(sum<k)
          {
            i++;
          }
          else
          {
            j--;
          }
        }
        return false;
    }
};
