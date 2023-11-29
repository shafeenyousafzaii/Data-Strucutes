#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int capacity;
    public:
    Stack(int c)
    {
        arr = new int[c];
        top = -1;
        capacity = c;
    }
    bool isFull()
    {
        if(top+1 == capacity)
            return true;
        
        return false;
    }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        
        return false;
    }
    void push(int val)
    {
        if(isFull())
        {
         cout<<"StackOverflow";
            return;
        }
        top++;
        arr[top] = val;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"StackUnderflow";
            return -1;
        }
        int val = arr[top];
        top--;
        return val;
    }

    int peak()
    {
        if(isEmpty())
        {
            cout<<"List is Empty";
            return -1;
        }
        return arr[top];
    }

    void display()
    {
        for(int i = 0; i<=top; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

class Queue
{
    int front, rear, length;
    int capacity;
    int *arr;

public:
    Queue(int s)
    {
        capacity = s;
        front = 0;
        rear = -1;
        arr = new int[s];
        length = 0;
    }
    ~Queue()
    {
        delete[] arr;
    }
    void enqueue(int val)
    {
        if (length == capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (rear == capacity - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
        length++;
    }

    int dequeue()
    {
        if (length == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = arr[front];
        if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        length--;

        return x;
    }

    void print()
    {
        if (length == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int index = front;
        for (int i = 0; i < length; i++)
        {
            cout << arr[index] << " ";
            if (index == capacity - 1)
            {
                index = 0;
            }
            else
            {
                index++;
            }
        }
        cout << endl;
    }
    // void ReverseEven()
    // {
    //     // int front =0;
    //     // int rearr=rear;  
    //     // int *arr=q.arr;
    //     // int length=q.length;
    //     // int capacity=q.capacity;
    //     int frontt=0;
    //     int fronttt=1;
    //     for (int i = 0; i < capacity; i++)
    //     {
    //         for (int j = 0; j < capacity; j++)
    //         {
                
    //             // if(arr[0]%2==0)
    //             // {
    //             //     continue;
    //             // }
    //             if (arr[j] % 2 == 0 )
    //             {
    //                 frontt+2;
    //                 int temp = arr[frontt ];
    //                 arr[frontt ] = arr[j];
    //                 arr[j] = temp;
    //             }
    //             if(arr[j]%3==0)
    //             {
    //                 int temp = arr[fronttt ];
    //                 arr[fronttt ] = arr[j];
    //                 arr[j] = temp;
    //                 fronttt+2;

    //             }
    //         }
    //         frontt = 0;
    //     }
    // }
    void ReverseOdd(Queue &q)
    {
        for(int i = 1 ; i<=q.capacity;i++)
        {
            if(q.arr[i]%2!=0)
            {
                if(q.front==q.rear)
                {
                    break;
                }
                q.front=i;
                int temp=q.dequeue();
                q.front--;
                q.rear=capacity;
                int temp2=q.arr[rear];
                q.enqueue(temp);
                q.front+2;
                q.rear=i;
                q.enqueue(temp2);
                // q.rear=capacity;
                // q.rear=capacity-2;
            }
        }

    }
    
};

int main()
{
    Queue q(11);
    q.enqueue(14);
    q.enqueue(13);
    q.enqueue(17);
    q.enqueue(8);
    q.enqueue(4);
    // q.print();
    // q.dequeue();
    // q.dequeue();
    // q.print();
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(4);
    q.enqueue(15);
    q.enqueue(18);
    q.enqueue(19);
    // q.enqueue(19);
    q.print();

    q.ReverseOdd(q);
    q.print();
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();

    // q.print();

    return 0;
}