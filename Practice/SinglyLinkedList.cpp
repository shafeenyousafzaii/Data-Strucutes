#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    // Node(int data=0)
    // {
    //     this->data=data;
    // }
    // Node(int data = 0)
    // {
    //     // next = n;
    //     this->data = data;
    // };
    Node(int data = 0, Node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
    // ~Node();
};
class SinglyLinkedList
{
public:
    Node *head;
    Node *tail;
    int length;
    SinglyLinkedList(int l = 0)
    {
        head = NULL;
        tail = NULL;
        length = l;
    }
    void insert_atfirst(int data)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
        // cout << n->data;
        if (tail == nullptr)
        {
            tail == head;
        }
        length++;
    }
    void insert_lastposition(int data)
    {
        if (tail == NULL)
        {
            insert_atfirst(data);
            return;
        }
        Node *n = new Node(data);
        tail->next = n;
        tail = n;
        length++;
    }
    void insert(int data, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "INVALID POSITION" << endl;
            return;
        }
        if (pos == 1)
        {
            insert_atfirst(data);
            return ;
        }
        if (pos == length)
        {
            insert_lastposition(data);
            return;
        }
        Node *slow = head;
        for (int i = 1; i < pos - 1; i++)
        {
            slow = slow->next;
        }
        Node *n = new Node(data, slow->next);

        slow->next = n;

        length++;
    }
    void delete_first()
    {
        Node *curr = head;
        int value = head->data;
        head = head->next;
        delete curr;
        cout << value << " was deleted from the first index" << endl;
        length--;
    }
    void delete_positions(int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid" << endl;
            return;
        }
        if (length == 0)
        {
            cout << "LIST IS EMPTYY" << endl;
            return;
        }
        if(pos==1)
        {
            delete_first();
            return;
        }
        else
        {
        }
    }
    void print_all()
    {
        if(length==0)
        {
            cout<<"LIST IS EMPTY"<<endl;
            return;
        }
        Node *n = head;
        while (n != NULL)
        {
            cout << n->data << " - > ";
            n = n->next;
        }
        cout << "END" << endl;
        cout << length << endl;
    }
    Node get(int index)
    {
        Node *node=head;
        for(int i = 1 ; i < index ; i++)
        {

            node=node->next;
        }
        return *node;    
    }
    // int delete_last()
    // {
    //     if(length<=1)
    //     {
    //         return delete_first();
    //     }
    //     Node second_last=get(length-2);
    //     int value=tail.value; 
    //     return val;
        
    // }
    // ~SinglyLinkedList();
};

int main()
{
    SinglyLinkedList l1;
    while (1)
    {
        int choice;
        cout << endl;
        cout << "Choose from the following options" << endl;
        cout << "1) Insert" << endl;
        cout << "2) display" << endl;
        cout << "3) Insert at last " << endl;
        cout << "4) Insert at any position " << endl;
        cout << "5) delete element" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int data;
            cout << "Enter the number you want to enter in it" << endl;
            cin >> data;
            l1.insert_atfirst(data);
        }
        else if (choice == 2)
        {
            l1.print_all();
        }
        else if (choice == 3)
        {
            int data;
            cout << "Enter the integer you want to add" << endl;
            cin >> data;
            l1.insert_lastposition(data);
        }
        else if (choice == 4)
        {
            int data;
            int pos;
            cout << "Enter data" << endl;
            cin >> data;
            cout << "Enter the position at which you want to enter" << endl;
            cin >> pos;
            l1.insert(data, pos);
        }
        else if (choice == 5)
        {
            int pos;
            cout << "Enter the position you want to delete" << endl;
            cin >> pos;
            l1.delete_positions(pos);
        }
        else
        {
            break;
        }
    }
}