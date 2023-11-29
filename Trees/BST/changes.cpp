#include <iostream>
#include <string>
#include "Changes.h" using namespace std;
int main()
{
    BST T;
    T.set_root(T.insert(T.Root, 50));
    T.insert(T.Root, 60);
    T.insert(T.Root, 30);
    T.insert(T.Root, 40);
    T.insert(T.Root, 10);
    T.insert(T.Root, 70);
    T.insert(T.Root, 55);
    T.insert(T.Root, 53);
    T.insert(T.Root, 56);
    T.insert(T.Root, 9);
    T.insert(T.Root, 11);
    T.insert(T.Root, 28);
    T.insert(T.Root, 27);
    cout << endl;
    T.inOrder(T.Root);
    cout << endl;
    // Deleting a leaf node
    cout << "Before Deleting one leaf node 70" << endl;
    T.printBST(T.Root, NULL, false);
    T.delete_Nodes(T.Root, 70);
    cout << "After Deletion one leaf node 70" << endl;
    T.printBST(T.Root, NULL, false);
    // Deleting a parent with one child
    cout << "Before Deletion of parent 28 with one child" << endl;
    T.printBST(T.Root, NULL, false);
    T.delete_Nodes(T.Root, 28);
    cout << "After Deletion of parent 28 with one child" << endl;
    T.printBST(T.Root, NULL, false);

    // Deleting a parent with multiple childs
    cout << "Before Deletion of parent with two children 55" << endl;
    T.printBST(T.Root, NULL, false);
    T.delete_Nodes(T.Root, 55);
    cout << "After Deletion of parent with two children 55" << endl;
    T.printBST(T.Root, NULL, false);
    //Deleting the Root node of the Tree
    cout << "Before Deletion of ROOT node" << endl;
    T.printBST(T.Root, NULL, false);
    T.delete_Nodes(T.Root, 50);
    cout << "After Deletion of Root node" << endl;
    T.printBST(T.Root, NULL, false);
    //Deleting all the left side nodes of the tree
    cout << "Before Deletion of all left side nodes" << endl;
    T.printBST(T.Root, NULL, false);
    T.delete_Nodes(T.Root, 30);
    T.delete_Nodes(T.Root, 27);
    T.delete_Nodes(T.Root, 9);
    T.delete_Nodes(T.Root, 10);
    // T.delete_Nodes(T.Root, 11);
    cout << "After Deletion of all left side nodes" << endl;
    cout<<endl;
    T.printBST(T.Root, NULL, false);
    
    // cout<<endl;
    // bool a=T.search(T.Root,9);
    // Node *n=T.Search(T.Root,9);
    // cout<<"FOUND : "<<n->data<<endl;
    // cout<<"TRUE OR NOT "<<a<<endl;
    // cout<<endl;
    // T.printBST(T.Root,NULL,false);
    // T.delete_Nodess(T.Root,9);
    // cout<<endl;
    // T.printBST(T.Root,NULL,false);
    // T.delete_Nodess(T.Root,53);
    // cout<<endl;
    // T.printBST(T.Root,NULL,false);

    // T.delete_Nodess(T.Root,11);
    // cout<<endl;
    // T.printBST(T.Root,NULL,false);
    // cout<<endl;
    // cout<<endl;

    // T.delete_Nodess(T.Root,28);
    // cout<<endl;
    // T.printBST(T.Root,NULL,false);
    // BST T;
    // T.set_root(T.insert(T.Root, 35));
    // // Inserting nodes
    // // T.insert(T.Root, 35);
    //     T.insert(T.Root, 20);
    //         T.insert(T.Root, 50);
    //             T.insert(T.Root, 10);
    //                 T.insert(T.Root, 30);
    //                     T.insert(T.Root, 40);
    //                         T.insert(T.Root, 60);

    // T.delete_Nodes(T.Root, 30);
    // T.delete_Nodes(T.Root, 20);
    // T.delete_Nodes(T.Root, 35);
    // T.delete_Nodes(T.Root, 40);

    // T.insert(T.Root, 60);
    // // T.insert(T.Root, 30);
    // // T.insert(T.Root, 40);
    // // T.insert(T.Root, 10);
    // // T.insert(T.Root, 9);
    // T.insert(T.Root, 70);
    // T.insert(T.Root, 55);
    // // T.insert(T.Root, 35);
    // // T.insert(T.Root, 40);
    // // T.insert(T.Root, 11);
    // T.insert(T.Root, 71);
    // T.insert(T.Root, 65);
    // T.insert(T.Root, 54);
    // T.printBST(T.Root, NULL, 0);
    // T.delete_Nodes(T.Root,50); //Predessor In-Order deletion
    // // T.printBST(T.Root, NULL, 0);
    // T.delete_Nodes(T.Root,70); //Predessor In-Order deletion
    // // T.printBST(T.Root, NULL, 0);
    // T.delete_Nodes(T.Root,55); //Predessor In-Order deletion
    // // T.printBST(T.Root, NULL, 0);
    //     cout<<"EXECUTION"<<endl;
    // T.printBST(T.Root,NULL,0);

    // T.delete_Nodes(T.Root,70);
    // // T.printBST(T.Root,NULL,0);
    // T.delete_Nodes(T.Root,10);
    // // T.printBST(T.Root,NULL,0);
    // T.delete_Nodes(T.Root,35);
    // T.printBST(T.Root,NULL,0);
    // T.delete_Nodes(T.Root,60);
    // T.printBST(T.Root,NULL,0);

    // T.delete_Nodes(T.Root,55);
    // T.printBST(T.Root,NULL,0);

    // T.delete_Nodes(T.Root,30);
    // T.printBST(T.Root, NULL, 0);
    // T.inOrder(T.Root);
    // T.delete_Nodes(T.Root,55);
    // T.printBST(T.Root,NULL,0);

    //------------------------

    // T.delete_Nodes(T.Root, 50);
    // T.printBST(T.Root, NULL, 0);
    // T.delete_Nodes(T.Root, 60);
    // T.printBST(T.Root, NULL, 0);
    // T.delete_Nodes(T.Root, 9);
    // T.printBST(T.Root, NULL, 0);
    // T.delete_Nodes(T.Root, 55);
    // T.printBST(T.Root, NULL, 0);

    // T.delete_Nodes(T.Root, 70);
    // T.printBST(T.Root, NULL, 0);
    // T.delete_Nodes(T.Root, 60);
    // T.printBST(T.Root, NULL, 0);

    // // couT<<endl;

    // T.delete_Nodes(T.Root, 40);
    // T.printBST(T.Root, NULL, 0);

    // T.delete_Nodes(T.Root, 30);
    // T.printBST(T.Root, NULL, 0);

    // cout<<"MAX DEPTH "<< T.maxDepth(T.Root)<<endl;
    // T.delete_Nodes(T.Root, 10);
    // T.printBST(T.Root, NULL, 0);

    // T.delete_Nodes(T.Root, 9);
    // T.printBST(T.Root,NULL,0);
    // T.delete_Nodes(T.Root, 55);
    // cout<<"WORKING"<<endl;
    // T.printBST(T.Root,NULL,0);
    // T.delete_Nodes(T.Root, 55);
    // // T.printBST(T.Root, NULL, 0);
};