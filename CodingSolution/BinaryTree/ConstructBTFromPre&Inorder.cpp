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
void createmapping(vector<int> inorder,map<int,int> &inorderToIndex)
{
    for(int i=0;i<inorder.size();i++)
    {
        inorderToIndex[inorder[i]]=i;
    }
}
TreeNode* solve(vector<int> &preorder,vector<int> &inorder,map<int,int> &inorderToIndex,int &index,int inorderstart,int inorderend,int n)
{
    if(index>=n|| inorderstart>inorderend )
    {
        return NULL;
    }
    int element=preorder[index++];
    int position=inorderToIndex[element];
    TreeNode* root=new TreeNode(element);
    root->left=solve(preorder,inorder,inorderToIndex,index,inorderstart,position-1,n);
    root->right=solve(preorder,inorder,inorderToIndex,index,position+1,inorderend,n);
    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inorderToIndex;
        createmapping(inorder,inorderToIndex);
        int preindex=0;
        TreeNode* root=solve(preorder,inorder,inorderToIndex,preindex,0,inorder.size()-1,preorder.size());
        return root;
    }
};
