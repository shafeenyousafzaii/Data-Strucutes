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
class BST
{
public:
    int length;
    Node *Root;
    BST()
    {
        length = 0;
        Root = NULL;
    };
    void insert_root(int val)
    {
        Node *n = new Node(val);
        Root = n;
        // Root->data = val;
    }
    void set_root(Node *c)
    {
        Root = c;
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
    void deleteBST(Node *leaf)
    {
        if (leaf != NULL)
        {
            deleteBST(leaf->left);
            deleteBST(leaf->right);
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
            /* compute the depth of each subBST */
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
    Node *inOrder(Node *n, int x)
    {

        if (n == NULL)
        {
            return NULL;
        }
        inOrder(n->left, x);

        inOrder(n->right, x);
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

    void printBST(Node *root, Trunk *prev, bool isRight)
    {
        if (root == NULL)
            return;

        string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);

        printBST(root->right, trunk, true);

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

        printBST(root->left, trunk, false);
    }
    bool search(Node *curr, int val)
    {
        if (curr == NULL)
        {
            return false;
        }
        if (curr->data == val)
        {
            return true;
        }
        else if (val < curr->data)
        {
            return search(curr->left, val);
        }
        else if (val > curr->data)
        {
            return search(curr->right, val);
        }
        return false;
    }
    Node *Search(Node *curr, int val)
    {
        if (curr == NULL)
            return NULL;
        if (curr->data == val)
        {
            return curr;
        }
        else if (val < curr->data)
        {
            return Search(curr->left, val);
        }
        else if (val > curr->data)
        {
            return Search(curr->right, val);
        }
        return NULL;
    }
    Node *insert(Node *Curr, int val)

    {
        if (Curr == NULL)
        {
            return new Node(val);
            ;
        }
        else if (val < Curr->data)
        {
            Curr->left = insert(Curr->left, val);
            return Curr;
        }
        else if (val > Curr->data)
        {
            Curr->right = insert(Curr->right, val);
            return Curr;
        }
        else
            return Curr;

        // return NULL;
    }
    Node *delete_Nodes(Node *curr, int val)
    {
        bool y = search(curr, val);
        // cout << y << endl;
        // printBST(Root,NULL,false);
        Node *location = Search(curr, val);
        if (y == 1)
        {
            // cout << "Enter " << endl;
            if (location->left == NULL && location->right == NULL)
            {
                // cout << location->data << endl;
                // if (location->left == NULL)
                // {
                //     cout << "NULL";
                // }
                // if (location->right == NULL)
                // {
                //     cout << "NULL";
                // }

                // cout << "I AM HERE" << endl;
                Node *p = parent(Root, location, NULL);
                // cout << "WORKING" << endl;
                if (p->left == location)
                {
                    // cout << "WORKING" << endl;
                    p->left = NULL;
                    delete location;
                    return NULL;
                }
                else if (p->right == location)
                {
                    p->right = NULL;
                    delete location;
                    return NULL;
                }
            }
            if ((location->left == NULL && location->right != NULL))
            {
                int level = 0;
                int depth = 0;
                depth = maxDepth(Root);
                level = getLevel(Root, location, 0);
                // cout << "DE" << depth << endl;
                // cout << "Level" << level << endl;
                int l = depth - level;
                if (l == 1)
                {
                    if (location->right != NULL)
                    {
                        Node *p = parent(Root, location, NULL);
                        if (p->left == location)
                        {
                            p->left = location->right;
                            delete location;
                        }
                        else if (p->right == location)
                        {
                            p->right = location->right;
                            delete location;
                        }
                    }
                    // else if (location->left != NULL)
                    // {
                    // Node *p = parent(Root, location, NULL);
                    // if (p->left == location)
                    // {
                    //     p->left = location->left;
                    // }
                    //     Node *p = parent(Root, location, NULL);
                    //     if (p->left == location)
                    //     {
                    //         p->left = location->right;
                    //         delete location;
                    //     }
                    //     else if(p->right==location)
                    //     {
                    //         p->right==location->right;
                    //         delete location;
                    //     }
                    // }
                }
                else if (l != 1)
                {

                    // cout << "I AM HERE" << endl;
                    Node *p = parent(Root, location, NULL);
                    //(location->right->left != NULL || location->right->right != NULL)
                    if (location->data == val && p == NULL)
                    {
                        Root = location->right;
                        delete location;
                        // cout << "HELLO" << endl;
                        return NULL;
                    }
                    // printBST(Root, NULL, false);
                    if (p->left == location)
                    {
                        p->left = location->right;
                        delete location;
                    }
                    else if (p->right == location)
                    {
                        p->right = location->right;
                        delete location;
                    }
                    // else if(p->right!=NULL && p->left==NULL)
                    // {

                    // }
                }
            }
            else if ((location->right == NULL && location->left != NULL))
            {
                int level = 0;
                int depth = 0;
                depth = maxDepth(Root);
                level = getLevel(Root, location, 0);
                // cout << depth << endl;
                // cout << level << endl;
                int l = depth - level;
                if (l == 1)
                {
                    // if (location->right != NULL)
                    // {
                    //     Node *p = parent(Root, location, NULL);
                    //     if (p->left == location)
                    //     {
                    //         p->left = location->right;
                    //         delete location;
                    //     }
                    // }
                    if (location->left != NULL)
                    {
                        Node *p = parent(Root, location, NULL);
                        if (p->left == location)
                        {
                            p->left = location->left;
                            delete location;
                        }
                        else if (p->right == location)
                        {
                            p->right = location->left;
                            delete location;
                        }
                    }
                }
                else if (l != 1)
                {
                    //(location->left->left!=NULL || location->left->right!=NULL)
                    // cout << "WORKING HERE" << endl;
                    Node *p = parent(Root, location, NULL);
                    if (location->data == val && p == NULL)
                    {
                        // cout << "HERE AS WELL";
                        Root = location->left;
                        delete location;
                        // cout << "HELLO" << endl;
                        return NULL;
                    }
                    if (location->left != NULL)
                    {

                        if (p->left == location)
                        {
                            p->left = location->left;
                            delete location;
                        }
                        else if (p->right == location)
                        {
                            p->right = location->left;
                            delete location;
                        }
                    }
                }
            }

            else if (location->left != NULL && location->right != NULL)
            {
                // cout<<"I AM HEREEEEEEEE"<<endl;
                Node *n = find_predessor(location, val);
                // cout<<"DATA : "<<n->data<<endl;
                location->data = n->data;
                // printBST(Root,NULL,false);
                return delete_Nodes(n, n->data);
            }
            // cout<<"ABOVE"<<endl;
        }
        else
        {
            cout << "No value found to delete" << endl;
            return NULL;
        }
        return NULL;
    }

    Node *find_predessor(Node *r, int val)
    {
        if (val < r->data)
        {
            if (r->left == NULL && r->right == NULL)
            {
                return r;
            }
            else if (r->left == NULL && r->right != NULL)
            {
                return r;
            }
            else if (r->left != NULL && r->right == NULL)
            {
                return r;
            }
            return find_predessor(r->left, val);
        }
        else if (val > r->data)
        {

            if (r->left == NULL && r->right == NULL)
            {
                return r;
            }
            else if (r->left == NULL && r->right != NULL)
            {
                return r;
            }
            else if (r->left != NULL && r->right == NULL)
            {
                return r;
            }
            return find_predessor(r->right, val);
        }
        else if (r->data == val)
        {
            if (r->left != NULL && r->right != NULL)
            {
                return find_predessor(r->left, val);
            }
            else if (r->left == NULL && r->right == NULL)
            {
                return find_predessor(r->left, val);
            }
            else if (r->left != NULL && r->right == NULL)
            {
                return find_predessor(r->left, val);
            }
            else if (r->left == NULL && r->right != NULL)
            {
                return find_predessor(r->right, val);
            }
            return NULL;
        }
        return NULL;
    }
    Node *find_successor(Node *r, int val)
    {
        if (val < r->data)
        {
            if (r->left == NULL && r->right == NULL)
            {
                return r;
            }
            else if (r->left == NULL && r->right != NULL)
            {
                return r;
            }
            else if (r->left != NULL && r->right == NULL)
            {
                return r;
            }
            return find_successor(r->left, val);
        }
        else if (val > r->data)
        {
            if (r->left == NULL && r->right == NULL)
            {
                return r;
            }
            else if (r->left == NULL && r->right != NULL)
            {
                return r;
            }
            else if (r->left != NULL && r->right == NULL)
            {
                return r;
            }
            return find_successor(r->right, val);
        }
        else if (r->data == val)
        {
            if (r->left != NULL && r->right != NULL)
            {
                return find_successor(r->right, val);
            }
            else if (r->left == NULL && r->right == NULL)
            {
                return find_successor(r->right, val);
            }
            else if (r->left != NULL && r->right == NULL)
            {
                return find_successor(r->left, val);
            }
            else if (r->left == NULL && r->right != NULL)
            {
                return find_successor(r->left, val);
            }
        }
    }
    bool Question2_2(Node *n,int dataaa,int k)
    {
        if (n == NULL)
            return false;

        Question2_2(n->left,dataaa,k);
          if (dataaa * n->data == k)
        {
            cout<< " DATA : "<<dataaa<<endl;
            cout<< "n->data : "<<n->data<<endl;
            return true;
        }
        // cout << n->data << "\t";
        Question2_2(n->right,dataaa,k);
    }

    bool Question2(Node *n, Node *knode, int k)
    {
        bool yes;
        if (n == NULL)
            return false;
        else
        {
            yes = Question2_2(n,knode->data,k);
            if(yes==true)
            {
                return true;
            }
            Question2(n->left, n, k);
            // cout << n->data << "\t";
            Question2(n->right, n, k);

        }
        // return false;
    }
};
