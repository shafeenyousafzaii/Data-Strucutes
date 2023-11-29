#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Stack
{
private:
    int *curr;
    int capacity;
    int top;

public:
    Stack(int s = 0)
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
        cout << endl;
    }
    ~Stack()
    {
        delete curr;
    };
    // void Harnoi(Stack &q2, Stack &q3, int val)
    // {
    //     int vall = pow(val, 2) - 1;
    //     cout << vall << endl;
    //     while (vall != 0)
    //     {
    //         // int count=0;++
    //         cout << vall << endl;

    //         if ((curr[top] < q2.curr[q2.top]) || ((q2.isEmpty() == true))) // to shift the disk by one step to other rod or shift it to the second again if disk is less than the one already in the second
    //         {
    //             cout << "Moving disk from rod 1 to the second rod" << endl;
    //             int val;
    //             val = pop();
    //             q2.push(val);
    //             vall--;
    //             // continue;
    //         }
    //         else if ((curr[top] < q3.curr[q3.top]) || (q3.isEmpty() == true)) // to shift the disk by one step to other auxilliary rod or shift it to the auxilliary again if disk is less than the one already in the auxilliary
    //         {
    //             cout << "Moving disk from rod 1 to the aux rod" << endl;
    //             int val;
    //             val = pop();
    //             q3.push(val);
    //             vall--;
    //             // continue;
    //         }
    //         else if (q2.curr[q2.top] < q3.curr[q3.top])
    //         {
    //             cout << "Moving disk from rod 2 to the aux rod" << endl;
    //             int val;
    //             val = q2.pop();
    //             q3.push(val);
    //             vall--;
    //             // continue;
    //         }
    //         else if (q2.curr[q2.top] < curr[top])
    //         {
    //             cout << "Moving disk from rod aux to the first rod" << endl;
    //             int val;
    //             val = q2.pop();
    //             q3.push(val);
    //             vall--;
    //             // continue;
    //         }
    //         else if (q3.curr[q3.top] < curr[top])
    //         {
    //             cout << "Moving disk from rod 3 to the first rod" << endl;
    //             int val;
    //             val = q3.pop();
    //             push(val);
    //             vall--;
    //             // continue;
    //         }
    //         else if (q3.curr[q3.top] < q2.curr[q2.top])
    //         {
    //             cout << "Moving disk from rod aux to the second rod" << endl;
    //             int val;
    //             val = q3.pop();
    //             q2.push(val);
    //             vall--;
    //             // continue;
    //         }
    //     }
    // }
    void Hanoi(Stack &Destination, Stack &Auxiliary, int val)
    {
        int vall = pow(2, val) - 1;
        int i = 1;
        if (val % 3 == 0)
        {
            while (i != vall + 1)
            {
                if (i % 3 == 1)
                {
                    if (curr[top] < Destination.curr[Destination.top] || Destination.isEmpty() == true)
                    {
                        cout << "Moving Disk from Source to Destination" << endl;
                        int val = pop();
                        Destination.push(val);
                    }
                    // else if (Destination.curr[Destination.top] < curr[top])
                    // {

                    // }
                }
                else if (i % 3 == 2)
                {

                    if (curr[top] < Auxiliary.curr[Auxiliary.top] || Auxiliary.isEmpty() == true)
                    {
                        cout << "Moving Disk from Source to Auxiliary" << endl;

                        int val = pop();
                        Auxiliary.push(val);
                    }
                }
                else if (i % 3 == 0)
                {

                    if (Auxiliary.curr[Auxiliary.top] < Destination.curr[Destination.top] || Auxiliary.isEmpty() == true)
                    {
                        cout << "Moving Disk from Auxiliary to Destination" << endl;

                        int val = Auxiliary.pop();
                        Destination.push(val);
                    }
                    // else if( Destination.curr[Destination.top] )
                }
                i++;
            }
            return;
        }
         if (val % 2 == 0)
        {
            while (i != vall + 1)
            {
                if (i % 3 == 1)
                {
                    if (curr[top] < Auxiliary.curr[Auxiliary.top] || Auxiliary.isEmpty() == true)
                    {
                        cout << "HERE 1" << endl;
                        cout << "Moving Disk from Source to Auxiliary" << endl;
                        int val = pop();
                        cout << val << endl;
                        Auxiliary.push(val);
                    }
                    // else if (Destination.curr[Destination.top] < curr[top])
                    // {

                    // }
                }
                if (i % 3 == 2)
                {

                    cout << "HERE 2" << endl;

                    if (curr[top] < Destination.curr[Destination.top] || Destination.isEmpty() == true)
                    {

                        cout << "Moving Disk from Source to Destination" << endl;
                        int val = pop();
                        cout << val << endl;
                        Destination.push(val);
                    }
                }
                if (i % 3 == 0)
                {

                    cout << "HERE 3" << endl;
                    if (Auxiliary.curr[Auxiliary.top] < Destination.curr[Destination.top] || Auxiliary.isEmpty() == true)
                    {

                        cout << "Moving Disk from Auxiliary to source" << endl;
                        int val = Auxiliary.pop();

                        cout << val << endl;
                        Destination.push(val);
                    }
                    // else if( Destination.curr[Destination.top] )
                }
                i++;
            }
            return;
        }
    }
    void print()
    {
        int curr2 = top;
        for (int i = 0; i <= capacity - 1; i++)
        {
            int val;
            val = curr[curr2];
            curr2--;
            cout << " " << val << " " << endl;
        }
    }
};
