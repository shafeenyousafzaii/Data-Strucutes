#include <iostream>
#include <string>
#include "Task.h"
using namespace std;

int main()
{
    AVL t;
    node *root = NULL;
    // root = t.insert(root, 20);
    // root = t.insert(root, 15);
    // root = t.insert(root, 25);
    // root = t.insert(root, 14);
    // root = t.insert(root, 26);
    // root = t.insert(root, 13);
    // root = t.insert(root, 27);
    // root = t.insert(root, 12);
    // cout<<"ROOT IS "<<root->info<<endl;
    // t.printTree(root, NULL, false);
    while (1)
    {
        int choice;
        cout << "1)Insert a value" << endl;
        cout << "2)Delete a value" << endl;
        cout << "3)Display tree(In order traversal)" << endl;
        cout << "4)Update a value" << endl;
        cout << "5)Search a value" << endl;
        cout << "6)Find max" << endl;
        cout << "7)Find min" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int val;
            cin >> val;
            root = t.insert(root, val);
            t.printTree(root, NULL, false);
        }
        else if (choice == 2)
        {
            int val;
            cout << "Enter the value to be deleted" << endl;
            cin >> val;

            t.deleteNode(root, val);

            t.printTree(root, NULL, false);
        }
        else if (choice == 3)
        {
            t.inOrder(root);
        }
        else if (choice == 4)
        {

            t.printTree(root, NULL, false);
            int del;
            cout << "Enter the value you want to update" << endl;
            cin >> del;
            t.deleteNode(root, del);
            t.printTree(root, NULL, false);

            cout << "Enter the updated value" << endl;
            cin >> del;
            t.insert(root, del);
            t.printTree(root, NULL, false);
        }
        else if (choice == 5)
        {
            int val;
            cin >> val;
            if (t.search(root, val) == true)
            {
                cout << "VALUE FOUND" << endl;
            }
            else
            {
                cout << "Value not found" << endl;
            }
        }
        else if (choice == 6)
        {
            node *val = t.findmax(root);
            cout << "Max value is" << val->info << endl;
        }
        else if (choice == 7)
        {
            node *val = t.findmin(root);
            cout << "Min value is" << val->info << endl;
        }
    }
    return 0;
}
