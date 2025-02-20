/**leetcode 
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
      bool Symmetric(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
        {
            return true;
        }
        if(p==NULL && q!=NULL)
        {
            return false;
        }
        if(p!=NULL && q==NULL)
        {
            return false;
        }
        bool left=Symmetric( p->left, q->right);
        bool right=Symmetric( p->right, q->left);
        bool data=p->val==q->val;
        if(left && right && data)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    bool isSymmetric(TreeNode* root) {
        return Symmetric(root->left,root->right);
    }
};
