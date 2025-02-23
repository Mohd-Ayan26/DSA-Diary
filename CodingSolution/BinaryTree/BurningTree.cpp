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
    TreeNode* mapping(TreeNode* root,map<TreeNode*,TreeNode*> &nodetoparent,int start)
    {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res=NULL;
        while(!q.empty())
        {
           
                TreeNode* temp=q.front();
                q.pop();
                if(temp->val==start)
                {
                    res=temp;
                }
                if(temp->left)
                {
                    nodetoparent[temp->left]=temp;
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    nodetoparent[temp->right]=temp;
                    q.push(temp->right);
                }

            
        }
        return res;
    } 
    void burn(TreeNode* start,map<TreeNode*,TreeNode*> nodetoparent,int &count)
    {
        map<TreeNode*,bool> m;
        queue<TreeNode*> q;
        q.push(start);
        m[start]=true;
        while(!q.empty())
        {
            int size = q.size();
            bool burnedNewNode = false; 

            for (int i = 0; i < size; i++) {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left && !m[temp->left])
            {
                m[temp->left]=true;
                q.push(temp->left);
                burnedNewNode = true;;
            }
             if(temp->right && !m[temp->right])
            {
                m[temp->right]=true;
                q.push(temp->right);
               burnedNewNode = true;
            }
            if(nodetoparent[temp] && !m[nodetoparent[temp]])
            { 
                m[nodetoparent[temp]]=true;
                burnedNewNode = true;
                q.push(nodetoparent[temp]);
            }
            
            }
            if( burnedNewNode)
            {
                count++;
            }
        }
       
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> nodetoparent;
        int count=0;
        TreeNode* res=mapping(root,nodetoparent,start);
        burn(res,nodetoparent,count);
        return count;

    }
};
