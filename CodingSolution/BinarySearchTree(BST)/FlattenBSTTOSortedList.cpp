/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
 void construct(Node* root,vector<int> &inorder)
    {
        if(root==NULL)
        {
            return ;
        }
        construct(root->left,inorder);
        inorder.push_back(root->data);
        construct(root->right,inorder);
    }
    Node *flattenBST(Node *root)
    {
        vector<int> inorder;
        construct(root,inorder);
        Node* rootnew=new Node(inorder[0]);
        Node* curr=rootnew;
       for(int i=1;i<inorder.size();i++)
       {
            Node* temp=new Node(inorder[i]);
            curr->left=NULL;
            curr->right=temp;
            curr=temp;
            
       }
       return rootnew;
       
    }
    
};
