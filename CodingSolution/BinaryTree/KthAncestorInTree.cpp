//GfG solution
//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
int solve(Node* root,int &k,int node)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==node)
    {
        return node;
    }
    int left=solve(root->left,k,node);
    int right=solve(root->right,k,node);
    if(left!=-1 && right==-1)
    {
        k--;
        if(k==0)
        {

            return root->data;
        }
        return left;
    }
    if(left==-1 && right!=-1)
    {
        k--;
        if(k==0)
        {
            return root->data;
        }
        return right;
    }
    return -1;
    
}
int kthAncestor(Node *root, int k, int node)
{
    int ans=solve(root,k,node);
    return (ans == node) ? -1 : ans;
}
