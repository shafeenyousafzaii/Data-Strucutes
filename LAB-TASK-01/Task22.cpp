#include <iostream>
#include <string>
using namespace std;

bool check_palindrome(string &name);
void check_frequency(string name);

int main()
{
    string name;
    int choice;

    while (choice != 3)
    {
        cout << "Enter your name:" << endl;
        cin >> name;
        cout << name << endl;
        cout << "Enter 1 to check if it is a palindrome               " << endl;
        cout << "Enter 2 to check the frequency of a certain character" << endl;
        cout << "Enter 3 to exit                                      " << endl;
        cin >> choice;

        if (choice == 1)
        {
            if (check_palindrome(name))
            {
                cout << "It is a palindrome    " << endl;
            }
            else
            {
                cout << "It is not a palindrome"<< endl;
            }
        }
        else if (choice == 2)
        {
            check_frequency(name);
        }
        else if (choice == 3)
        {
            break;
        }
    }

    return 0;
}

bool check_palindrome(string &name)
{
    int length = name.length();
    for (int i = 0; i < length / 2; i++)
    {
        if (name[i] != name[length - i - 1])
        {
            return false;
        }
    }
    return true;
}

void check_frequency(string name)
{
    char character;
    cout << "Enter the character to check its frequency" << endl;
    cin >> character;
    int count = 0;
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == character)
        {
            count++;
        }
    }
    cout << "The frequency of " << character << " is " << count << endl;
}
