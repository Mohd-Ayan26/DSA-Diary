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
    int maxi(vector<int> nums,int s,int e)
    {
        int ans=s;
        for(int i=s+1;i<=e;i++)
        {
            if(nums[ans]<nums[i])
            {
                ans=i;
            }
        }
        return ans;
    }
    TreeNode* construct(vector<int> &nums,int s,int e)
    {
        if(s>e)
        {
            return NULL;
        }
        int i=maxi(nums,s,e);
        TreeNode* root=new TreeNode(nums[i]);
        root->left=construct(nums,s,i-1);
        root->right=construct(nums,i+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=construct(nums,0,nums.size()-1);
        return root;
    }
};
