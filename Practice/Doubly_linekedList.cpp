#include<iostream>
#include<string>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
public:
    Node(int l=0)
    {
        data=l;
        next=NULL;
        prev=NULL;
    };
    ~Node();
};
class Doubly_linekedList
{
public:
    int length;
    Node *head;
    Doubly_linekedList(int x=0)
    {
        length=x;
        head=NULL;
    };
    void insert(int pos , int val)
    {
        if(pos<1 || pos > length+1)
        {
            cout<<"Invalid Position"<<endl;
        }
        Node *n=new Node(val);
        if(pos==1)
        {
            n->next=head;
            head->prev=n;
            head=n;

        }
        if(head!=NULL)
        {
            n->prev=head;
            head=n;
        }
        else
        {
            Node *curr=head;
            for(int i=0 ; i<(pos-1) ; i++)
            {
                curr=curr->next;
            }
            n->prev=curr;
            n->next=curr->next;
            if(curr->next!=NULL)
            {
                curr->next->prev=n;
            }
            curr->next=n;
        }
        length++;
    }
    void remove(int pos)
    {
        if(pos<1 || pos>(length+1))
        {
            cout<<"Invalid"<<endl;
        }
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
        }
        Node *curr=head;
        if(pos==1)
        {
            head=head->next;
            if(head!=NULL)
            head->prev=NULL;
            delete curr;
        }
        else 
        {
            Node *slow=head;
            for(int i = 1 ; i < length + 1 ; i++)
            {
                slow=slow->next;
            }
            slow->next=curr->next;
            if(curr->next!=NULL)
            {
                curr->next->prev=slow;
            }
            delete curr;
        }
        length--;
    }
    // void reverse()
    // {
    //     Node *curr=head;
    //     Node *slow=head;
    //     for(int i=1 ; i< length ; i++)
    //     {
    //         if(head->next==NULL)
    //         {
    //             break;
    //         }
    //         head=head->next;
    //         curr->next=curr->next->prev;
    //         curr->prev=slow->next;
    //         curr=head;
    //         slow=head;
    //     }
    // }
    ~Doubly_linekedList();
};


int main()
{
    Doubly_linekedList l1;
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    l1.insert(4,4);
    l1.insert(5,5);
    l1.di
    
}