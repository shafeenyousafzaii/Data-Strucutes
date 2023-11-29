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
    };
    void EnQueue(string val)
    {
        if(length==capacity)
        {
            cout<<"Queue overflow"<<endl;
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
        if (length==0)
        {
            cout << "Underflow\n";
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
        
        for(int i=front ; i<=rear ; i++)
        {
            cout<<arr[i]<<"\t";
        }
    }
    // ~Queue();
};
int main()
{
    int seats=0;
    cout<<"Enter the number of seats in waiting area"<<endl;
    cin>>seats;
    Queue q1(seats);
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
            string name;
            cin.ignore();
            getline(cin,name);
            q1.EnQueue(name);
        }
        else if(choice==2)
        {
            string name;
            name=q1.Deque();
            cout<<"Sending the next patient : "<<name<<endl;
        }
        else if(choice==3)
        {
            
        }
    }

    
    
}