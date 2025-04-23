//build tree from levelorder traversal
#include<iostream>
#include<queue>
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
//tree traversal
void levelorder(node* root)
{
    if(root==NULL)
    {
        cout<<"";
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
             node* temp=q.front();
             q.pop();
             cout<<temp->data;
             if(temp->left)
             {
                q.push(temp->left);
             }
             if(temp->right)
             {
                q.push(temp->right);
             }
        }
    }

}
//using recursion
node* buildtree1()
{
    int data;
    cin>>data;
     if(data==-1)
     {
        return NULL;
     }
     node* root=new node(data);
     root->left=buildtree1();
     root->right=buildtree1();
     return root;
}
//using level order
node* buildtree(node* root)
{
    
    int data;
    cin>> data;
    if(data==-1)
    {
        return NULL;
    }
    root=new node(data);
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cin>>data;
        if(data!=-1)
        {
            temp->left=new node(data);
            q.push(temp->left);
        }
         cin>>data;
        if(data!=-1)
        {
            temp->right=new node(data);
            q.push(temp->right);
        }
    }
    return root;
}
int main()
{
    node* root=NULL;
    root=buildtree1();
    levelorder(root);
    return 0;
}
