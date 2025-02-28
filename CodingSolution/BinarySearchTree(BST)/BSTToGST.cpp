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
    void Greater(vector<int> &inorder)
    {
        int sum=0;
        for(int i=inorder.size()-1;i>=0;i--)
        {
             sum+=inorder[i];
             inorder[i]=sum;
        }
    }
    void updateTree(TreeNode* &root,vector<int> inorder,int &i)
    {
        if(root==NULL)
        {
            return  ;
        }
        updateTree(root->left,inorder,i);
        root->val=inorder[i];
        i++;
        updateTree(root->right,inorder,i);
    

    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int> inorder;
        construct(root,inorder);
        Greater(inorder);
        int i=0;
        updateTree(root,inorder,i);
        return root;

    }
};
