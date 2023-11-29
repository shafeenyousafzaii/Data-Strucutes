#include <iostream>
#include <string>
#include <iostream>
using namespace std;
class Student
{
public:
    string student_name;
    int student_merit;
    Student *next;

    Student(string student_name = "", int student_merit = 0)
    {
        this->student_name = student_name;
        this->student_merit = student_merit;
        next = NULL;
    }
};

class Queue
{
    Student *head;
    int length;

public:
    Queue()
    {
        head = NULL;
        length = 0;
    }
    ~Queue()
    {
        Student *curr = NULL;
        while (head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    void enqueue(string name, int merit)
    {
        Student *n = new Student(name, merit);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Student *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
        length++;
    }

    int dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = head->student_merit;
        Student *temp = head;
        head = head->next;
        delete temp;
        length--;
        return x;
    }

    void print()
    {
        Student *curr = head;
        while (curr != NULL)
        {
            cout << curr->student_merit << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void seewhoisnext()
    {
        if (length != 0)
        {
            cout << "Student Name : " << head->student_name << endl;
            cout << "Student Merit: " << head->student_merit << endl;
        }
        else
        {
            cout << "No Students to show" << endl;
        }
    }
    void process_admission(Queue &q1, Queue &q2, Queue &q3);
    void Check_queue_status(Queue &q1, Queue &q2, Queue &q3);
};
void Queue::process_admission(Queue &q1, Queue &q2, Queue &q3)
{

    if (q1.length == 0 && q2.length == 0 && q3.length == 0)
    {
        cout << "No admissions to process" << endl;
        return;
    }

    if (((q1.length <= q2.length) && (q1.length <= q3.length) && (q1.length != 0)) || ((q1.length >= q2.length) && (q1.length >= q3.length) && (q1.length != 0)))
    {
        // cout<<"HERE"<<endl;
        Student *curr = q1.head;
        cout << " Processing the shortest Queue : Q1 " << endl;
        while (curr != NULL)
        {
            try // learned from W3Tutorials
            {
                if (curr->student_merit > 50)
                {
                    q1.dequeue();
                    curr = curr->next;
                }
                else
                {
                    throw(curr->student_name);
                }
            }
            catch (string name)
            {
                cout <<"Dear "<<name<<"! \n Merit must be greater than 50 in order to proceed forward for admission " << endl;
                curr = curr->next;
                q1.dequeue();
            }
        }
    }
    if (((q2.length >= q1.length) && (q2.length >= q3.length) && (q2.length != 0)) || ((q2.length <= q1.length) && (q2.length <= q3.length) && (q2.length != 0)))
    {

        Student *curr = q2.head;
        cout << " Processing the shortest Queue : Q1 " << endl;
        while (curr != NULL)
        {
            try // learned from W3Tutorials
            {
                if (curr->student_merit > 50)
                {
                    q2.dequeue();
                    curr = curr->next;
                }
                else
                {
                    throw(curr->student_name);
                }
            }
            catch (string name)
            {
                cout <<"Dear "<<name<<"! \n Merit must be greater than 50 in order to proceed forward for admission " << endl;
                curr = curr->next;
                q2.dequeue();
            }
        }
    }
    if (((q3.length >= q1.length) && (q3.length >= q2.length) && (q3.length != 0)) || ((q3.length <= q1.length) && (q3.length <= q2.length) && (q3.length != 0)))
    {

        Student *curr = q3.head;
        cout << " Processing the shortest Queue : Q1 " << endl;
        while (curr != NULL)
        {
            try // learned from W3Tutorials
            {
                if (curr->student_merit > 50)
                {
                    q3.dequeue();
                    curr = curr->next;
                }
                else
                {
                    throw(curr->student_name);
                }
            }
            catch (string name)
            {
                cout <<"Dear "<<name<<"! \n Merit must be greater than 50 in order to proceed forward for admission " << endl;
                curr = curr->next;
                q3.dequeue();
            }
        }
    }
    // }
    /*if (curr->student_merit > 50)
            {
                q3.dequeue();
                curr = curr->next;
            }
            else
            {
                cout << "You are not eligible" << endl;
                q3.dequeue();
                curr = curr->next;
            }*/
}
void Queue::Check_queue_status(Queue &q1, Queue &q2, Queue &q3)
{
    // for (int i = 0; i < 3; i++)
    //

     if (q1.length == 0 && q2.length == 0 && q3.length == 0)
    {
        cout << "All Queues are empty" << endl;
        return;
    }

    Student *curr = q1.head;
    cout << "No of Students in the queue 1" << endl;
    for (int i = 0; i < q1.length; i++)
    {
        cout << "Student Name    : " << curr->student_name << endl;
        cout << "Student Merit   : " << curr->student_merit << endl;
        cout << "Num of students : " << q1.length << endl;
        curr = curr->next;
    }

    curr = q2.head;
    cout << "No of Students in the queue 2" << endl;
    for (int i = 0; i < q2.length; i++)
    {
        cout << "Student Name    : " << curr->student_name << endl;
        cout << "Student Merit   : " << curr->student_merit << endl;
        cout << "Num of students : " << q1.length << endl;
    }

    curr = q3.head;
    cout << "No of Students in the queue 3" << endl;
    for (int i = 0; i < q3.length; i++)
    {
        cout << "Student Name    : " << curr->student_name << endl;
        cout << "Student Merit   : " << curr->student_merit << endl;
        cout << "Num of students : " << q1.length << endl;
    }

    // }
}