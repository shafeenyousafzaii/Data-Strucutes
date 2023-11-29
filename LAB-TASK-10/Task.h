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

// Helper function to print branches of the binary tree
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
    int height;

    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
        height = 0;
    }
};
class AVL
{
public:
    node *root;
    int tree_height;
    AVL()
    {
        root = NULL;
        tree_height = 0;
    };

    int height(node *x)
    {
        if (x == NULL)
        {
            return -1;
        
        }
        return x->height;
    }

    int max(int x, int y)
    {
        
        if(x>y)
        {
            return x;
        }
        else 
        {
            return y;
        }
    }

    node *rightRotate(node *y)
    {
        node *x = y->left;
        node *two = x->right;
        x->right = y;
        y->left = two;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    node *leftRotate(node *x)
    {
        node *y = x->right;
        node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left),  height(x->right)) +1;
        y->height = max(height(y->left),  height(y->right)) +1;
        return y;
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

    int getBalance(node *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    node *insert(node *n, int key)
    {
        if (n == NULL)
            return (new node(key));

        if (key < n->info)
        {

            n->left = insert(n->left, key);
        }
        else if (key > n->info)
        {
            n->right = insert(n->right, key);
        }
        else
        {
            return n;
        }
        n->height = 1 + max(height(n->left),
                            height(n->right));
        int balance = getBalance(n);
        if (balance > 1 && key < n->left->info)
            return rightRotate(n);

        if (balance < -1 && key > n->right->info)
            return leftRotate(n);

        if (balance > 1 && key > n->left->info)
        {
            n->left = leftRotate(n->left);
            return rightRotate(n);
        }

        if (balance < -1 && key < n->right->info)
        {
            n->right = rightRotate(n->right);
            return leftRotate(n);
        }
        return n;
    }

    node *minValueNode(node *n)
    {
        node *current = n;
        while (current->left != NULL)
            current = current->left;

        return current;
    }
    int maxDepth(node *node)
    {
        if (node == NULL)
            return -1;
        else
        {
            int lDepth = maxDepth(node->left);
            int rDepth = maxDepth(node->right);
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
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

    void printTree(node *&root, Trunk *prev, bool isRight)
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
    node *deleteNode(node *root, int key)
{

    if (root == NULL)
        return root;
    if (key < root->info)
        root->left = deleteNode(root->left, key);
    else if (key > root->info)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == NULL) ||(root->right == NULL))
        {
            node *temp = root->left ? root->left : root->right;

      
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else             
                *root = *temp;
                              
            delete temp;
        }
        else
        {
     
         
            node *temp = minValueNode(root->right);

   
            root->info = temp->info;
            root->right = deleteNode(root->right,
                                     temp->info);
        }
    }

    if (root == NULL)
        return root;


    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);


    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

    bool search(node *curr, int val)
    {
        if (curr == NULL)

            return false;

        if (curr->info == val)

            return true;

        else if (val < curr->info)
            return search(curr->left, val);
        else if (val > curr->info)
            return search(curr->right, val);
    }
       node* findmax(node *curr)
    {
        node *n=curr;
        while(n->right!=NULL){
            n=n->right;}
        return n;
    }
    node*findmin(node*curr)
    {
        node *n=curr;
        while(n->left!=NULL){
            n=n->left;}
        return n;
        
    }
    
    


    // ~AVL();
};
