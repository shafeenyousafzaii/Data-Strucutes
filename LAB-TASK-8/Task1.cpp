#include <iostream>
#include <string>
#include "Binary_tree_classs_MAINN.h"
using namespace std;
int main()
{
    Tree t;
    int count=0;
    while (1)
    {
        cout << "1)Insert in the tree" << endl;
        cout << "2)Traverse the tree" << endl;
        cout << "3)Find Depth of a node" << endl;
        cout << "4)Find height of a node" << endl;
        cout << "5)Search a value" << endl;
        cout << "6)Delete a tree" << endl;
        int choice = 0;
        cin >> choice;
        if (choice == 1)
        {
            int ch;
            cout << "1)insert root" << endl;
            cout << "2)insert left" << endl;
            cout << "3)insert right" << endl;
            cin>>ch;
            if (ch == 1)
            {
                if (count >= 1)
                {
                    cout << "Root already exist" << endl;
                    continue;
                }
                int value;
                cout << "Enter the value you wanna insert" << endl;
                cin >> value;
                t.insert_root(value);
                count++;
            }
            else if (ch == 2)
            {
                int value;
                cout << "Enter the value of the node you wanna insert value to it" << endl;
                cin >> value;
                t.task_insertion(t.Root, value, 0);
            }
            else if (ch == 3)
            {
                int value;
                cout << "Enter the value of the node you wanna insert value to it" << endl;
                cin >> value;
                t.task_insertion(t.Root, value, 1);
                
            }
            // string ch;
            // cout<<"Do you wanna insert root? {Type:Yes || No}"<<endl;
            // cin.ignore();
            // getline(cin,ch);
            // if(ch=="Yes"||ch=="yes")
            // {
            //     cin.ignore();
            //     cout<<"Do you wanna insert at left of root or right of root"<<endl;
            //     getline(cin,ch);
            //     if(ch=="left")
            //     {

            //     }
            // }
        }
        else if (choice == 2)
        {
            t.printTree(t.Root,NULL,false);
            // cout<<"1)pre-order 2)in-order 3)post-order"<<endl;
            // t.preOrder(t.Root);
            // cout<<endl;
            // t.inOrder(t.Root);
            // cout<<endl;
            // t.postOrder(t.Root);
            // cout<<endl;
        }   
        else if (choice == 3)
        {
            int value;
            cout<<"Enter the value you are finding depth"<<endl;
            cin>>value;
            // t.find_value(value);
            value=t.maxDepth(t.Root);
            cout<<"Max depth is "<<value<<endl;
        }
        else if (choice == 4)
        {

        }
        else if (choice == 5)
        {
        }
        else if (choice == 6)
        {
        }
        else
        {
            cout << "Wrong input" << endl;
            break;
        }
    }
    //  Tree t;
    // t.insert_root(5);
    // t.insert_node_left(t.Root,6);
    // t.insert_node_right(t.Root,7);
    // t.insert_node_left(t.Root->left,1);
    // t.insert_node_right(t.Root->left,2);
    // // t.insert_node_left(t.Root->left->left,1);
    // // t.insert_node_right(t.Root->right->left,3);
    // t.insert_node_left(t.Root->right,3);
    // t.insert_node_right(t.Root->right,4);
    // t.display_pre_order(t.Root);
    // t.insert_root(5);
    // t.insert_node_left(t.Root, 2);
    // t.insert_node_right(t.Root, 7);
    // t.insert_node_left(t.Root->right, 3);
    // t.insert_node_right(t.Root->right, 9);
    // t.insert_node_left(t.Root->left, 6);
    // t.insert_node_right(t.Root->left->left, 1);
    // t.printTree(t.Root, NULL, false);
    // t.find_value(t.Root, 10);
    // Find Parent
    // Node *n = t.parent(t.Root, t.Root->right, t.Root);
    // cout << "Parent is: " << n->data << endl;
    // // Find sibling
    // Node *sib = t.sibling(t.Root, t.Root->right->left); // sibling of 3 (which is 9)
    // cout << "Sibling of 3 is: " << sib->data << endl;
    // // Level of a node
    // cout << "Level of 1: " << t.getLevel(t.Root, t.Root->left->left->right, 0) << endl;
    // // Depth of the tree
    // cout << "Depth of the tree: " << t.maxDepth(t.Root) << endl;
    // t.deleteTree(t.Root);
    // t.Root = NULL;
    // // Find Duplicates [Start]
    // Node *r = NULL;
    // int arr[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};
    // int sz = sizeof(arr) / sizeof(int);
    // for (int i = 0; i < sz; i++)
    //     t.checkDuplicates(&r, arr[i]);

    // t.deleteTree(r);
    // t.Root = NULL;
    // // Find Duplicates [End]

    // // Tree Traversals (PreOrder, InOrder, PostOrder) [Start]
    // Node *order = NULL;
    // order = new Node(1);
    // order->left = new Node(2);
    // order->right = new Node(3);
    // order->left->left = new Node(4);
    // // printTree(root, NULL, false);
    // t.preOrder(order);
    // cout << endl;
    // t.inOrder(order);
    // cout << endl;
    // t.postOrder(order);
    // // Tree Traversals (PreOrder, InOrder, PostOrder) [End]
    // // cout<<"Value "<<yes;
    // return 0;
}