#include<iostream>
#include<string>
#include"Tree.h"
using namespace std;
int main()
{
    Tree t;
    t.insert_root(5);
    t.insert_node_left(t.Root,6);
    t.insert_node_right(t.Root,7);
    t.insert_node_left(t.Root->left,1);
    t.insert_node_right(t.Root->left,2);
    // t.insert_node_left(t.Root->left->left,1);
    // t.insert_node_right(t.Root->right->left,3);
    t.insert_node_left(t.Root->right,3);
    t.insert_node_right(t.Root->right,4);
    t.display_pre_order(t.Root);
    
}