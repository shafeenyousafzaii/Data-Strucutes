#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};
class circLinkedList
{
public:
    node *head;
    int length;

    circLinkedList(int l)
    {
        head = NULL;
        length = l;
    }

    void insert(int pos, int val)

    {
        node *n = new node(val);
        if (length == 0)
        {
            cout << "empty list" << endl;
            return;
        }
        else if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            
            if (pos == 1)
            {
                n->next = head;
                head = n;
            }
        }
        length++;
    }

    // void remove(int pos)
    // {
    //     node *current = head;
    //     if (length == 0)
    //     {
    //         cout << " Empty" << endl;
    //     }
    //     else if (pos < 1 || pos > length + 1)
    //     {
    //         cout << " Invalid Position" << endl;
    //     }
    //     else
    //     {
    //         if (pos == 1)
    //         {
    //             current = head;
    //             head = head->next;
    //             delete current;
    //         }
    //         for (int i = 1; i < pos-1; i++)
    //         {
    //             current = current->next;
    //         }
    //         delete current;
    //     }
    //     length--;
    // }
    void remove(int pos) {
    if (length == 0 || pos < 1 || pos > length) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1) {
        node* current = head;
        head = head->next;
        delete current;
    } else {
        node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            current = current->next;
        }

        if (current->next != nullptr) {
            node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            cout << "Invalid position" << endl;
            return;
        }
    }
    length--;
}

    int josephus(int m, int n)
    {

node *current = head;
        for (int i = 1; i <= n; i++)
        {
            insert(i, i);
            

            current = head;
            while (length != 1)
            {
                for (int i = 1; i <= m; i++)
                {
                    // pos++;
                    // node *new= current->next;
                    current = current->next;
                }
                 node *temp= current->next;
                 remove(current->data);
                current = temp;
                remove(i);
            }

            
        }
        return current->data;
    }
};

int main(){
    circLinkedList list(10);
    int winner=list.josephus(10,3);
    cout<<"The winner is : "<<winner<<endl;
}