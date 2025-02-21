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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;

        }
 /*    horizontal  level      value 
             |        |          |        */
        map<int,map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            TreeNode* node=temp.first;
            int hd=temp.second.first;
            int level=temp.second.second;
            nodes[hd][level].insert(node->val);
            if(node->left)
            {
                q.push(make_pair(node->left,make_pair(hd-1,level+1)));
            }
            if(node->right)
            {
                q.push(make_pair(node->right,make_pair(hd+1,level+1)));
            }


        }
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};
