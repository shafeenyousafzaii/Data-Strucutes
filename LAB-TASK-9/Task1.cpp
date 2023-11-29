#include <iostream>
#include <string>
#include "Changes2_100.h"
int main()
{
    BST t;
    t.set_root(t.insert(t.Root, 50, "Zircon"));
    t.insert(t.Root, 20, "Diamond");
    t.insert(t.Root, 5, "Jade");
    t.insert(t.Root, 10, "Opal");
    t.insert(t.Root, 30, "Ruby");
    t.insert(t.Root, 70, "Sapphire");
    t.insert(t.Root, 60, "Garnet");
    t.insert(t.Root, 40, "Pearl");

    int power;
    int input;
    while (1)
    {
        cout << endl;
        cout << "1.Display magical tree." << endl;
        cout << "2.Search a gem by its power" << endl;
        cout << "3.Find the gem with the highest magical power." << endl;
        cout << "4.Pluck (remove) a gem from the BST, and put it in your bag." << endl;
        cout << "Enter your option" << endl;
        cin >> input;
        if (input == 1)
        {
            cout << "1.pre Order " << endl;
            cout << "2.In Order " << endl;
            cout << "3.Post Order " << endl;
            int a;
            cin >> a;
            if (a == 1)
            {
                cout << "Magical Tree (Pre Order)" << endl;
                t.preOrder(t.Root);
            }
            else if (a == 2)
            {
                cout << "Magical Tree (In Order)" << endl;

                t.inOrder(t.Root);
            }
            else if (a == 3)
            {
                cout << "Magical Tree (post Order)" << endl;

                t.postOrder(t.Root);
            }
        }
        else if (input == 2)
        {
            cout << "Enter the power of which gem u want to search" << endl;
            int n;
            cin >> n;
            Node *temp = t.Search(t.Root, n);
            cout << "[  " << temp->name << "  " << temp->data << "]";
        }
        else if (input == 3)
        {
            Node *temp = t.findmax(t.Root);
            cout << "Max power gem is [" << temp->name << "  " << temp->data << "]";
        }
        else if (input == 4)
        {
            cout << "Magical Tree--(In Order)" << endl;

            t.inOrder(t.Root);

            cout << "gems you want to pluck : Enter Power " << endl;
            int pow;
            cin >> pow;
            Node *temp = t.Search(t.Root, pow);
            cout << "You plucked   ";
            cout << "[  " << temp->name << "  " << temp->data << "]";
            power = power + temp->data;
            t.delete_Nodes(t.Root, pow);
            if (power >= 100)
            {
                if (power == 100)
                {
                    cout << "There is a sacry monstar with dark hair and BIG TEETHS , HIS NAME IS KHIZER " << endl;
                    break;
                }
                else
                {
                    cout << "Oh shit!  run from the khizer the vicious monster who i about to catch you for stealing RUNN!!!!!!!!" << endl;
                    break;
                }
            }
            else
                continue;
        }
        else
            break;
    }
}
