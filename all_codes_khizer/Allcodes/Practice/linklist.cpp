#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val = 0)
    {
        data = val;
        next = nullptr;
    }
};

class linklist
{
    node *head;
    int length;

public:
    linklist()
    {
        head = NULL;
        length = 0;
    }
    ~linklist()
    {
        node *curr = nullptr;
        while (curr != NULL)
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
            cout << "Invalid Index " << endl;
            return;
        }
        node *n = new node(val);
        if (pos == 1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }
    bool is_empty()
    {
        if (length == 0)
        {
            return true;
        }
        else
            return false;
    }
    void display()
    {
        if (is_empty())
        {
            cout << "List is empty " << endl;
            return;
        }
        node *curr = head;
        for (int i = 1; i <= length; i++)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    void delete_node(int pos)
    {
        if (is_empty())
        {
            cout << "List is empty" << endl;
            return;
        }
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        node *curr = head;
        if (pos == 1)
        {
            head = head->next;
            delete curr;
        }
        else
        {
            node *prev = nullptr;
            for (int i = 1; i < pos; i++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }
        length--;
    }

    bool search(int val)
    {
        if(is_empty())
        {
            cout << "List is empty" << endl;
            return false;
        }

        node *curr=head;
        for(int i=1;i<=length;i++)
        {
            if(val==curr->data)
            {
                return true;
            }
            curr=curr->next;

        }

        return false;
    }
};

int main()
{
    linklist l;
    l.insert(1,1);
    l.insert(2,2);
    l.insert(3,3);
    l.insert(4,4);
    l.insert(5,5);
    l.insert(6,6);
    l.display();
    l.delete_node(4);
    l.display();

}