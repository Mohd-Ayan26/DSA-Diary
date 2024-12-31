//Program to merge two linked list
#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    ~node()
    {
        this->next=NULL;
    }
};
//insertion
node* insert()
{
    node* head=NULL;
    node* tail=NULL;
    while(1)
    {
        int data;
        cin>>data;
        if(data==-1) break;
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=head;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
    return head;
}
//printing linked list
void print(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
//merging linked list
node* merge(node* &head1,node* &head2)
{
    node* curr1=head1;
    node* next1=head1->next;
    node* curr2=head2;
    node* next2=NULL;
    while(next1!=NULL && curr2!=NULL)
    {
        if(curr2->data>=curr1->data && curr2->data<=next1->data)
        {
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else
        {
           curr1=next1;
           next1=next1->next;
           if(next1==NULL)
           {
            curr1->next=curr2;
            return head1;
           }
        }
    }
    return head1;
}
//first checking the linked list
node* check(node* &head1,node* &head2)
{
     if(head1==NULL)
    {
         return head2;

    }
    if(head2==NULL)
    {
        return head1;
    }
    if(head1->data<=head2->data)
    {
       return merge(head1,head2);
    }
    else{
        return merge(head2,head1);
    }
}
int main()
{
    cout<<"Enter the element of Ist list "<<endl;
    node* head1=insert();
    cout<<"Enter the element of 2st list "<<endl;
    node* head2=insert();
    //calling check function
    node* ans=check(head1,head2);
    cout<<"linked list after the merge"<<endl;
    print(ans);
    return 0;
}
