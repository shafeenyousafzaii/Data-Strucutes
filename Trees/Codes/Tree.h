#include <iostream>
#include <string>
using namespace std;
class Node
{

public:
    int data;
    Node *left;
    Node *right;
    Node(int l = 0)
    {
        data = l;
        left = NULL;
        right = NULL;
    };
    // Node Get_left_node()
    // {
    //     return *left;
    // }
    // Node Get_right_node()
    // {
    //     return *right;
    // }
    // int Get_data()
    // {
    //     return data;
    // }
};
class Tree
{
public:
    int length;
    Node *Root;
    Tree()
    {
        length = 0;
        Root = NULL;
    };
    void insert_root(int val)
    {
        Node*n=new Node(val);
        Root=n;
        Root->data=val;
    }
    void insert_node_left(Node *cur, int val)
    {
        if (Root == NULL)
        {
            return;
        }
        Node *n = new Node(val);
        cur->left=n;
        return;
    }
    void insert_node_right(Node *cur, int val)
    {
        if (Root == NULL)
        {
            return;
        }
        Node *n = new Node(val);
        cur->right=n;
        return;
    }
    void display_pre_order(Node *curr)
    {   if(curr==NULL)
        {
            return;
        }
        cout<<"\t"<<curr->data<<endl;
        display_pre_order(curr->left);
        display_pre_order(curr->right);
    }
    void display_in_order(Node *curr)
    {
       if(curr==NULL)
        {
            return;
        }
        display_pre_order(curr->left);
        cout<<"\t"<<curr->data<<endl;
        display_pre_order(curr->right);
    }
};
