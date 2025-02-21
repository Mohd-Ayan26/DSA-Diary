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
   void rightview(Node* root,vector<int> &ans,int level)
    {
        if(root==NULL)
        {
            return ;
        }
        if(ans.size()==level)
        {
            ans.push_back(root->data);
        }
        rightview(root->left,ans,level+1);
        rightview(root->right,ans,level+1);
    }
    vector<int> leftView(Node *root) {
        vector<int> ans;
        rightview(root,ans,0);
        return ans;
    }
};
