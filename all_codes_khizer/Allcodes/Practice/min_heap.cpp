#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
    vector<int> htree;

    int getParent(int child)
    {
        int a = (child - 1) / 2;
        if(child==0)
        {
            return -1;
        }
        else if (a <htree.size())
        {
            return a;
        }

        else
            return -1;
    }
    int getLeft(int parent)
    {
        int a = 2 * parent + 1;
        if (a < htree.size())

        {
            return a;
        }
        else
            return -1;
    }

    int getRight(int parent)
    {
        int a = 2 * parent + 2;
        if (a < htree.size())
        {
            return a;
        }
        else
            return -1;
    }
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node)
    {
        int parent = getParent(node);
        if (node >=0&& parent != -1 && htree[parent] > htree[node])
        {
            swap(&htree[parent], &htree[node]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int node)
    {
        int left = getLeft(node);
        int right = getRight(node);
        int smallest = node;
        if (left != -1 && htree[left] < htree[smallest])
        {
            smallest = left;
        }
        if (right != -1 && htree[right] < htree[smallest])
        {
            smallest = right;
        }
        if (smallest != node)
        {
            swap(&htree[node], &htree[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(int val)
    {
        int size = htree.size();
        if (size == 0)
        {
            htree.push_back(val);
        }
        else
        {
            htree.push_back(val);
            heapifyUp(htree.size() - 1);
        }
    }

    void dele()
    {
        int size = htree.size();
        if (size == 0)
            return;
        swap(&htree[0], &htree[size - 1]);
        htree.pop_back();
        heapifyDown(0);
    }

    void display()
    {
        for (int i = 0; i < htree.size(); i++)
        {
            cout << htree[i] << " ";
        }
    }
};
int main()
{
    Heap a;
    a.insert(10);
    a.insert(4);
    a.insert(2);
    a.insert(5);
    a.insert(1);
    a.display();
    cout << endl;
    a.dele();
    a.display();
    cout << endl;
    a.dele();
    a.display();
}