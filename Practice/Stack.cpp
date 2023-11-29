#include <iostream>
using namespace std;
class node
{
    public:
        int data;
        node *next;

        node(int val)
        {
            data = val;
            next = NULL;
        }
};

class List
{
    node* top;
    int length;
    public:
      List()
      {
          top = NULL;
          length = 0;
      }
      ~List()
      {
         node* curr = NULL;
         while(top != NULL)
         {  curr = top;
             top = top->next;
             delete curr;
            
         }
      }

        void push(int val)
        {
            node*  n = new node(val);
            n->next = top;
            top = n;
            length++;
        }

        int pop()
        {
            if(top == NULL)
            {
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            node* curr = top;
            int val = curr->data;
            top = top->next;
            delete curr;
            length--;
            return val;
        }
        int peak()
        {
            if(top == NULL)
            {
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            return top->data;
        }

        void display()
        {
            node* curr = top;
            while(curr != NULL)
            {
                cout<<curr->data<<" ";
                curr = curr->next;
            }
            cout<<endl;
        }

};

int main()
{
    List s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    s.display();
    cout<<s.peak()<<endl;
    return 0;
    
}