#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    string data;
    Node *next;
    Node(string val)
    {
        data = val;
        next = NULL;
    };
    // ~Node();
};
class CircularLinkedLInst
{
public:
    int length;
    Node *head;
    CircularLinkedLInst()
    {
        head = NULL;
        length = 0;
    };
    void insert(int pos, string data)
    {
        if (pos < 0 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
        }
        Node *n = new Node(data);
        Node *curr = head;
        if (head == NULL)
        {
            // n->next = n;
            head = n;
            head->next = head;
            // cout<<"Done";
        }
        else if (pos == 1)
        {

            n->next = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = n;
            head = n;
            // length++;
        }
        else
        {
            Node *curr = head;
            for (int i = 0; i < pos - 2; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }
    void display()
    {
        // Node *curr = head;
        // while (curr->next != head)
        // {
        //     cout << "Data : " << curr->data << endl;
        // }
        Node *curr = NULL;
        while (curr != head)
        {
            if (curr == NULL)
            {
                curr = head;
            }
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    void display(int val)
    {
        // Node *curr = head;
        // while (curr->next != head)
        // {
        //     cout << "Data : " << curr->data << endl;
        // }
        Node *curr = NULL;
        while (1)
        {
            if (curr == NULL)
            {
                curr = head;
            }
            cout << curr->data << " "<<endl;
            cout<<"1.Next"<<endl;
            cout<<"2.Go to Main menu"<<endl;
            int choice;
            cin>>choice;
            curr = curr->next;
            if(choice==1)
            {
                continue;
            }
            else if(choice==2)
            {
                return;
            }
            else
            {
                cout<<"Invalid Choice"<<endl;
            }
        }
        cout << endl;
    }
    void startgame()
    {
        while(length!=1)
        {
        int s;
        s=rand()%length+1;
        cout<<"Random Number : "<<s<<endl;
        remove(s);
        cout<<"Current Players:";
        display();
        }
        cout<<head->data<<" is the winner"<<endl;
        
    }
    void remove(int pos)
    {   
       if(head == NULL)
            {
                cout<<"Empty"<<endl;
                return;
            }
            if(pos < 1 || pos > length)
            {
                cout<<"Invalid position"<<endl;
                return;
            }
            Node* curr = head;
            Node* tail = head;
            if(pos == 1)
            {
                while(tail->next != head)
                {
                    tail = tail->next;
                }
                head = head->next;
                tail->next = head;
                if(head == head->next)
                {
                    head = NULL;
                }
                delete curr;
            }
            else
            {
                Node* slow = NULL;
                for(int i = 1 ; i < pos ; i++)
                {
                    slow = curr;
                    curr = curr->next;
                }
                slow->next = curr->next;
                cout<<curr->data<<" Removed"<<endl;
                delete curr;

            }
            length--; 
    }
    // ~CircularLinkedLInst();
};
