#include <iostream>
#include <vector>
using namespace std;

class Patient
{
public:
    string name;
    int urgency;

    Patient(string name, int urgency)
    {
        this->name = name;
        this->urgency = urgency;
    }
};

class Heap
{
public:
    vector<Patient> htree;

    int getParent(int child)
    {
    }

    int getLeft(int parent)
    {
        int leftchild = 2 * (parent) + 1;
        if (htree.size() < leftchild)
        {
            return -1;
        }
        else
        {
            return leftchild;
        }
    }

    int getRight(int parent)
    {
        int rightchild = 2 * (parent) + 2;

        if (parent > htree.size())
        {
            return -1;
        }
        else
        {
            return rightchild;
        }
        
    }

    void swap(Patient *a, Patient *b)
    {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node)
    {
        int parent = node;
        int inserted = htree[htree.size()].urgency;
        if (/*parent <*/ htree[inserted].urgency > parent)
        {
            int temp = htree[inserted].urgency;
            htree[inserted].urgency = htree[parent].urgency;
            htree[parent].urgency = temp;
        }
    }

    void heapifyDown(int node)
    {
        
        // cout << "WORKING 3" << endl;
        // display();
        int leftchild = getLeft(node);
        int rightchild = getRight(node);
        int smallest = node;
        // cout << "WORKING 4" << endl;
        // display();
        if (htree[node].urgency > htree[smallest].urgency )
        {
            // swap(&htree[node], &htree[leftchild]);
            // cout << "WORKING INSIDE 2" << endl;
            // display();
            smallest = leftchild;
        }
        // cout << "WORKING 5" << endl;
        // display();
        cout<<htree[node].urgency<<endl;
        if (htree[node].urgency > htree[smallest].urgency)
        {
            // swap(&htree[node], &htree[rightchild]);
            // cout << "WORKING INSIDE 3" << endl;
            // display();
            smallest = rightchild;
        }

        //  leftchild = 2 * (node) + 1;
        //  rightchild = 2 * (node) + 2;
        // cout << "WORKING 6" << endl;
        // display();
        if(smallest!=node)
        {
            
            swap(&htree[node], &htree[smallest]);
            heapifyDown(smallest);
        }
        // cout << "WORKING 7" << endl;
        
        // display();
        // heapifyDown(rightchild);
    }

    void insert(Patient patient)
    {

        htree.push_back(patient);
        int index = htree.size();
        int parent = (index - 1) / 2;
        heapifyUp(parent);
        // int size=htree.size();

        // htree[i]=patient;
    }

    void del()
    {
        swap(&htree[0], &htree[htree.size() - 1]);
        // cout << "WORKING 1" << endl;
        // display();
        htree.pop_back();
        // cout << "WORKING 2" << endl;
        // display();
        heapifyDown(0);
        // cout << "WORKING 3" << endl;
        // display();
    }

    void updateUrgency(string patientName, int newUrgency)
    {
    }

    void display()
    {
        if (htree.empty())
        {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++)
        {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
    }
    void send_next_patient()
    {
        cout<<"Sending next patient"<<endl;
        cout<<"Name : "<<htree[htree.size()-1].name<<endl;
        cout<<"Urgency : "<<htree[htree.size()-1].urgency<<endl;
        del();
    }
};

int main()
{
    Heap priorityQueue;

    // Schedule appointments
    Patient p1("Ali", 3);
    Patient p2("Bilal", 1);
    Patient p3("Alina", 2);
    Patient p4("Hashir", 4);
    int i;
    priorityQueue.insert(p1);
    priorityQueue.insert(p2);
    priorityQueue.insert(p3);
    priorityQueue.insert(p4);

    // Display appointments
    // priorityQueue.display();

    // Send next patient to the doctor
    cout << "Sending next patient to the doctor:" << endl;
    priorityQueue.display();
    priorityQueue.del();
    priorityQueue.display();
    priorityQueue.send_next_patient();
    priorityQueue.display();
    // Update urgency level
    // priorityQueue.updateUrgency("Ali", 5);
    // priorityQueue.display();

    return 0;
}
