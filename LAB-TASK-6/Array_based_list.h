#include <iostream>
using namespace std;

class list
{
private:
    int *arr;
    int *curr;
    int length;
    int capacity;
    void next()
    {
        curr++;
    }
    void back()
    {
        curr--;
    }
    void start()
    {
        curr = arr;
    }
    void tail()
    {
        curr = arr + length - 1;
    }

public:
    list(int size = 0)
    {
        capacity = size;
        arr = new int[size];
        length = 0;
        curr = arr;
    }

    ~list()
    {
        delete[] arr;
    }

    void insert(int V, int I)
    {
        if (length == capacity)
        {
            cout << "Overflow" << endl;
            return;
        }
        if (1 > I || I > length + 1)
            cout << "\nInvalid index\n";
        tail();
        for (int i = length; i >= I; i--)
        {
            *(curr + 1) = *curr;
            back();
        }
        *(curr + 1) = V;
        length++;
    }
    void remove(int pos)
    {
        if (length == 0)
        {
            cout << "Empty" << endl;
            return;
        }
        if (pos < 1 || pos > length)
            cout << "\nInvalid index\n";
        start();
        curr = arr + pos - 1;
        for (int i = pos; i < length; i++)
        {
            (curr) = (curr + 1);
            next();
        }
        length--;
    }
    bool is_empty()
    {
        if (length == 0)
        {
            return false;
        }
        else
            return true;
    }
    int find(char val)
    {
        if (!is_empty())
        {
            start();
            for (int i = 1; i <= length; i++)
            {
                if (val == *curr)
                {
                    return i;
                }
                next();
            }
        }
        else
            cout << "List is empty" << endl;
    }
    void update(int V, int I)
    {
        if (1 > I || I > length + 1)
        {
            cout << "\nInvalid index\n";
            return;
        }
        start();
        *(curr + I - 1) = V;
    }
    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << *(arr + i) << "|";
        }
        cout << endl;
    }

    int get(int P)
    {
        if (1 > P || P > length + 1)
        {
            cout << "\nInvalid index\n";
        }
        start();
        return *(curr + P - 1);
    }

    int Length()
    {
        return length;
    }

    void copy(list l)
    {
        length = l.length;
        capacity = l.capacity;
        arr = new int[capacity];
        for (int i = 0; i < length; i++)
        {
            *(arr + i) = *(l.arr + i);
        }
    }

    void clear()
    {
        delete[] arr;
        curr = NULL;
        length = 0;
    }
    // void rearrangeList()
    // {
    //     start();
    //     int *second = arr+1;
    //     int count;
    //     for (int i = 1; i < length / 2 + 1; i++)
    //     {
    //         for (int j = 1; j < length; j++)
    //         {
    //             // if(i>=1 && j>1)
    //             // {
    //             // second++;
    //             // }
    //             if (*curr % 2 == 0 )
    //             {
    //                 int temp;
    //                 temp = *curr;
    //                 *curr = *second;
    //                 *second = temp;
    //                 count++;
    //                 next();
    //                 next();
    //             }
    //             second++;
    //         }
    //         second=&arr[count];
            
    //         next();
    //         // second++;
    //     }
    //     // for (int i = 1; i <= length ; i++)
    //     // {
    //     //         // if(i>=1 && j>1)
    //     //         // {
    //     //         // second++;
    //     //         // }
    //     //         if (*curr % 2 == 0 )
    //     //         {
    //     //             int temp;
    //     //             temp = *curr;
    //     //             *curr = *second;
    //     //             *second = temp;
    //     //             count++;
    //     //             next();
    //     //             // next();
    //     //         }
    //     //         second++;
    //     //     }
        

    //     // // start();
    // }
    void rearrangeList()
{
    start();
    int *evenStart = arr;  // Pointer to the start of even elements
    int *oddStart = arr;   // Pointer to the start of odd elements

    for (int i = 0; i < length; i++)
    {
        if (*curr % 2 == 0)
        {
            int temp = *curr;
            *curr = *evenStart;
            *evenStart = temp;
            evenStart++;
        }
        else
        {
            oddStart++;
        }

        next();
    }
    cout<<"Arranging even-odd"<<endl;
    print();
    cout<<"After re-arranging"<<endl;
    start();
    while(*curr%2==0)
    {
        curr++;
    }
    // next();
    int *curr2=arr+1;
    while(*curr2%2==0)
    {
        int temp;
        temp=*curr;
        *curr=*curr2;
        *curr2=temp;
        curr2=curr2+2;
        next();
    }

}

};
