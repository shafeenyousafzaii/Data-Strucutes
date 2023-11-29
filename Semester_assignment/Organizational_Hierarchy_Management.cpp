#include <iostream>
#include <string>
#include "Organizational_Hierarchy_Management.h"
int main()
{
    AVL a;
    int choice = 0;
    node *root = NULL;

    while (choice != 7)
    {
        cout << "1)Add Employee                   " << endl;
        cout << "2)Search For employee            " << endl;
        cout << "3)Generate Organizational char   " << endl;
        cout << "4)Modify Employee Information    " << endl;
        cout << "5)Remove Employee                " << endl;
        cout << "6)Print                          " << endl;
        cout << "7)Exit                           " << endl;
        cin >> choice;
        if (choice == 1)
        {
            int ID;
            string Employeename, Employeedesignation, EmployeeDepartment;
            cout << "Enter Employee ID           " << endl;
            cin >> ID;
            cout << "Enter Employee Name         " << endl;
            cin.ignore();
            getline(cin, Employeename);
            // cin >> Employeename;
            // cin.ignore();
            cout << "Enter Employee Department  " << endl;
            getline(cin, EmployeeDepartment);
            // cin >> EmployeeDepartment;
            // cin.ignore();
            cout << "Enter Employee Designation  " << endl;
            getline(cin, Employeedesignation);
            // cin >> Employeedesignation;
            root = a.insert(root, ID, Employeename, EmployeeDepartment, Employeedesignation);
        }
        else if (choice == 2)
        {
            int ID;
            cout << "Enter employee's ID" << endl;
            cin >> ID;
            a.Search_for_Employee(root,ID);
        }
        else if (choice == 3)
        {
            int A = 0;
            a.printTree(root, NULL, false, A);
        }
        else if (choice == 4)
        {

            int ID;
            cout << "Enter employee's ID" << endl;
            cin >> ID;
            a.Modify_Employee(root,ID);
        }
        else if (choice == 5)
        {
            int ID, A = 0;
            cout << "Enter the ID of the Employee you wanna remove" << endl;
            cin >> ID;
            a.deleteNode(root, ID);
            a.printTree(root, NULL, false);
        }
        else if (choice == 6)
        {
            int aa=0;
            cout<<endl;
            a.printTree(root, NULL, false);
        }
        else
        {
            cout << "incorrect input" << endl;
            continue;
        }

        // return 0;
    }
}