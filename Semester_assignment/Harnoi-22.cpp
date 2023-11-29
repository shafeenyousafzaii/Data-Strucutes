#include <iostream>
#include <string>
#include "Harnoi-22.h"
using namespace std;
int main(int argc, char const *argv[])
{

    cout << "Welcome to TOWER OF HARNOI puzzle" << endl;

    int disks = 0;
    cout << "How many disks?" << endl;
    cin >> disks;
    // bool yes;
    // if (disks % 2 == 0)
    // {
    //     yes = true;
    // }
    // disks=disks+1;
    Stack Source(disks), Destination(disks), Auxiliary(disks);
    // int count = 0;
    int choice = 0;
    int count = 0;

    while (choice < 3)
    {
        cout << "1)Insert Disks       " << endl;
        cout << "2)Perform Operation  " << endl;
        cout << "3)Finish             " << endl;
        cin >> choice;
        if (choice == 1)
        {
            int weight = 0;

            if (count == disks)
            {
                cout << "No more disks can be inserted" << endl;
                continue;
            }
            cout << "Enter Disk weight" << endl;

            cin >> weight;
            // if (yes == true)
            // {
            //     Destination.push(weight);
            // // }
            // els?e
            // // {??
            Source.push(weight);
            // }
            count++;
        }
        else if (choice == 2)
        {
            Source.display();
         
            Source.Hanoii(Destination, Auxiliary, disks);
          
        }
        else
        {
            cout << "You asked to exit the program" << endl;
            break;
        }

        // return 0;
    }
}