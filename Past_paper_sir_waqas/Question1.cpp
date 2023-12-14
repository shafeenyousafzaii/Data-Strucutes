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
    void rearrangeList()
    {
        start();
        int *evenStart = arr; // Pointer to the start of even elements
        int *oddStart = arr;  // Pointer to the start of odd elements

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
    }
};
int main()
{
    list l1(9);
    l1.insert(5, 1);
    l1.insert(2, 2);
    l1.insert(9, 3);
    l1.insert(4, 4);
    l1.insert(7, 5);
    l1.insert(6, 6);
    l1.insert(1, 7);
    l1.insert(3, 8);
    l1.insert(8, 9);
    l1.print();
    l1.rearrangeList();
    l1.print();
}