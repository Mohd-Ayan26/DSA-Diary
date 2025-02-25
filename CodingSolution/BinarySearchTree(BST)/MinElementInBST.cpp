/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    int minValue(Node* root) {
     if(root->left==NULL && root->right==NULL)
     {
         return root->data;
     }
     if(root->left)
     {
         return minValue(root->left);
     }
     else
     {
         return root->data;
     }
      
    }
};
