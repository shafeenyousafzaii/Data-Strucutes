#include <iostream>
#include <string>

using namespace std;

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

class node
{
public:
    int info;
    node *left;
    node *right;

    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
    int length;

public:
    node *root;

    Tree()
    {
        length = 0;
        root = NULL;
    }

    ~Tree()
    {
        deleteTree(root);
    }
    void deleteTree(node *leaf)
    {
        if (leaf != NULL)
        {
            deleteTree(leaf->left);
            deleteTree(leaf->right);
            delete leaf;
        }
    }

    node *getRoot()
    {
        return root;
    }

    void insertroot(int val)
    {
        if (root == NULL)
        {
            root = new node(val);
            length++;
        }
        else
        {
            cout << "Root already exists" << endl;
        }
    }

    void insertleft(node *n, int val)
    {
        if (n == NULL)
        {
            cout << "Parent does not exist" << endl;
        }
        else
        {
            if (n->left == NULL)
            {
                n->left = new node(val);
                length++;
            }
            else
            {
                cout << "Left child already exists" << endl;
            }
        }
    }

    void insertright(node *n, int val)
    {
        if (n == NULL)
        {
            cout << "Parent does not exist" << endl;
        }
        else
        {
            if (n->right == NULL)
            {
                n->right = new node(val);
                length++;
            }
            else
            {
                cout << "Right child already exists" << endl;
            }
        }
    }

    void preOrder(node *n)
    {
        if (n == NULL)
            return;

        cout << n->info << "\t";
        preOrder(n->left);
        preOrder(n->right);
    }

    void inOrder(node *n)
    {
        if (n == NULL)
            return;

        inOrder(n->left);
        cout << n->info << "\t";
        inOrder(n->right);
    }

    void postOrder(node *n)
    {
        if (n == NULL)
            return;

        postOrder(n->left);
        postOrder(n->right);
        cout << n->info << "\t";
    }

    node *parent(node *curr, node *p, node *par)
    {
        if (curr == NULL)
            return NULL;

        if (curr == p)
        {
            return par;
        }
        else
        {
            node *t = NULL;
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

    node *sibling(node *p)
    {
        node *par = parent(root, p, root);

        if (par->left == p)
            return par->right;
        else
            return par->left;
    }

    int maxDepth(node *n)
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

    int getLevel(node *ptr, node *n, int level)
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

    node *insert(node *curr, int val)
    {
        if (curr == NULL)
        {
            return new node(val);
        }

        if (val < curr->info)
        {
            curr->left = insert(curr->left, val);
        }
        else if (val > curr->info)
        {
            curr->right = insert(curr->right, val);
        }

        return curr;
    }

    node *prev = NULL;
    void checkDuplicates(node *root)
    {
        if (root != NULL)
        {
            checkDuplicates(root->left);

            if (prev != NULL && root->info == prev->info)
            {
                cout << root->info << " is repeated..." << endl;
            }

            prev = root;

            checkDuplicates(root->right);
        }
    }
};

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
    cout << root->info << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

void checkDuplicates(node **n, int val)
{
    if (*n == NULL)
    {
        *n = new node(val);
        return;
    }

    if (val > (*n)->info)
    {
        if ((*n)->right != NULL)
            checkDuplicates(&(*n)->right, val);
        else
        {
            (*n)->right = new node(val);
            return;
        }
    }
    else if (val < (*n)->info)
    {
        if ((*n)->left != NULL)
            checkDuplicates(&(*n)->left, val);
        else
        {
            (*n)->left = new node(val);
            return;
        }
    }
    else if (val == (*n)->info)
        cout << val << " is repeated..." << endl;
}

bool checkBstTree(node *n)
{

    if (n == NULL)
        return true;
    else
    {
        if (n->left != NULL)
        {
            if (n->left->info > n->info)
                return false;
            else
                return checkBstTree(n->left);
        }
        if (n->right != NULL)
        {
            if (n->right->info < n->info)
                return false;
            else
                return checkBstTree(n->right);
        }
    }
    return true;
}
int countNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int countNodesSumOfChild(node *n)
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
        leftVal = n->left->info;
    }
    if (n->right != NULL)
    {
        rightVal = n->right->info;
    }

    if (n->info == leftVal + rightVal)
    {
        count = 1;
    }
    return count + countNodesSumOfChild(n->left) + countNodesSumOfChild(n->right);
}
bool SingleChild(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return true;
    }
    if (root->left != NULL && root->right != NULL)
    {
        return false;
    }
    if (root->left != NULL)
    {
        return SingleChild(root->left);
    }
    return SingleChild(root->right);
}

void inorderTree(Tree &t, node *n)
{
    if (n == NULL)
        return;
    inorderTree(t, n->left);
    t.root = t.insert(t.root, n->info);
    inorderTree(t, n->right);
}

int main()
{
    Tree t;
    t.insertroot(5);
    node *root = t.getRoot();
    t.insertleft(root, 2);
    t.insertright(root, 3);
    t.insertleft(root->left, 2);
    // t.insertright(root->left, 1);
    t.insertright(root->right, 8);
    t.insertleft(root->right, 1);
    //     t.insertright(root->right->right, 10);
    t.insertleft(root->left, 7);
    //  t.insertright(root->left, 10);
    t.insertright(root->left->left, 7);
    printTree(root, NULL, false);

    cout << "Preorder: " << endl;
    t.preOrder(root);
    cout << endl;

    cout << "Inorder: " << endl;
    t.inOrder(root);
    cout << endl;

    cout << "Postorder: " << endl;
    t.postOrder(root);
    cout << endl;

    cout << "Max Depth: " << t.maxDepth(root) << endl;

    cout << "Level of 7: " << t.getLevel(root, root->right, 1) << endl;

    // node* par = t.parent(root, root->right->right->right, root);
    // cout<<"Parent of 10: "<<par->info<<endl;

    // node* sib = t.sibling(root->left->right);
    // cout<<"Sibling of 3: "<<sib->info<<endl;

    // // Find Duplicates [Start]

    //   node *r = NULL;
    // int arr[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};
    // int sz = sizeof(arr)/sizeof(int);

    // for (int i = 0; i < sz; i++)
    //     checkDuplicates(&r, arr[i]);

    //     // Check if a tree is BST or not [Start]
    //     cout<<"Is BST: "<<checkBstTree(root)<<endl;

    //    cout<<"COunt Nodes"<<countNodes(root)<<endl;

    int nodeCount = countNodesSumOfChild(root);
    cout << "Number of nodes where sum of child nodes equals parent: " << nodeCount << endl;

    cout << "Single Child: " << SingleChild(root) << endl;

    Tree t2;
    inorderTree(t2, root);

    printTree(t2.getRoot(), NULL, false);

    cout << "Dublicates: " << endl;
    t.checkDuplicates(root);

    return 0;
}