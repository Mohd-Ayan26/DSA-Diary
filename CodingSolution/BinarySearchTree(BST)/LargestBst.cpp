/* Tree node structure  used in the program
GFG solution
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    pair<int, pair<int, int>> BST(Node* root)
    {
        if(root==NULL)
        {
            return make_pair(0,make_pair(INT_MAX, INT_MIN));
        }
        pair<int,pair<int,int>> left=BST(root->left);
        pair<int,pair<int,int>> right=BST(root->right);
        pair<int,pair<int,int>> res;
        if(left.second.second<root->data && right.second.first>root->data)
        {
            res.first=left.first+right.first+1;
            res.second.first=min(left.second.first,root->data);
            res.second.second=max(right.second.second,root->data);
            return res;
            
        }
        else
        {
            return make_pair(max(left.first,right.first),make_pair(INT_MIN,INT_MAX));
        }
         
    }
    int largestBst(Node *root)
    {
    	
    	pair<int,pair<int,int>> ans=BST(root);
    	return ans.first;
    }
};
