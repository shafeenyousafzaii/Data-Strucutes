#include <iostream>
#include <string>
using namespace std;

class Trunk
{
public:
    Trunk *prev;
    string str;
    Trunk(Trunk *prevv, string strr)
    {
        prev = prevv;
        str = strr;
    };
    // ~Trunk();
};

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
        Node *n = new Node(val);
        Root = n;
        Root->data = val;
    }
    void insert_node_left(Node *cur, int val)
    {
        if (Root == NULL)
        {
            return;
        }
        Node *n = new Node(val);
        cur->left = n;
        return;
    }
    void insert_node_right(Node *cur, int val)
    {
        if (Root == NULL)
        {
            return;
        }
        Node *n = new Node(val);
        cur->right = n;
        return;
    }
    void display_pre_order(Node *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        cout << "\t" << curr->data << endl;
        display_pre_order(curr->left);
        display_pre_order(curr->right);
    }
    void display_in_order(Node *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        display_pre_order(curr->left);
        cout << "\t" << curr->data << endl;
        display_pre_order(curr->right);
    }
    Node *parent(Node *curr, Node *p, Node *par)
    {
        if (curr == NULL)
            return NULL;

        if (curr == p)
        {
            return par;
        }
        else
        {
            Node *t = NULL;
            t = parent(curr->left, p, curr);
            if (t != NULL)
                return t;
            else
            {
                t = parent(curr->right, p, curr);
                return t;
            }
        }
    }
    Node *sibling(Node *root, Node *p)
    {
        Node *par = parent(root, p, root);

        if (par->left == p)
            return par->right;
        else
            return par->left;
    }
    void deleteTree(Node *leaf)
    {
        if (leaf != NULL)
        {
            deleteTree(leaf->left);
            deleteTree(leaf->right);
            delete leaf;
        }
    }
    // int getLevel(Node *ptr, Node *n, int level)
    // {
    //     if (ptr == NULL)
    //         return 0;
    //     if (ptr == n)
    //         return level;

    //     int l = getLevel(ptr->left, n, level + 1);
    //     int r = getLevel(ptr->right, n, level + 1);

    //     if (l == 0)
    //         return r;
    //     else if (r == 0)
    //         return l;
    //     else
    //         return 0;
    //     // return l | r;
    //     // return getLevel(ptr->left, val, level+1) |
    //     // getLevel(ptr->right, val, level+1);
    // }
    void checkDuplicates(Node **n, int val)
    {
        if (*n == NULL)
        {
            *n = new Node(val);
            return;
        }

        if (val > (*n)->data)
        {
            if ((*n)->right != NULL)
                checkDuplicates(&(*n)->right, val);
            else
            {
                (*n)->right = new Node(val);
                return;
            }
        }
        else if (val < (*n)->data)
        {
            if ((*n)->left != NULL)
                checkDuplicates(&(*n)->left, val);
            else
            {
                (*n)->left = new Node(val);
                return;
            }
        }
        else if (val == (*n)->data)
            cout << val << " is repeated..." << endl;
    }
    int getLevel(Node *ptr, Node *n, int level)
    {
        if (ptr == NULL)
            return 0;
        if (ptr == n)
            return level;

        int l = getLevel(ptr->left, n, level + 1);
        int r = getLevel(ptr->right, n, level + 1);

        if (l == 0)
            return r;
        else if (r == 0)
            return l;
        else
            return 0;
        // return l | r;
        // return getLevel(ptr->left, val, level+1) |
        // getLevel(ptr->right, val, level+1);
    }
    int maxDepth(Node *n)
    {
        if (n == NULL)
            return -1;
        else
        {
            /* compute the depth of each subtree */
            int lDepth = maxDepth(n->left);
            int rDepth = maxDepth(n->right);

            /* use the larger one */
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }
    void preOrder(Node *n)
    {
        if (n == NULL)
            return;

        cout << n->data << "\t";
        preOrder(n->left);
        preOrder(n->right);
    }

    void inOrder(Node *n)
    {
        if (n == NULL)
            return;

        inOrder(n->left);
        cout << n->data << "\t";
        inOrder(n->right);
    }

    void postOrder(Node *n)
    {
        if (n == NULL)
            return;

        postOrder(n->left);
        postOrder(n->right);
        cout << n->data << "\t";
    }
    void showTrunks(Trunk *p)
    {
        if (p == NULL)
            return;

        showTrunks(p->prev);

        cout << p->str;
    }

    void printTree(Node *root, Trunk *prev, bool isRight)
    {
        if (root == NULL)
            return;

        string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);

        printTree(root->right, trunk, true);

        if (!prev)
            trunk->str = "---";
        else if (isRight)
        {
            trunk->str = ".---";
            prev_str = "   |";
        }
        else
        {
            trunk->str = "`---";
            prev->str = prev_str;
        }

        showTrunks(trunk);
        cout << root->data << endl;

        if (prev)
            prev->str = prev_str;
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }
    // bool function_to_check_BT_nodes(Node *curr)
    // {
    //     if (function_implementation(curr) == 1)
    //     {
    //         return true;
    //     }
    //     else
    //         return false;
    // }
    // int function_implementation(Node *curr)
    // {
    //     // if(curr==NULL)
    //     //     return 1;
    //     // if(curr->left!=NULL)
    //     //      function_implementation(curr->left);
    //     if (curr == NULL)
    //         return 0;
    //     if(curr->left!=NULL && curr->right==NULL)
    //         return 1 && function_implementation(curr->left);
    //     if(curr->left==NULL && curr->right== NULL)
    //         return 0;
    //     if(curr->right!=NULL && curr->left==NULL)
    //         function_implementation(curr->right);
    //     if(curr->left!=NULL && curr->right!=NULL)
    //         return 0;
    //     // cout << curr->data << "\t";
    // }
    bool SingleChild(Node *R)
    {
        if (R == NULL || (R->left == NULL && R->right == NULL))
        {
            return true;
        }
        if (R->left != NULL && R->right != NULL)
        {
            return false;
        }
        if (R->left != NULL)
        {
            return SingleChild(R->left);
        }
        return SingleChild(R->right);
    }
    int countNodesSumOfChild(Node *n)
    {

        if (n == NULL)
        {
            return 0;
        }
        if (n->left == NULL && n->right == NULL)
        {
            return 0;
        }
        int count = 0;
        int leftVal = 0;
        int rightVal = 0;
        if (n->left != NULL)
        {
            leftVal = n->left->data;
        }
        if (n->right != NULL)
        {
            rightVal = n->right->data;
        }

        if (n->data == leftVal + rightVal)
        {
            count = 1;
        }
        return count + countNodesSumOfChild(n->left) + countNodesSumOfChild(n->right);
    }
};

//-------------------------
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
    t.insert_node_right(t.Root, 3);
    t.insert_node_left(t.Root->right, 2);
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
    int sz = sizeof(arr) / sizeof(int);
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
    // printTree(root, NULL, false);
    t.preOrder(order);
    cout << endl;
    t.inOrder(order);
    cout << endl;
    t.postOrder(order);
    // Tree Traversals (PreOrder, InOrder, PostOrder) [End]
    bool yes = t.SingleChild(t.Root);
    cout<<endl;
    if (yes == true)
        cout << "Single Child" << endl;
    else
        cout << "No single child" << endl;
    // yes=t.countNodesSumOfChild(t.Root);
    // if(yes==true)
    //     cout<<"Single Child"<<endl;
    // else
    //     cout<<"No single child"<<endl;
    return 0;
}