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
            return;
        }
        construct(root->left,inorder);
        inorder.push_back(root->val);
        construct(root->right,inorder);

    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> inorder1;
        construct(root1,inorder1);
        vector<int> inorder2;
        construct(root2,inorder2);
        vector<int> inorder3(inorder1.size()+inorder2.size());
        int i=0,j=0,k=0;
        while(i<inorder1.size() && j<inorder2.size())
        {
            if(inorder1[i]<=inorder2[j])
            {
                  inorder3[k++]=inorder1[i++];
            }
            else
            { 
                inorder3[k++]=inorder2[j++];
                
            }
        }
        while(i<inorder1.size())
        {
            inorder3[k++]=inorder1[i++];
        }
        while(j<inorder2.size())
        {
            inorder3[k++]=inorder2[j++];
        }
        return inorder3;
    }
};
