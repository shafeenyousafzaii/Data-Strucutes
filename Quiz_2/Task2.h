#include <iostream>
using namespace std;
class Node
{
    public:
        char data;
        Node *next;
        Node(char val)
        {
            data = val;
            next = NULL;
        }
};

class Stack_List
{
    Node* top;
    int length;
    public:
      Stack_List()
      {
          top = NULL;
          length = 0;
      }
        void push(char val)
        {
            Node*  n = new Node(val);
            n->next = top;
            top = n;
            length++;
        }

        char pop()
        {
            if(top == NULL)
            {
                cout<<"You have not even entered the cave"<<endl;
                return 1;
            }
            Node* curr = top;
            char val = curr->data;
            top = top->next;
            delete curr;
            length--;
            return val;
        }
        void pop(int c)
        {
            while(length!=0)
            {
            if(top == NULL)
            {
                cout<<"underflow"<<endl;
                return;
            }
            Node* curr = top;
            char val = curr->data;
            top = top->next;
            delete curr;
            length--;
            cout<<"You are now at: "<<val<<endl;
            }
        }        
        void display()
        {
            Node* curr = top;
            while(curr != NULL)
            {
                cout<<curr->data<<"";
                curr = curr->next;
            }
            cout<<endl;
        }

};

