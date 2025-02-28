/**leetcode solution
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        if(root==NULL)
        {
            return str;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
                TreeNode* temp=q.front();
                q.pop();
                if(temp!=NULL)
                {
                    str+=to_string(temp->val)+",";
                     q.push(temp->left);
                     q.push(temp->right);
                }
                else
                {
                    str+="#,";
                }
            
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
        {
            return NULL;
        }
        string str;
        stringstream s(data);
        getline(s,str,',');
        queue<TreeNode*> q;
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#")
            {
                TreeNode* leftans=new TreeNode(stoi(str));
                temp->left=leftans;
                q.push(leftans);
            }
             getline(s,str,',');
            if(str!="#")
            {
                TreeNode* rightans=new TreeNode(stoi(str));
                temp->right=rightans;
                q.push(rightans);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
