#include <iostream>
#include <string>
#include "BookManagement.h"
using namespace std;
int main()
{
    BookManagement b1;
    int choice;
    while (true)
    {
        cout << "Library Management System" << endl;
        cout << "1. Add a New Book" << endl;
        cout << "2. Search for a Book" << endl;
        cout << "3. Filter Books by Author" << endl;
        cout << "4. Recommend Related Books" << endl;
        cout << "5. Delete a Book" << endl;
        cout << "6. Print the books" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int isbn, day, month, year;
            string author, title, genre;
            cout << "Enter ISBN: ";
            cin >> isbn;
            cout << "Enter Author: ";
            cin >> author;
            cout << "Enter Title: ";
            cin >> title;
            cout << "Enter Genre: ";
            cin >> genre;
            cout << "Enter Publication Date (day month year): ";
            // int day, month, year;
            cin >> day >> month >> year;
            b1.insert(day, month, year, isbn, author, title, genre);
        }
        else if (choice == 2)
        {
            int isbn;
            cout << "Enter the isbn number to find the book" << endl;
            cin >> isbn;
            bool yes = b1.find(isbn);
            if (yes == true)
            {
                cout << "Book found" << endl;
            }
            else
            {
                cout << "Book not found" << endl;
            }
        }
        else if (choice == 3)
        {
            string name;
            cout << "Enter authors name" << endl;
            cin.ignore();
            getline(cin, name);
            // cout<<"NAME : "<<name<<endl;
            bool yes = b1.find(name);
            if (yes == true)
            {
                cout << "Book found" << endl;
            }
            else
            {
                cout << "Book not found" << endl;
            }
        }
        else if (choice == 4)
        {
            string name;
            int val=0;
            cout << "Enter authors name" << endl;
            cin.ignore();
            getline(cin, name);
            // cout<<"NAME : "<<name<<endl;
            bool yes = b1.find(name,val);
            if (yes == true)
            {
                cout << "Books found" << endl;
            }
            else
            {
                cout << "Books not found" << endl;
            }
        }
        else if (choice == 5)
        {
            int val;
            cout<<"Enter ISBN number"<<endl;
            cin>>val;
            b1.remove(val);
        }
        else if (choice == 6)
        {
            b1.printBooks();
        }
        else if (choice == 7)
        {
            cout << " EXITING " << endl;
            break;
        }
        else
        {
            cout << "Wrong input" << endl;
            continue;
        }
    }
}