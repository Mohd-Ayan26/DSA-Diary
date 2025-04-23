//GFG solution
/*A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
   void leftview(Node* root,vector<int> &ans,int level)
    {
        if(root==NULL)
        {
            return ;
        }
        if(ans.size()==level)
        {
            ans.push_back(root->data);
        }
        leftview(root->left,ans,level+1);
        leftview(root->right,ans,level+1);
    }
    vector<int> leftsideView(Node *root) {
        vector<int> ans;
        leftview(root,ans,0);
        return ans;
    }
};
