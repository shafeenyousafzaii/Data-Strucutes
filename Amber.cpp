#include <iostream>
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

class node
{
public:
    int value;
    node *right;
    node *left;
    // node* root;
    node(int val)
    {
        value = val;
        right = NULL;
        left = NULL;
        // root=NULL;
    }
};
class BST
{
public:
    node *root;
    // node *current;
    // int val2;
    BST()
    {
        root = NULL;
        // current = NULL;
    }
    node *insert(node *current, int val)
    {
       // cout << "INsert FUnction" << endl;

        if (current == NULL)
        {
            return new node(val);
        }
        if (val == current->value)
        {
            cout << "value already presend in the tree" << endl;
        }
        if (val > current->value)
        {
            current->right = insert(current->right, val);
            // return current;
        }
        if (val < current->value)
        {
            current->left = insert(current->left, val);
        }
        //cout << "current: " << current << endl;

        return current;
        // cout<<"current: "<<current<<endl;
    }

    bool search(node *current, int val)
    {
        //cout << "Search function" << endl;
        if (current == NULL)
        {
            cout << "Tree is empty" << endl;
            return false;
        }

        if (current->value == val)
        {
            cout << "value found " << endl;
            return true;
        }
        if (val > current->value)
        {
            return search(current->right, val);
        }
        else if (val < current->value)
        {
            return search(current->left, val);
        }
        return current;
    }
    // void emptyBST()
    // {
    //     if (root == NULL)
    //     {
    //         cout << "The BST is empty" << endl;
    //     }
    // }
    bool isempty(node *r)
    {
        cout << " IS EMPTY FUNCTION" << endl;
        if (r == NULL)
        {
            cout << " BST is empty Right Now" << endl;
            return true;
        }
        else
        {
            cout << "BST is  not empty Right Now" << endl;
            return false;
        }
    }

    // node *successor(node *r, int key)
    // {
    //     if (r == NULL)
    //     {
    //         return r;
    //     }
    //     node *temp = new node(key);
    //     temp = search(r, key);
    //     if (temp->right != NULL)
    //     {
    //         temp = Min(temp->right);
    //         return temp;
    //     }
    //     if (temp->right == NULL)
    //     {
    //         node *parent = new node;
    //         node *rt = new node;
    //         rt = root;
    //         parent = NULL;
    //         while (rt != temp)
    //         {
    //             if (rt->info > temp->info)
    //             {
    //                 parent = rt;
    //                 rt = rt->left;
    //             }
    //             else
    //             {
    //                 rt = rt->right;
    //             }
    //         }
    //         return parent;
    //     }
    // }
    // node *parent(node *current, node *findparent, node *parent)
    // {
    //     if (current == NULL)
    //     {
    //         cout << "There is no parent to be found" << endl;
    //         return NULL;
    //     }
    //     if (current == findparent)
    //     {
    //         return parent;
    //     }

    //     node *temp = parent(current->left, findparent, current);

    //     if (temp != NULL)
    //     {
    //         return temp;
    //     }

    //     return parent(current->right, parent, current);
    // }
    node *find_successor(node *val1)
    {
        if (val1->left == NULL)
        {
            return val1;
        }
        root = val1;
        return find_successor(val1->left);
    }

    void preOrder(node *n)
    {
        if (n == NULL)
        {
            return;
        }
        cout << n->value << "\t";
        preOrder(n->left);
        preOrder(n->right);
    }
    void inOrder(node *n)
    {
        if (n == NULL)
        {
            return;
        }
        inOrder(n->left);
        cout << n->value << "\t";
        inOrder(n->right);
    }
    void postOrder(node *n)
    {
        if (n == NULL)
        {
            return;
        }
        postOrder(n->left);
        postOrder(n->right);
        cout << n->value << "\t";
    }
    void deleteNode(int val, node *&current)
    {
        //cout << "Delete Function" << endl;
        if (current == NULL)
        {
            cout << "Tree is empty , there is nothing to delete" << endl;
            return;
        }
        if (current == NULL)
        {
            cout << "value does not exist" << endl;
            return;
        }
        if (current->value == val)
        {
            if (current->left && current->right == NULL)
            {

                delete current;
                current = NULL;
                return;

                // delete current;
                // current = NULL;
            }
            else if (current->left == NULL)
            {
                node *temp = current;
                current = current->right;
                delete temp;
                // root = NULL;
            }
            else if (current->right == NULL)
            {
                node *temp = current;
                current = current->left;
                delete temp;
                // root = NULL;
            }
            else
            {
                node *successor = find_successor(current->right);
                current->value = successor->value;
                deleteNode(successor->value, current->right);
                // current->value = val2;
            }
        }
        else if (val < current->value)
        {
            deleteNode(val, current->left);
        }
        else
        {
            deleteNode(val, current->right);
        }
    }
    void showTrunks(Trunk *p)
    {
        if (p == NULL)
            return;

        showTrunks(p->prev);

        cout << p->str;
    }
    void printTree(node *root, Trunk *prev, bool isRight)
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
        cout << root->value << endl;

        if (prev)
            prev->str = prev_str;
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }
};

int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, 50);

    //tree.insert(tree.root, 10);
    tree.insert(tree.root, 45);
    tree.insert(tree.root, 55);
    tree.insert(tree.root, 46);
    tree.insert(tree.root, 54);
    tree.insert(tree.root, 47);
    tree.insert(tree.root, 57);
    tree.insert(tree.root, 48);
    tree.insert(tree.root, 53);
    tree.insert(tree.root, 49);
    tree.insert(tree.root, 59);
    tree.insert(tree.root,35);
    tree.inOrder(tree.root);
    tree.isempty(tree.root);
    tree.search(tree.root, 3);
    cout<<"Before deletion: "<<endl;
    tree.printTree(tree.root,NULL,false);
    tree.deleteNode(50, tree.root);
    cout<<"After deletion"<<endl;
    tree.printTree(tree.root,NULL,false);
    cout<<"Before deletion: "<<endl;
    tree.printTree(tree.root,NULL,false);
    tree.deleteNode(46, tree.root);
    cout<<"After deletion"<<endl;
    tree.printTree(tree.root,NULL,false);
    tree.inOrder(tree.root);
}