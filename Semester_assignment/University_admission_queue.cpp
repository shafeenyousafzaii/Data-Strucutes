#include <iostream>
#include <string>
#include "University_admission_queue.h"
using namespace std;
void printMenu()
{
    cout << "1. Add Student" << endl;
    cout << "2. Process Admission" << endl;
    cout << "3. Check Queue Status" << endl;
    cout << "4. See Next" << endl;
    cout << ">5. Exit" << endl;
}
int main()
{

    Queue q, q1, q2, q3;
    int choice;

    int count = 0;
    do
    {
        printMenu();
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int merit;
            string name;
            cout << "Enter your name" << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Enter your merit" << endl;
            try
            {
                cin >> merit;
                if(merit>100)
                {
                    throw(merit);
                }
            }
            catch (int merit)
            {
                cout<<"Enter a valid merit (0-100)"<<endl;
                continue;
            }

            if (count == 0)
            {
                q1.enqueue(name, merit);
                count++;
                // break;
            }
            else if (count == 1)
            {
                q2.enqueue(name, merit);
                count++;
            }
            else if (count == 2)
            {
                q3.enqueue(name, merit);
                count = 0;
            }
        }
        else if (choice == 2)
        {
            q.process_admission(q1, q2, q3);
        }
        else if (choice == 3)
        {
            q1.Check_queue_status(q1, q2, q3);
        }
        else if (choice == 4)
        {
            int queue_number;
            cout << "What queue number do you want to check" << endl;
            cin >> queue_number;
            if (queue_number == 1)
            {
                q1.seewhoisnext();
            }

            if (queue_number == 2)
            {
                q2.seewhoisnext();
            }

            if (queue_number == 3)
            {
                q3.seewhoisnext();
            }
        }
    } while (!(choice >= 5));
    cout << "Invalid choice" << endl;
    return 0;
}