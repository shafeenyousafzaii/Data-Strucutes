#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;
    int length;

public:
    List()
    {
        head = NULL;
        length = 0;
    }
    ~List()
    {
        Node *curr = NULL;
        while (head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

    void insert(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        Node *n = new Node(val);

        if (pos == 1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }
    void remove(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (pos < 1 || pos > length)
        {
            cout << "Invalid position" << endl;
            return;
        }
        Node *curr = head;
        if (pos == 1)
        {
            head = head->next;
            delete curr;
        }
        else
        {
            Node *slow = NULL;
            for (int i = 1; i < pos; i++)
            {
                slow = curr;
                curr = curr->next;
            }
            slow->next = curr->next;
            delete curr;
        }
        length--;
    }
    int find(int val)
    {
        Node *curr = head;
        for (int i = 1; i <= length; i++)
        {
            if (curr->data == val)
            {
                return i;
            }
            curr = curr->next;
        }
        return -1;
    }
    void rem_val(int val)
    {
        int pos = find(val);
        if (pos == -1)
        {
            cout << "Value not found" << endl;
            return;
        }
        remove(pos);
    }

    void display()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    void clear()
    {
        while (head != NULL)
        {
            remove(1);
        }
    }
    int len()
    {
        return length;
    }

    void copy(List &l)
    {
        Node *curr = l.head;
        while (curr != NULL)
        {
            insert(curr->data, length + 1);
            curr = curr->next;
        }
    }
    /*
       what i did in this code was something like , first i am exchanging the front nodes and then the alternating last nodes
       if sum of k is greater then i am only reversing the first k nodes and not exchanging the other alternating k nodes
       becasue that is out of bounds.
       with valid checks
        */
    void reverseKNode(int k)
    {
        if (k > length)
        {
            cout << "Invalid exchange" << endl;
            return;
        }
        Node *next=NULL;
        Node *curr=head;
        
        int count=0;
        Node *prev2=NULL;
        while(curr->next!=NULL)
        {
            Node *prev=NULL;    
            for(int i=1 ; i<=k;i++)
            {
                // cout<<"WOrking"<<endl;
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            if (count==0)
            {
                head=prev;
                while(prev->next!=NULL)
                {
                    prev=prev->next;
                }
                prev->next=curr;
                prev=curr;
                prev2=head;
                count++;
                // cout<<"FIRST WORK"<<endl;
                

            }
            else
            {
                prev2->next=prev;
                while(prev->next!=NULL)
                {
                    prev=prev->next;
                }
                prev->next=curr;
                // cout<<"SECOND_WORK"<<endl;

            }
            for(int i=1 ; i<=k ; i++)
            {
                 if(curr==NULL)
                {
                    // cout<<"CURRENT NULL"<<endl;
                    break;
                }
                curr=curr->next;
                next=curr;
                prev=curr;
                // cout<<"WORKING"<<endl;
                
            }
            //pointer from head to prev 2 on page;
            while(prev2->next!=curr && prev2->next!=NULL)
            {
                prev2=prev2->next;
            }
            // cout<<"WORKING_LASTTTT"<<endl;
            if(curr==NULL)
            {
                break;
            }



        }
    }
};
