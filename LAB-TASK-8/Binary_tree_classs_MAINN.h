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
    // int maxDepth(Node *n,int t)
    // {
    //     if (n == NULL)
    //         return -1;
    //     else
    //     {
    //         /* compute the depth of each subtree */
    //         int lDepth = maxDepth(n->left);
    //         int rDepth = maxDepth(n->right);

    //         /* use the larger one */
    //         if (lDepth > rDepth)
    //             return (lDepth + 1);
    //         else
    //             return (rDepth + 1);
    //     }
    // }
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
    void find_value(Node *roott, int value)
    {
        if (roott == NULL)
        {
            return;
        }
        if (roott->data == value)
        {
            cout << "Found the value" << endl;
            return;
        }
        find_value(roott->left, value);
        find_value(roott->right, value);
    }
    // Node *find_value(Node *roott, int value, int h)
    // {
    //     if (roott == NULL)
    //     {
    //         return NULL;
    //     }
    //     if (roott->data == value)
    //     {
    //         cout << "Found the value" << endl;
    //         return roott;
    //     }
    //     return find_value(roott->left, value, 1);
    //     return find_value(roott->right, value, 1);
    //     // return NULL;
    // }
    void task_insertion(Node *curr, int value, int l_r)
    {
        if (curr == NULL)
        {
            return;
        }
        if (l_r == 0)
        {
            Node *n;
            n = find(curr, value);
            cout << "value : " << n->data << endl;
            // n=find_value(curr,value)
            if (n->left == NULL)
            {
                int val;
                cout << "Enter the value you wanna insert" << endl;
                cin >> val;
                insert_node_left(n, val);
                cout << "IAOSDIAISHDJAS" << endl;
                return;
            }
            else
            {
                cout << "There exist a node" << endl;
                return;
            }
        }
        else if (l_r == 1)
        {
            Node *n;
            n = find(curr, value);
            cout << n->data;
            // n=find_value(curr,value)
            if (n->right == NULL)
            {
                int val;
                cout << "Enter the value you wanna insert" << endl;
                cin >> val;
                insert_node_right(n, val);
                return;
            }
            else
            {
                cout << "There exist a node" << endl;
                return;
            }
        }
    }
    Node *find(Node *n, int val)
    {
        if (n == NULL)
            return NULL;
        if (n->data == val)
            return n;
        else
        {
            Node *t = NULL;
            t = find(n->left, val);
            if (t != NULL)
                return t;
            else
            {
                t = find(n->right, val);
                if (t != NULL)
                    return t;
            }
        }
        return NULL;
    }
};