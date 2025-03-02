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
    void findSum(TreeNode* root,int &sum, int store)
    {
        if(root==NULL)
        {
            return;
        }
         store = store * 10 + root->val;
         if(root->left == NULL && root->right == NULL)
        {
            sum += store;
        }
        findSum(root->left,sum,store);
        findSum(root->right,sum,store);
        store=store/10;
        

    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int store=0;
        findSum(root,sum,store);
        return sum;
    }
};
