#include <iostream>
using namespace std;
class arraylist
{
    int *arr;
    int *curr;
    int size;
    int length;
    void next()
    {
        curr++;
    }
    void prev()
    {
        curr--;
    }
    void start()
    {
        curr = arr;
    }
    void end()
    {
        curr = arr + length - 1;
    }

public:
    arraylist(int size)
    {
        this->size = size;
        arr = new int[size];
        curr = arr;
        length = 0;
    }
    ~arraylist()
    {
        delete [] arr;
    }

    void insert(int val, int index)
    {
        if (length == size)
        {
            cout << "List is full" << endl;
            return;
        }
        if (index < 1 && index >= size)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        end();
        for(int i=length;i>=index;i--)
        {
            *(curr+1)=*curr;
            prev();
        }
        *(curr+1) = val;
        length++;
    }
    bool is_empty()
    {
        if(length==0)
        {
            return true;
        }
        else
        return false;
    }

    void remove(int index)
    {

        if(is_empty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        if(index<1 || index>length)
        {
            cout<<"Invalid Index"<<endl;
            return;
        }
        curr=arr+index-1;
        for(int i=index;i<length;i++)
        {
            *curr=*(curr+1);
            next();
        }
        length--;
    }

    int find (int val)
    {
          if(is_empty())
        {
            cout<<"List is empty"<<endl;
            return -1;
        }
        start();
        for(int i=1;i<=length;i++)
        {
            if(val==*curr)
            {
                return i;
            }
            next();
        }
        return -1;
    }

    void print()
    {
        start();
        for(int i=0;i<length;i++)
        {
            cout<<*curr<<" ";
            next();
        }
    }
};

int main()
{
    arraylist list(5);
    list.insert(1,1);
    list.insert(2,2);
    list.insert(3,3);
    list.insert(4,4);
    list.insert(5,5);
    list.print();
    list.remove(3);
    list.print();
}