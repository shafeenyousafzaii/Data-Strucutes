#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
    int num;
    Node *next;
    Node(int c)
    {
        num=c;
        next=NULL;
    };
    // ~Node();
};

class LinkedList
{
public:
    Node *head;
    int length;
    LinkedList(int c)
    {
        head=new Node(c);
        length=0;
    };
    void inset(int pos , int val);
    ~LinkedList();
};

void LinkedList::inset(int pos, int val)
{
    if(pos<1 || pos>(length+1))
    {
        cout<<"Invalid"<<endl;
    }
    Node *n=new Node(val);
    if(pos==1)
    {
        n->next=head;
        head=n;
    }
    else
    {
        Node *curr=head;
        for(int i=1 ; i< pos-1;i++)
        {
            curr=curr->next;
            n->next=curr->next;

        }
        length++;
    }
}