#include <iostream>
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

    void insert(string val, int pos)
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
    int find(string val)
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
    void rem_val(string val)
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
    string get(int pos)
    {
        Node *curr=head;
        for(int i =1 ; i<=pos ; i++)
        {
            if(i==pos)
            {
                return curr->data;
            }
            curr=curr->next;
        }
        return 0;
    }
};

class TicketSalesQueue : public List
{
private:
    int front;
    int rear;
public:
    TicketSalesQueue()
    {
        front=1;
        rear=0;
    };
    void enqueue(string name)
    {
        rear++;
        insert(name,rear);
    }
    string dequeue()
    {
        if(len()==0)
        {
            cout<<"No more queues"<<endl;
            return "";
        }
        string name;
        name=get(front);
        // front++;
        remove(front);
        rear--;
        return name;
    }

    void display()
    {
        if(len()==0)
        {
            cout<<"No queues to display"<<endl;
            return;
        }
        display();
    }
    
};

// class RollerCoster : public List
// {
// private:
//     int front;
//     int rear;
// public:
//     RollerCoster()
//     {
//         front =1;
//         rear=0;
//     };
//     void Enqueue(string name)
//     {
//         rear++;
//         insert(name,rear);
//     }
//     string Deque()
//     {
//         string name;
//         name=get(front);
//         return name;
//     }
//     void display()
//     {
//         display();
//     }
// };

// class RoundWheel : public List
// {
// private:
//     int front;
//     int rear;
// public:
//     RoundWheel()
//     {
//         front =1;
//         rear=0;
//     };
//     void Enqueue(string name)
//     {
//         rear++;
//         insert(name,rear);
//     }
//     string Deque()
//     {
//         string name;
//         name=get(front);
//         return name;
//     }
//     void display()
//     {
//         display();
//     }
// };
// class MotionRide : public List
// {
// private:
//     int front;
//     int rear;
// public:
//     MotionRide()
//     {
//         front =1;
//         rear=0;
//     };
//     void Enqueue(string name)
//     {
//         rear++;
//         insert(name,rear);
//     }
//     string Deque()
//     {
//         if(len()==0)
//         {
//             cout<<"No more visitors left"<<endl;
//             return 0;
//         }
//         string name;
//         name=get(front);
//         remove(front);
//         return name;
//     }
//     void display()
//     {
//         display();
//     }
// };

int main()
{
    TicketSalesQueue q1;
    TicketSalesQueue RollerCoster;
    TicketSalesQueue RoundWheel;
    TicketSalesQueue MotionRide;
    while(1)
    {
        int choices;
        cout<<"Enter Your Choice"<<endl;
        cout<<"1)Enter a visitor in ticktets purchace queue"<<endl;
        cout<<"2)Sell a ticket"<<endl;
        cout<<"3)Proces all queues"<<endl;
        cin>>choices;
        if(choices==1)
        {
            cout<<"Enter your name"<<endl;
            string name;
            cin.ignore();
            getline(cin,name);
            q1.enqueue(name);
        }
        else if(choices==2)
        {
            string name;
            name=q1.dequeue();
            if(name=="")
            {
                continue;
            }
            cout<<"Now selling ticket to:"<<name<<"..."<<endl;
            cout<<"Which attraction's ticket "<<name<<" wants?"<<endl;
            cout<<"1.Roller Coster"<<endl;
            cout<<"2.Motion Ride"<<endl;
            cout<<"3.Round wheel"<<endl;
            int choice;
            cin>>choice;
            while(1)
            {
            if(choice==1)
            {
                RollerCoster.enqueue(name);
                cout<<"Roller Coster ticket sold to "<<name<<endl;
                break;
            }
            else if(choice==2)
            {
                MotionRide.enqueue(name);
                cout<<"Motion Ride ticket sold to "<<name<<endl;
                break;
            }
            else if(choice==3)
            {
                RoundWheel.enqueue(name);
                cout<<"Round Wheel ticket sold to "<<name<<endl;
                break;
            }
            else{
            cout<<"Wrong input"<<endl;}
            }
        }
        else if(choices==3)
        {
            int len=RollerCoster.len();
            if(len==0)
            {
                cout<<"No more queues to display in roller coster"<<endl;
                continue;
            }
            for(int i=0;i<len ; i++)
            {
                string name;
                name=RollerCoster.dequeue();
                cout<<"Visitor "<<name<<" now enjoying at the attraction roller coster"<<endl;   
            }
            int lenn=MotionRide.len();
            if(lenn==0)
            {
                cout<<"No more queues to display in motion ride"<<endl;
                continue;
            }
            for(int i=0;i<len ; i++)
            {
                string name;
                name=MotionRide.dequeue();
                cout<<"Visitor "<<name<<" now enjoying at the attraction motion ride"<<endl;   
            }
            int lennn=RoundWheel.len();
            if(lennn==0)
            {
                cout<<"No more queues to display in motion round wheel"<<endl;
                continue;
            }
            for(int i=0;i<len ; i++)
            {
                string name;
                name=RoundWheel.dequeue();
                cout<<"Visitor "<<name<<" now enjoying at the attraction round wheel"<<endl;   
            }
            
            
        }
        else
        {
            cout<<"Wrong input"<<endl;
            cout<<"Do you wanna exit or not{press 1 for exit 2 for continuation}"<<endl;
            int c;
            cin>>c;
            if(c==1)
            {
            break;
            }
            else
            {
                continue;
            }
        }
    }
}