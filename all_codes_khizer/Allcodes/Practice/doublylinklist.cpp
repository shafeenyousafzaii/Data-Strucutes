#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data = 0)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class doublylinklist
{
    node *head;
    int length;

public:
    doublylinklist()
    {
        head = NULL;
        length = 0;
    }

    ~doublylinklist()
    {
        node *curr = head;
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
            cout << "Invalid Index" << endl;
            return;
        }
        node *n = new node(val);

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
            node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            n->prev = curr;
            if (curr->next != nullptr)
            {
                curr->next->prev = n;
            }
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

    void remove(int pos)
    {
        if (is_empty())
        {
            cout << "List is empty" << endl;
            return;
        }
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Index" << endl;
            return;
        }

        node *curr = head;
        if (pos == 1)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = NULL;
            }
            delete curr;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }
            delete curr;
        }
        length--;
    }

    void Display()
    {
        if (is_empty())
        {
            cout << "List is empty" << endl;
            return;
        }
        node *curr = head;
        cout << "List is : ";
        for (int i = 1; i <= length; i++)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};
int main()
{
    doublylinklist l;
    l.insert(1,1);
    l.insert(2,2);
    l.insert(3,3);
    l.insert(4,2);
    l.insert(5,5);
    l.Display();
    l.remove(2);
    l.Display();
}