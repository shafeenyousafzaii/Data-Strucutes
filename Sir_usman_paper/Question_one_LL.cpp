#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
public:
    node *head;
    int length;

public:
    List()
    {
        head = NULL;
        length = 0;
    }
    node *get_head()
    {
        return head;
    }
    int head_data()
    {
        return head->data;
    }
    ~List()
    {
        node *curr = NULL;
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
        node *curr = head;
        if (pos == 1)
        {
            head = head->next;
            delete curr;
        }
        else
        {
            node *slow = NULL;
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
        node *curr = head;
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
        node *curr = head;
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
        node *curr = l.head;
        while (curr != NULL)
        {
            insert(curr->data, length + 1);
            curr = curr->next;
        }
    }
    int Question_One(node *curr, int &max_profit, bool &yes)
    {
        // int max_profit;

        node *curr2 = curr;
        int data = curr->data;
        int profit = 0;
        while (curr2 != NULL)
        {

            // cout << "Curr->data : " << curr->data << endl;
            // cout << "Curr2->data : " << curr2->data << endl;
            profit = curr2->data - curr->data;
            // cout << "Profit : " << profit << endl;
            if (profit >= max_profit && profit >= 0)
            {
                yes = true;
                max_profit = profit;
                // cout << "Max profit : " << max_profit << endl;
            }
            if (curr2->next == NULL)
            {
                break;
            }
            curr2 = curr2->next;

            // max_profit=curr2->data-curr->data;
        }
        // cout<<"Working"<<endl;
        if (curr->next != NULL)
        {
            Question_One(curr->next, max_profit, yes);
        }
        if (yes == false)
        {
            max_profit = -1;
        }
        // else
        // {
        // cout<<"HERE"<<endl;
        // return Question_One(l1,curr,max_profit,true);
        return max_profit;
        // }
    }
};

int main()
{
    List l;
    int max_profit = 0;
    bool yes;
    // int data=0;

    l.insert(44, 1);
    l.insert(30, 2);
    l.insert(24, 3);
    l.insert(32, 4);
    l.insert(35, 5);
    l.insert(30, 6);
    l.insert(40, 7);
    l.insert(38, 8);
    l.insert(15, 9);
    //---------------
    // l.insert(10, 1);
    // l.insert(9, 2);
    // l.insert(8, 3);
    // l.insert(2, 4);
    //---------------
    //  l.insert(3, 1);
    // l.insert(5, 2);
    // l.insert(6, 3);
    // l.insert(8, 4);
    // l.insert(10, 5);
    // l.insert(15, 6);
    // l.insert(16, 7);
    // l.insert(25, 8);
    // l.insert(11, 9);


    l.display();
    max_profit = l.Question_One(l.head, max_profit, yes);
    if (max_profit == 0)
    {
        max_profit=-1;
        cout << "Max profit : " << max_profit<< endl;
    }
    else
    {
        cout << "Max profit : " << max_profit << endl;
    }
    // l.remove(1);
    // l.rem_val(40);
    // l.display();
    // cout << l.find(30) << endl;
    // cout << l.len() << endl;
    // List l1;
    // l1.copy(l);
    // l1.display();
    // l.clear();
    // l.display();
    // l1.display();

    return 0;
}
