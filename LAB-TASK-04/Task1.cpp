#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    string descriptoin;
    bool completed;
    Node *next;
    Node *prev;
    Node(string d = "")
    {
        descriptoin = d;
        completed = false;
        next = NULL;
        prev = NULL;
    };
    // ~Node();
};
class ToDoList
{
public:
    int length;
    Node *head;
    ToDoList(int l = 0)
    {
        length = l;
        head = NULL;
    };
    void insert(int pos, string d)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid" << endl;
            return;
        }
        Node *n = new Node(d);
        if (pos == 1)
        {
            n->next = head;
            // head->prev=n;
            if (head != NULL)
            {
                head->prev = n;
            }
            head = n;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->prev = curr;
            n->next = curr->next;
            if (curr->next != NULL)
            {
                curr->next->prev = n;
            }
            curr->next = n;
        }
        length++;
    }
    void remove(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        if (pos < 1 || pos > length )
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
            Node *slow = head;
            for (int i = 1; i < pos ; i++)
            {
                slow = slow->next;
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
    void remove_all_comleted()
    {
        Node *curr = head;
        for (int i = 1; i <length; i++)
        {
            if (curr->completed == true)
            {
                remove(i);
            }
            curr = curr->next;
        }
    }
    void displayTask(int x)
    {
        if (x == 1)
        {
            Node *curr = head;
            for (int i = 1; i <=length; i++)
            {
                cout << curr->descriptoin;
                if (curr->completed == true)
                {
                    cout << " completed" << endl;
                }
                else
                {
                    cout << " Not completed" << endl;
                }
                curr = curr->next;
            }
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i <=length; i++)
            {
                curr = curr->next;
            }
            for (int i = 1; i < length; i++)
            {
                cout << curr->prev->descriptoin ;
                if (curr->completed == true)
                {
                    cout << " completed" << endl;
                }
                else
                {
                    cout << "Not completed" << endl;
                }
                curr=curr->prev;
            }
        }
    }
    void mark_completed(int pos)
    {
        if (pos < 1 || pos > length )
        {
            cout << "Invalid" << endl;
        }
        Node *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        curr->completed = true;
    }

    // ~ToDoList();
};

int main()
{
    ToDoList l1;
    cout << "Your TO-DO-LIST " << endl;
    int choice;
    while (1)
    {
        cout << "Choose from the following options" << endl;
        cout << "1) Add task" << endl;
        cout << "2) Mark as completed" << endl;
        cout << "3) Remove completed task" << endl;
        cout << "4) Display task" << endl;
        cout << "5) Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            string d;
            int priority;
            cout << "Enter Description of the task" << endl;
            cin.ignore();
            getline(cin, d);
            cout << "Enter priority level" << endl;
            cin >> priority;
            l1.insert(priority, d);
        }
        else if (choice == 2)
        {
            int task_number;
            cout << "Enter the task number you want to complete" << endl;
            cin >> task_number;
            l1.mark_completed(task_number);
        }
        else if (choice == 3)
        {
            l1.remove_all_comleted();
        }
        else if (choice == 4)
        {
            int x;
            cout << "In which order do you want to display the task? \n press 1 for forward 2 for reverse" << endl;
            cin >> x;
            if (x < 1 || x > 2)
            {
                cout << "Wrong input" << endl;
            }
            l1.displayTask(x);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid " << endl;
        }
    }
}