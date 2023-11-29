#include<iostream>
#include<string>
#include"Changes2.h"
int main()
{
    BST t;
    t.set_root(t.insert(t.Root, 18));
    // t.insert(t.Root, 60);
    // t.insert(t.Root, 30);
    // t.insert(t.Root, 40);
    // t.insert(t.Root, 10);
    // t.insert(t.Root, 70);
    // t.insert(t.Root, 55);
    t.printBST(t.Root, NULL, 0);
    int input;
    while (1)
    {
        cout<<"1.Insert in Tree"<<endl;
        cout<<"2.Delete from tree"<<endl;
        cout<<"3.Inorder Triversal"<<endl;
        cout<<"4.PreOrdeer Triversal"<<endl;
        cout<<"5.PostOrder Traversal"<<endl;
        cout<<"6.Print the tree"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>input;
        if(input==1)
        {
            int num;
            cout<<"Enter the number to be inserted:";
            cin>>num;
            if(t.Root==NULL)
            {
                t.set_root(t.insert(t.Root,num));
            }
            else
            t.insert(t.Root,num);
        }
        else if(input==2)
        {
            int num;
            cout<<"Enter the number to be deleted:";
            cin>>num;
            t.delete_Nodes(t.Root,num);
            t.printBST(t.Root,NULL,0);
        }
        else if(input==3)
        {
            t.inOrder(t.Root);
        }
        else if(input==4)
        {
            t.preOrder(t.Root);
        }
        else if(input==5)
        {
            t.postOrder(t.Root);
        }
        else if(input==6)
        {
            t.printBST(t.Root,NULL,false);
        }
        else
        break;
    }
}