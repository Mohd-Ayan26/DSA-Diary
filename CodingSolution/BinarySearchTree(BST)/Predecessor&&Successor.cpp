/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Node* temp=root;
        while(temp && temp->key!=key)
        {
            if(temp->key>key)
            {
                suc=temp;
                temp=temp->left;
            }
            else
            {
                pre=temp;
                temp=temp->right;
            }
        }
        if (temp==NULL) 
               return;
        //precessor
       if (temp->left)
       {
        Node*curr1=temp->left;
        while(curr1)
        {
            pre=curr1;
            curr1=curr1->right;
        }
       }
       //successor
       if (temp->right)
       {
         Node*curr2=temp->right;
        while(curr2)
        {
            suc=curr2;
            curr2=curr2->left;
        }
       }
        
    }
};
