#include <iostream>
#include <string>
using namespace std;
class HashTables
{
public:
    int *arr;
    int capacity;
    int length;
    int curr;
    int percent = 0;
    HashTables(int size = 0)
    {
        this->capacity = size;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = -1;
        }
        curr = -1;
        length = 0;
    };
    // void swap(int *a, int *b)
    // {
    //     int temp = *a;
    //     *a = *b;
    //     *b = temp;
    // }
    void check_index(int val, int arrr[] , int c , int &indexx)
    {
        for(int i=0 ; i<c;i++)
        {
            if(indexx==c)
            {
                indexx=0;
            }
            if(arrr[indexx] != -1)
            {
                indexx++;
            }
            else if(arr[indexx]==-1)
            {
                break;
            }
        }
        return ;
    }
    void insert_hashtable_rehashing(int val)
    {
        if (percent > 70) 
        {
            cout << "Array is more than 70'%' full" << endl;
            int capacity1 = capacity;
            int capacity2 = capacity + capacity;
            int *newarray = new int[capacity2];
            // capacity = capacity2;
            int count = 0;
            for (int i = 0; i < capacity2; i++)
            {
                newarray[i] = -1;
                if (arr[i] != -1)
                {
                    count++;
                }
            }
            length = 0;
            // int count2=-1;
            for (int i = 0; i < capacity; i++)
            {
                if (arr[i] != -1)
                {
                    int index2 = h(arr[i], capacity2);
                    if (index2 == capacity2)
                    {
                        index2 = 0;
                    }
                    if (newarray[index2] != -1)
                    {
                        // cout<<"Index sent"<<index2<<endl;
                        check_index(val,newarray,capacity2,index2);
                        // cout<<"Index returned"<<index2<<endl;
                    }
                    // cout << "values : " << arr[i] << endl;
                    newarray[index2] = arr[i];
                    length++;
                    // count2++;
                }
                if (length == count)
                {
                    break;
                }
                // int new_value=
                // newarray[i]
                // insert(val);
            }
            // h(val,capacity2);
            capacity = capacity2;
            delete[] arr;
            arr = nullptr;
            arr = newarray;
            // return insert(val);
            // return;

            // return;
        }
        // curr++;
        int index = h(val, capacity);
        // cout << "index : " << index << endl;
        // cout << "Value : " << val <<endl;
        if (arr[index] == -1)
        {
            arr[index] = val;
            // length++;
        }
        else
        {
            // length++;
            if (index == capacity - 1)
            {
                index = 0;
            }
            for (int i = 0; i < capacity; i++)
            {
                if (arr[index] == -1)
                {
                    arr[index] = val;
                    // length++;
                    break;
                }
                index++;
            }
            // int index = h(val);
        }
        // arr[curr] = val;
        // length++;
        length++;
        percent = (float(length) / capacity) * 100;
        // cout << " percentage  = " << percent << endl;
    }
    int h(int x, int capacity)
    {
        int index;
        index = x % capacity;
        // cout << "INDEX : " << index << endl;
        return index;
        // index
    }
    void display()
    {
        // curr=arr;
        for (int i = 0; i < capacity; i++)
        {
            // if (arr[i] == -1)
            // {
            //     continue;
            // }
            // else
            // {
            cout << "  " << (arr[i]);
            // }
        }
    };
    ~HashTables()
    {
        delete[] arr;
    };
};
int main()
{
    HashTables r1(7);
    r1.insert_hashtable_rehashing(13);
    r1.insert_hashtable_rehashing(15);
    r1.insert_hashtable_rehashing(24);
    r1.insert_hashtable_rehashing(6);
    r1.display();
    cout<<endl;
    r1.insert_hashtable_rehashing(23);
    r1.insert_hashtable_rehashing(1);
    r1.insert_hashtable_rehashing(2);
    r1.insert_hashtable_rehashing(3);
    r1.insert_hashtable_rehashing(4);
    // // r1.insert(5);
    r1.display();
}
