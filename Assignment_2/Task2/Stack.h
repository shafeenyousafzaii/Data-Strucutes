#include <iostream>
#include <cctype> //including for checking if an integer exist in the arugment or not
#include <math.h>
using namespace std;
class node
{
public:
    char data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    node *top;
    int length;

public:
    List()
    {
        top = NULL;
        length = 0;
    }
    ~List()
    {
        node *curr = NULL;
        while (top != NULL)
        {
            curr = top;
            top = top->next;
            delete curr;
        }
    }

    void push(char val)
    {
        node *n = new node(val);
        n->next = top;
        top = n;
        length++;
    }

    char pop()
    {
        if (top == NULL)
        {
            // cout << "Stack underflow" << endl;
            return -1;
        }
        node *curr = top;
        char val = curr->data;
        top = top->next;
        delete curr;
        length--;
        return val;
    }
    int peak()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    void display()
    {
        node *curr = top;
        while (curr != NULL)
        {
            cout << curr->data << "";
            curr = curr->next;
        }
        cout << endl;
    }

    bool checking_brackets(string brackets)
    {
        int count = -1;
        // cout<<brackets.length()<<endl;

        for (int i = 0; i < brackets.length(); i++)
        {
            char a;
            a = brackets[i];
            // cout<<a<<endl;
            if (a == '{')
            {
                // cout <<"Pushing : "<< a << endl;
                push(a);
                count++;
            }
            else if (a == '[')
            {
                // char a;
                // a = a + brackets[i];
                push(a);
                // cout <<"Pushing : "<< a << endl;
                count++;
            }
            else if (a == '<')
            {
                // char a;
                // cout <<"Pushing : "<< a << endl;
                // a = a + brackets[i];
                push(a);
                count++;
            }
            else if (a == '(')
            {
                // char a;
                // cout <<"Pushing : "<< a << endl;
                // a = a + brackets[i];
                push(brackets[i]);
                count++;
            }
        }
        bool ans = false;
        // cout<<count;
        cout<<endl;
        for (int i = count+1 ; i < brackets.length(); i++)
        {
            char char2=pop();
            // cout<<"Popping : "<<char2<<endl;
            if ((char2 == '(' && brackets[i] == ')'))
            {
                // cout<<"Bracket[i] ="<<brackets[i]<<endl;
                ans = true;
            }
            else if ((char2 == '{' && brackets[i] == '}'))
            {
                ans = true;
                // cout<<"Bracket[i] ="<<brackets[i]<<endl;
            }
            else if ((char2 == '[' && brackets[i] == ']'))
            {
                ans = true;
                // cout<<"Bracket[i] ="<<brackets[i]<<endl;
            }
            else if ((char2 == '<' && brackets[i] == '>'))
            {
                ans = true;
                // cout<<"Bracket[i] ="<<brackets[i]<<endl;
            }
            else
            {
                ans = false;
            }
            if(ans==false)
            {
                break;
                ans=false;
                return false;
            }
        }
        return ans;
    }
};
