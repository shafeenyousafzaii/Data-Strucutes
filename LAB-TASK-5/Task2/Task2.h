#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    char *curr;
    int capacity;
    int top;

public:
    Stack(int s)
    {
        capacity = s;
        curr = new char[s];
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
    void push(char val)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        curr[top] = val;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack UnderFlow" << endl;
            return -1;
        }
        char val = curr[top];
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
