// Tree Node(GFG)
/*class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void leftTraversal(vector<int> &ans,Node* root)
  {
      if(root==NULL ||root->left==NULL && root->right==NULL)
      {
          return ;
      }
      ans.push_back(root->data);
      if(root->left)
      {
          leftTraversal(ans,root->left);
      }
      else
      {
          leftTraversal(ans,root->right);
      }
  }
   void rightTraversal(vector<int> &ans,Node* root)
  {
      if(root==NULL||root->left==NULL && root->right==NULL)
      {
          return ;
      }
      if(root->right)
      {
          rightTraversal(ans,root->right);
      }
      else
      {
          rightTraversal(ans,root->left);
      }
      ans.push_back(root->data);
  }
   void leafTraversal(vector<int> &ans,Node* root)
  {
      if(root==NULL)
      {
          return ;
      }
      if(root->left==NULL && root->right==NULL)
      {
          ans.push_back(root->data);
          return;
      }
      leafTraversal(ans,root->left);
      leafTraversal(ans,root->right);
  }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root==NULL)
        {
            return ans ;
        }
        ans.push_back(root->data);
       
          leftTraversal(ans, root->left);
          leafTraversal(ans, root->left);
          leafTraversal(ans, root->right);
          rightTraversal(ans, root->right);
     
        return ans;
    }
};
