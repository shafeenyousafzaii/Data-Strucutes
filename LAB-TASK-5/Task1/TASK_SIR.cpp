#include<iostream>
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