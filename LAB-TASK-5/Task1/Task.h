#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    int *curr;
    int capacity;
    int top;

public:
    Stack(int s)
    {
        capacity = s;
        curr = new int[s];
        top = -1;
    };
    bool isEmpty()
    {
        if (top == -1)
            return true;

        return false;
    }
    bool isFull()
    {
        if (top + 1 == capacity)
            return true;

        return false;
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        curr[top] = val;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack UnderFlow" << endl;
            return -1;
        }
        int val = curr[top];
        top--;
        return val;
    }
    int peak()
    {
        if (isEmpty())
        {
            cout << "List is Empty";
            return -1;
        }
        return curr[top];
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << curr[i] << " ";
        }
        cout<<endl;
    }
    ~Stack()
    {
        delete curr;
    };
};
