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
    void createmapping(vector<int> inorder,map<int,int> &inorderToIndex)
{
    for(int i=0;i<inorder.size();i++)
    {
        inorderToIndex[inorder[i]]=i;
    }
}
TreeNode* solve(vector<int> &postorder,vector<int> &inorder,map<int,int> &inorderToIndex,int &index,int inorderstart,int inorderend,int n)
{
    if(index<0|| inorderstart>inorderend )
    {
        return NULL;
    }
    int element=postorder[index--];
    int position=inorderToIndex[element];
    TreeNode* root=new TreeNode(element);
    root->right=solve(postorder,inorder,inorderToIndex,index,position+1,inorderend,n);
    root->left=solve(postorder,inorder,inorderToIndex,index,inorderstart,position-1,n);
    return root;

}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         map<int,int> inorderToIndex;
        createmapping(inorder,inorderToIndex);
        int postindex=postorder.size()-1;
        TreeNode* root=solve(postorder,inorder,inorderToIndex,postindex,0,inorder.size()-1,postorder.size());
        return root;
    }
};
