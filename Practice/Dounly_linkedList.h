#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val = 0)
    {
        data = val;
        next = NULL;
        prev = NULL;
    };
    // ~Node();
};
class Dounly_linkedList
{
public:
    int length;
    Node *head;
    Dounly_linkedList(int l=0)
    {
        length = l;
        head=NULL;
    };

    void insert(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position" << endl;
        }
        Node *n = new Node(val);
        if (pos == 1)
        {
            n->next = head;
            if (head != NULL)
            {
                head->prev = n;
            }
            head = n;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < pos -1 ; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            n->prev = curr;
            if (curr->next != NULL)
            {
                curr->next->prev = n;
                // curr->next=n;
            }
            curr->next = n;
        }
        length++;
    }
    void remove(int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid" << endl;
        }
        Node *curr = head;
        if (pos == 1)
        {
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete curr;
        }
        else
        {
            Node *slow = NULL;
            for (int i = 0; i < pos; i++)
            {
                slow = curr;
                curr = curr->next;
            }
            slow->next = curr->next;
            if (curr->next != NULL)
            {
                curr->next->prev = slow;
            }
            delete curr;
        }
        length--;
    }
    void display()
    {
        // Node *curr = head;
        // while (curr != NULL)
        // {
        //     cout << curr->data << " - > ";
        //     curr = curr->next;
        // }
        // cout << "END" << endl;
        // while (curr->prev != NULL)
        // {
        //     cout << curr->data << " - > ";
        //     curr = curr->next;
        // }
        // cout << "END" << endl;
        // for(int i = 0 ; i <length ; i++)
        // {
        //     cout<<curr->data<<" - >";
        //     curr=curr->prev;
        // }
        // cout<<endl;
        Node *curr = head;
        cout << "Forward: ";
        while (curr != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "END" << endl;

        cout << "Backward: ";
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        while (curr != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->prev;
        }
        cout << "END" << endl;
    }
        void reverse()
    {
        Node *curr=head;
        Node *slow=head;
        for(int i=1 ; i< length ; i++)
        {
            if(head->next==NULL)
            {
                break;
            }
            head=head->next;
            curr->next=curr->next->prev;
            curr->prev=slow->next;
            curr=head;
            slow=head;
        }
    }
    // ~Dounly_linkedList();
};

