#include<iostream>
using namespace std;
class Queue
{
private:
    int length;
    int capacity;
    string *arr;
    int front;
    int rear;
public:
    Queue(int c)
    {
        capacity=c;
        arr=new string[c];
        front=0;
        rear=-1;
        length=0;
    };
    void EnQueue(string val)
    {
        if(length==capacity)
        {
            cout<<"Queue overflow"<<endl;
            return;
        } 
        if(rear==(capacity-1))
        {
            rear=0;
        }
        else
        {
            rear++;
        }

            arr[rear]=val;
            length++;
    }
    string Deque()
    {
        if(length==0)
        {
            cout << "Underflow\n";
            return "";
        }
        string val=arr[front];
        if(front==(capacity-1))
        {
            front=0;
        }
        else 
        {
            front++;
            
        }
        length--;
        return val;
            
        
    }
    void display()
    {
        if(length==0)
        {
            cout<<"No patients left"<<endl;
            return;
        }   
        int index=front;
        for(int i=0 ; i<length ; i++)
        {
            cout<<arr[index]<<"\t";
            if(index==length-1)
            {
                index=0;
            }
            else
            {
                index++;
            }
        }
    }
    void seek()
    {
        if(length==0)
        {
            cout<<"No patients left"<<endl;
            return;
        }
        cout<<arr[front]<<endl;
    }
    ~Queue()
    {
        delete [] arr;
    };
};
int main()
{
    int seats=0;
    cout<<"Enter the number of seats in waiting area"<<endl;
    cin>>seats;
    Queue q1(seats);
    int count=0;
    while(1)
    {
        int choice=0;
        cout<<"Enter an option:"<<endl;
        cout<<"1. Enter a patient in waiting queue"<<endl;
        cout<<"2. Send next patient to the doctor."<<endl;
        cout<<"3. See who's next"<<endl;
        cout<<"4. Display all patients in the queue"<<endl;
        cin>>choice;
        if(choice==1)
        {
            if(count!=seats)
            {
            string name;
            cin.ignore();
            getline(cin,name);
            q1.EnQueue(name);
            count++;
            }
            else
            {
                cout<<"No more seats available"<<endl;

            }
        }
        else if(choice==2)
        {
            string name="";
            name=q1.Deque();
            cout<<"Sending the next patient : "<<name<<endl;
        }
        else if(choice==3)
        {
            q1.seek();
        }
        else if(choice==4)
        {
            q1.display();
        }
        else
        {
            cout<<"You asked to exit"<<endl;
            break;
        }
    }

    
    
}