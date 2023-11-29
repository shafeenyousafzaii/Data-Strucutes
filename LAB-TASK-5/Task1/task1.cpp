#include <iostream>
#include <string>
#include "Task.h"
using namespace std;
int main()
{
    Stack s1(2);
    int choice = 0;
    int count=0;
    int numbers[2];
    cout << "Swap numbers using stack" << endl;
    while (1)
    {
        cout << "1)Insert two elements" << endl;
        cout << "2)Remove" << endl;
        cout << "3)Display" << endl;
        cout << "4)Swap" << endl;
        cout << "5)Exit" << endl;
        cin>>choice;
        if (choice == 1)
        {
            cout << "Enter the First number you want to enter" << endl;
            cin >> numbers[0];
            s1.push(numbers[0]);
            cout << "Enter the Second number you want to add" << endl;
            cin >> numbers[1];
            s1.push(numbers[1]);
        }
        else if (choice == 2)
        {
            if(count>=2)
            {
                cout<<"You cannot pop more items because the list is empty"<<endl;
                // count=0;
                break;
            }
            s1.pop();
            count++;
            
        }
        else if (choice == 3)
        {
            if(count==2)
            {
                cout<<"No elements are present in the array"<<endl;
            }
            s1.display();
        }
        else if (choice == 4)
        {
            if(count>=2)
            {
                cout<<"Stack is empty you cannot swap"<<endl;
                break;
            }
            count=2;
            int i = 0;
            while (i != 2)
            {
                
                numbers[i] = s1.pop();
                i++;
                count++;

            }
            cout << "Your swapped numbers are : " << numbers[0] << " " << numbers[1] << endl;

        }
        else
        {
            break;
        }
    }
    cout << "Thankyou for using the swap operatoin" << endl;
}