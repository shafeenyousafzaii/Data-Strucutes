#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    int capacity;
    int length;
    int *arr;
    int front;
    int rear;

public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        length = 0;
        front = 0, rear = -1;
    }

    bool full()
    {
        return length == capacity;
    }

    void enqueue(int val)
    {
        if (full())
        {
            cout << "Overflow" << endl;
            return;
        }

        if (rear == capacity - 1)
            rear = 0;
        else
            rear++;

        arr[rear] = val;
        length++;
    }

    int dequeue()
    {
        if (length == 0)
        {
            cout << "Underflow" << endl;
            return -1; // You might want to handle underflow differently
        }

        int val = arr[front];

        if (front == capacity - 1)
            front = 0;
        else
            front++;

        length--;
        return val;
    }

    int get_length()
    {
        return length;
    }
    void print()
{
    if(length == 0)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    int index = front;
    for(int i = 0 ; i < length ; i++)
    {
        cout<<arr[index]<<" ";
        if(index == capacity-1)
        {
            index = 0;
        }
        else
        {
            index++;
        }
    }
    cout<<endl;

}
};

void reverseEven(Queue &Q)
{
    stack<int> s;

    // Dequeue and push even-positioned elements onto the stack
    for (int i = 1; i <= Q.get_length(); i++)
    {
        int val = Q.dequeue();
        if (i % 2 == 0)
        {
            s.push(val);
        }
        Q.enqueue(val);
    }

    for (int i = 1; i <= Q.get_length(); i++)
    {
        int val = Q.dequeue();
        if (i % 2 == 0)
        {
            // cout << "s=" << s.top() << endl;
            Q.enqueue(s.top());
            s.pop();
        }
        else
        {
            Q.enqueue(val);
        }
    }
}

int main()
{
    Queue q(10);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(9);
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(14);
    q.enqueue(7);
    q.enqueue(15);
    // q.enqueue(19);
    q.print();
    reverseEven(q);

    // Print the modified queue
     while (q.get_length() > 0)
    {
        cout << q.dequeue() << " ";
    }

    return 0;
}
