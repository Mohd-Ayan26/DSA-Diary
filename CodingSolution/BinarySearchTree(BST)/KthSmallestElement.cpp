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
    int Smallest(TreeNode* root,int &i,int k)
    {
        if(root==NULL)
        {
            return -1;
        }
        int leftans=Smallest(root->left,i,k);
        if(leftans!=-1)
        {
            return leftans;
        }
        i++;
        if(i==k)
        {
            return root->val;
        }
        return Smallest(root->right,i,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        int ans=Smallest(root,i,k);
        return ans;
    }
};
