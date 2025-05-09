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
    void solve(TreeNode* root,int &count)
    {
          if(root==NULL)
          {
            return;
          }
          solve(root->left,count);
          count++;
          solve(root->right,count);
    }
public:
    int countNodes(TreeNode* root) {
        int count=0;
        solve(root,count);
        return count;
        
    }
};
