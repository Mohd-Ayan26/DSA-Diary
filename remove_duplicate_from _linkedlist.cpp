// program to remove duplicates from sorted linked list
#include<bits/stdc++.h>
using namespace std;
//creating class node
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
//remove duplicate element from linkedlist
//head is pass by reference 
//changes occur in head will be visible in main function
void removeduplicate(node* &head)
{
    node* curr=head;
    node* forward=head->next;
    while(curr!=NULL && forward!=NULL)
    {
        if(curr->data==forward->data && forward!=NULL)
        {
            curr->next=forward->next;
            node* store=forward;
            forward=curr->next;
            delete(store);
        }
        else
        {
            curr=curr->next;
            forward=curr->next;

        }
    }
}
//insertion function
node* insert()
{
    //intializing head and tail
    node* head=NULL;
    node* tail=NULL;
    //iterating till -1 is encounter
    while(1)
    {
        int data;
        cin>>data;
        //breaking condition
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
//printing list
void print(node* head)
{
    node* temp=head;
    cout<<"List of elements after removing duplicate are :"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    //calling insertion function
    cout<<"Enter the element to insert and press -1 to terminated :"<<endl  ;
    node* head=insert();
    //calling print function
    removeduplicate(head);
    print(head);
    return 0;
}
