#include <iostream>
#include <string>
#include "Task2.h"
using namespace std;
int main()
{

    int choice = 0, count = 0;
    string name = "";
    cout << "Enter a string you want to reverse" << endl;
    // cin.ignore();
    getline(cin, name);
    int range = name.length();
    Stack s1(range);
    count = 1;
    while (1)
    {
        cout << "Reverse your string NOW!!!" << endl;
        cout << "1) First insert the string" << endl;
        cout << "2) Now Reverse a string" << endl;
        cin >> choice;
        if (choice == 1)
        {
            if (count <= 1)
            {
                cout << "You have already entered a string , you can only reverse it" << endl;
                for (int i = 0; i < name.length(); i++)
                {
                    char charr;
                    charr = name[i];
                    s1.push(charr);
                }
            }
            else
            {
                // cin.ignore();
                getline(cin, name);
                count = 1;
            }
        }
        else if (choice == 2)
        {
            if (name.length() <= 0)
            {
                cout << "You do not have a string" << endl;
            }
            else if (name.length() > 0)
            {

                for (int i = 0; i <= name.length() - 1; i++)
                {
                    char charr;
                    charr = s1.pop();
                    cout << charr;
                }
                cout << endl;
            }
            count = 2;
        }
        else
        {
            cout << "You asked to abort!  , Not my fault" << endl;
            break;
        }
    }
}