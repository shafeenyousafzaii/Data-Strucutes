#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int l=0)
    {
        data=l;
        next=NULL;
    };
    
};
class Circulat_list
{
public:
    int length;
    Node *head;
    Circulat_list(int l=0)
    {
        length=l;
    };
    void insert(int val , int pos)
    {
        if(pos<1 || pos > length+1)
        {
            cout<<"Invalid"<<endl;
        }
        Node *n=new Node(val);
        Node *curr=head;
        if(head==NULL)
        {
            head=n;
            head->next=head;
        }
        else if(pos==1)
        {
            n->next=head;
            while(curr->next!=head)
            {
                curr=curr->next;
            }
            curr->next=n;
            head=n;
        
        }
        else
        {
            Node *curr=head;
            for(int i = 1 ; i < pos - 1 ; i++)
            {
                curr=curr->next;
            }
            n->next=curr->next;
            curr->next=n;
        }
        length++;
    }
    
};


int main()
{
    Circulat_list l1;
    l1.insert(1,5);
}