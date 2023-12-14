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
    List &MergeList(List &l1, List &l2, List &l3)
    {
        // List l3;
        Node *curr1 = l1.head;
        Node *curr2 = l2.head;
        if (curr1->data > curr2->data)
        {
            int i = 1;
            while (curr2 != NULL)
            {
                insert(curr2->data, i);
                i++;
                curr2 = curr2->next;
            }
            i = 1;
            while (curr1 != NULL)
            {
                insert(curr1->data, i);
                i++;
                curr1 = curr1->next;
            }
        }
        else if (curr1->data < curr2->data)
        {
            int i = 1;
            while (curr1 != NULL)
            {
                insert(curr1->data, i);
                i++;
                curr1 = curr1->next;
            }
            i = 1;
            while (curr2 != NULL)
            {
                insert(curr2->data, i);
                i++;
                curr2 = curr2->next;
            }
        }
        curr1 = NULL;
        curr2 = NULL;
        delete curr1;
        delete curr2;
        return l3;
    }
};
int main()
{
    List l1, l2, l3;
    l1.insert(10, 1);
    l1.insert(11, 2);
    l1.insert(12, 3);
    l1.insert(13, 4);
    l1.insert(14, 5);
    l2.insert(1, 1);
    l2.insert(2, 2);
    l2.insert(3, 3);
    l2.insert(4, 4);
    l2.insert(5, 5);
    l1.display();
    l2.display();
    l3.MergeList(l1, l2, l3);
    l3.display();
}