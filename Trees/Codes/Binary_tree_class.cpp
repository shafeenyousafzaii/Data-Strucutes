#include <iostream>
#include <string>
#include "Binary_tree_classs.h"
using namespace std;
int main()
{
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
    Tree t;
    t.insert_root(5);
    t.insert_node_left(t.Root, 2);
    t.insert_node_right(t.Root, 7);
    t.insert_node_left(t.Root->right, 3);
    t.insert_node_right(t.Root->right, 9);
    t.insert_node_left(t.Root->left, 6);
    t.insert_node_right(t.Root->left->left, 1);
    t.printTree(t.Root, NULL, false);
    // Find Parent
    Node *n = t.parent(t.Root, t.Root->right, t.Root);
    cout << "Parent is: " << n->data << endl;
    // Find sibling
    Node *sib = t.sibling(t.Root, t.Root->right->left); // sibling of 3 (which is 9)
    cout << "Sibling of 3 is: " << sib->data << endl;
    // Level of a node
    cout << "Level of 1: " << t.getLevel(t.Root, t.Root->left->left->right, 0) << endl;
    // Depth of the tree
    cout << "Depth of the tree: " << t.maxDepth(t.Root) << endl;
    t.deleteTree(t.Root);
    t.Root = NULL;
    // Find Duplicates [Start]
    Node *r = NULL;
    int arr[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};
    int sz = sizeof(arr)/sizeof(int);
    for (int i = 0; i < sz; i++)
        t.checkDuplicates(&r, arr[i]);
    
    t.deleteTree(r);
    t.Root = NULL;
    // Find Duplicates [End]

    // Tree Traversals (PreOrder, InOrder, PostOrder) [Start]
    Node *order = NULL;
    order = new Node(1);
    order->left = new Node(2);
    order->right = new Node(3);
    order->left->left = new Node(4);
     //printTree(root, NULL, false);
    t.preOrder(order);
    cout<<endl;
    t.inOrder(order);
    cout<<endl;
    t.postOrder(order);
    // Tree Traversals (PreOrder, InOrder, PostOrder) [End]
    return 0;
}