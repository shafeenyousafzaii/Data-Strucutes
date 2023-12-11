#include <iostream>
using namespace std;

class queue
{
    int *arr;
    int front, rear, size, length;
    int *curr;

public:
    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        length = 0;
        front = 0;
        rear = -1;
        curr = arr;
    }
    ~queue()
    {
        delete[] arr;
    }
    bool is_full()
    {
        if(length==size)
        {
            return true;
        }
        return false;
    }
    bool is_empty()
    {
        if(length==0)
        {
            return true;
        }
        return false;
    }

    void enqueue(int val)
    {
        if(is_full())
        {
            cout<<"Over Follow"<<endl;
            return;
        }
        if(rear==size-1)
        {
            rear=0;
        }
        else
        {
            rear++;
            arr[rear]=val;
            length++;
        }
    }

    int dequeue()
    {
        if(is_empty())
        {
            cout<<"Underflow"<<endl;
            return -1;
        }

        int val=arr[front];
        if(front==size-1)
        {
            front=0;
        }
        else
        front++;

        length--;
        return val;
    }
};

int main()
{
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    // cout<<q.dequeue()<<endl;

}