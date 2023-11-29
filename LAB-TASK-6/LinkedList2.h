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
        Node *curr = head;
        // Node *prev = NULL;
        Node *next = NULL;
        Node *connect = head;
        while (curr != NULL)
        {
            int count=1;
           Node *prev = NULL;
            for (int i = 1; i <= k; i++)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(count==1){
            head=prev;}
            else
            {
                Node*lew=head;
                while(lew->next!=NULL)
                {
                    lew=lew->next;
                }
                lew=prev;
                Node*tew=prev;
                while(prev->next!=NULL)
                {
                    prev=prev->next;
                }
                prev->next=curr;
            }
             if (k + k == length || k + k > length)
            {
                Node *n = head;
                while (n->next != NULL)
                {
                    n = n->next;
                }

                n->next = connect;
                return;
            }
            Node*pew=head;
            while(pew->next!=NULL)
            {
                pew=pew->next;
            }
            pew->next=curr;
            for (int i = 1; i < k; i++)
            {
                curr = curr->next;
            }
            next=curr;
            count++;
        }

        for (int i = 1; i < k + 1; i++)
        {
            connect = connect->next;
        }
        // int i = 1;
        // while (curr != NULL && i <= k)
        // {
        //     next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        //     i++;
        // }
        // head = prev;
        // //----------------------------------------------------------------------------------------------------------------------------
        // cout << endl;
        // cout << head->data;
        // cout << endl;
        // if (k + k == length || k + k > length)
        // {
        //     Node *n = head;
        //     while (n->next != NULL)
        //     {
        //         n = n->next;
        //     }

        //     n->next = connect;
        //     return;
        // }

        // Node *curr2 = head;
        // while (curr2->next != NULL)
        // {
        //     curr2 = curr2->next;
        // }
        // curr2->next = curr;

        // curr = head;
        // prev = NULL;
        // next = NULL;
        // int reverse = length - k;
        // Node *prevReverse = NULL;
        // for (int i = 1; i <= reverse; i++)
        // {
        //     prevReverse = curr;
        //     curr = curr->next;
        // }

        // cout << endl;
        // int r = 1;
        // while (curr != NULL && r <= k)
        // {
        //     next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        //     r++;
        // }
        // prevReverse->next = prev;
    }
};
