#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
         this->data=data;
         this->left=NULL;
         this->right=NULL;
    }
    ~node()
    {
        delete left;
        delete right;
    }
};
node* build(node* root,int val)
{
    if(root==NULL)
    {
       return new node(val);
    }
    if(val<root->data)
    {
        root->left=build(root->left,val);
    }
    else
    {
        root->right=build(root->right,val);
    }
    return root;
}
void inorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node* root=NULL;
    while(true)
    {
        int data;
        cin>>data;
        if(data==-1)
              break;
        root=build(root,data);      
    }
    inorder(root);
    return 0;
}
